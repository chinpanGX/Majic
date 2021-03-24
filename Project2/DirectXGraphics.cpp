/*-------------------------------------------------------------

	[DirectXGraphics.cpp]
	Author : 出合翔太

	DirectX関連の処理

--------------------------------------------------------------*/
#include "Application.h"
#include "Utility.h"
#include "ConstantBuffer.h"
#include "DirectXGraphics.h"
#include <vector>

namespace
{
	const float win_x = Application::GetInstance().GetWindowSize().cx;
	const float win_y = Application::GetInstance().GetWindowSize().cy;
}

DirectXGraphics::DirectXGraphics() : m_ConstantBuffer(nullptr), m_Device(nullptr),  m_ImmediateContext(nullptr), m_SwapChain(nullptr),
									 m_RenderTargetView(nullptr), m_DepthStencilView(nullptr), m_DepthStateEnable(nullptr), m_DepthStateDisable(nullptr)
{
	// 初期化
	InitDevice();
	InitState();
	// ライト無効化
	Resource::Light light;
	light.Enable = false;
	SetLight(light);

	// マテリアル初期化
	Resource::Material material;
	ZeroMemory(&material, sizeof(material));
	material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	material.Ambient = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	SetMaterial(material);
}

DirectXGraphics::~DirectXGraphics() 
{
}

void DirectXGraphics::Begin()
{
	// バックバッファクリア
	float ClearColor[4] = { 0.0f, 0.5f, 0.0f, 1.0f };
	m_ImmediateContext->ClearRenderTargetView(m_RenderTargetView.Get(), ClearColor);
	m_ImmediateContext->ClearDepthStencilView(m_DepthStencilView.Get(), D3D11_CLEAR_DEPTH, 1.0f, 0);
}

void DirectXGraphics::End()
{
	m_SwapChain->Present(1, 0);
}

void DirectXGraphics::SetDepthEnable(bool Enable)
{
	if (Enable)
	{
		m_ImmediateContext->OMSetDepthStencilState(m_DepthStateEnable.Get(), NULL);
	}
	else
	{
		m_ImmediateContext->OMSetDepthStencilState(m_DepthStateDisable.Get(), NULL);
	}
}

void DirectXGraphics::SetWorldViewProjection2D()
{
	D3DXMATRIX world;
	D3DXMatrixIdentity(&world);
	D3DXMatrixTranspose(&world, &world);
	UpdateCBuffer(m_ImmediateContext.Get(), m_ConstantBuffer->Get(ConstantBuffer::EBuffer::CONSTANT_BUFFER_WORLD), &world);

	D3DXMATRIX view;
	D3DXMatrixIdentity(&view);
	D3DXMatrixTranspose(&view, &view);
	UpdateCBuffer(m_ImmediateContext.Get(), m_ConstantBuffer->Get(ConstantBuffer::EBuffer::CONSTANT_BUFFER_VIEW), &view);

	D3DXMATRIX projection;
	D3DXMatrixOrthoOffCenterLH(&projection, 0.0f, win_x, win_y, 0.0f, 0.0f, 1.0f);
	D3DXMatrixTranspose(&projection, &projection);
	UpdateCBuffer(m_ImmediateContext.Get(), m_ConstantBuffer->Get(ConstantBuffer::EBuffer::CONSTANT_BUFFER_PROJECTION), &projection);
}

void DirectXGraphics::SetWorldMatrix(D3DXMATRIX * WorldMatrix)
{
	D3DXMATRIX world;
	D3DXMatrixTranspose(&world, WorldMatrix);
	UpdateCBuffer(m_ImmediateContext.Get(), m_ConstantBuffer->Get(ConstantBuffer::EBuffer::CONSTANT_BUFFER_WORLD), &world);
}

void DirectXGraphics::SetViewMatrix(D3DXMATRIX * ViewMatrix)
{
	D3DXMATRIX view;
	D3DXMatrixTranspose(&view, ViewMatrix);
	UpdateCBuffer(m_ImmediateContext.Get(), m_ConstantBuffer->Get(ConstantBuffer::EBuffer::CONSTANT_BUFFER_VIEW), &view);
}

void DirectXGraphics::SetProjectionMatrix(D3DXMATRIX * ProjectionMatrix)
{
	D3DXMATRIX projection;
	D3DXMatrixTranspose(&projection, ProjectionMatrix);
	UpdateCBuffer(m_ImmediateContext.Get(), m_ConstantBuffer->Get(ConstantBuffer::EBuffer::CONSTANT_BUFFER_PROJECTION), &projection);
}

void DirectXGraphics::SetMaterial(Resource::Material Material)
{
	UpdateCBuffer(m_ImmediateContext.Get(), m_ConstantBuffer->Get(ConstantBuffer::EBuffer::CONSTANT_BUFFER_MATERIAL), &Material);
}

void DirectXGraphics::SetLight(Resource::Light Light)
{
	UpdateCBuffer(m_ImmediateContext.Get(), m_ConstantBuffer->Get(ConstantBuffer::EBuffer::CONSTANT_BUFFER_LIGHT), &Light);
}

void DirectXGraphics::SetCameraPosition(D3DXVECTOR3 CameraPosition)
{
	UpdateCBuffer(m_ImmediateContext.Get(), m_ConstantBuffer->Get(ConstantBuffer::EBuffer::CONSTANT_BUFFER_CAMERA), D3DXVECTOR4(CameraPosition.x, CameraPosition.y, CameraPosition.z, 1.0f));
}

void DirectXGraphics::SetParameter(D3DXVECTOR4 Parameter)
{
	UpdateCBuffer(m_ImmediateContext.Get(), m_ConstantBuffer->Get(ConstantBuffer::EBuffer::CONSTANT_BUFFER_PARAMETER), &Parameter);
}

void DirectXGraphics::SetBlendState(BlendMode::EMode Mode)
{
	float factor[4] = { 0.0f, 0.0f, 0.0f, 0.0f, };
	m_ImmediateContext->OMSetBlendState(m_BlendMode[Mode]->Get(), factor, 0xffffffff);
}

ID3D11Device * DirectXGraphics::GetDevice() const
{
	return m_Device.Get();
}

ID3D11DeviceContext * DirectXGraphics::GetDeviceContext() const
{
	return m_ImmediateContext.Get();
}

void DirectXGraphics::InitDevice()
{
	auto &app = Application::GetInstance();
	D3D_FEATURE_LEVEL featurelevel = D3D_FEATURE_LEVEL_11_0;

	// デバイス、スワップチェーン、コンテキスト生成
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.BufferCount = 1;
	sd.BufferDesc.Width = win_x;
	sd.BufferDesc.Height = win_y;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = app.Gethwnd();
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = TRUE;
	auto hr = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, 0, NULL, 0, D3D11_SDK_VERSION, &sd, m_SwapChain.ReleaseAndGetAddressOf(),
		m_Device.ReleaseAndGetAddressOf(), &featurelevel, m_ImmediateContext.ReleaseAndGetAddressOf());
	ThrowIfFailed(hr, "D3D11CreateDeviceAndSwapchain");

	// レンダーターゲットビュー生成、設定
	ID3D11Texture2D* pBackBuffer = NULL;
	m_SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
	m_Device->CreateRenderTargetView(pBackBuffer, NULL, &m_RenderTargetView);
	pBackBuffer->Release();

	//深度ステンシル用テクスチャー作成
	ID3D11Texture2D* depthTexture = NULL;
	D3D11_TEXTURE2D_DESC td;
	ZeroMemory(&td, sizeof(td));
	td.Width = sd.BufferDesc.Width;
	td.Height = sd.BufferDesc.Height;
	td.MipLevels = 1;
	td.ArraySize = 1;
	td.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	td.SampleDesc = sd.SampleDesc;
	td.Usage = D3D11_USAGE_DEFAULT;
	td.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	td.CPUAccessFlags = 0;
	td.MiscFlags = 0;
	m_Device->CreateTexture2D(&td, NULL, &depthTexture);

	//深度ステンシルターゲット作成
	D3D11_DEPTH_STENCIL_VIEW_DESC dsvd;
	ZeroMemory(&dsvd, sizeof(dsvd));
	dsvd.Format = td.Format;
	dsvd.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
	dsvd.Flags = 0;
	m_Device->CreateDepthStencilView(depthTexture, &dsvd, m_DepthStencilView.GetAddressOf());
	m_ImmediateContext->OMSetRenderTargets(1, m_RenderTargetView.GetAddressOf(), *m_DepthStencilView.GetAddressOf());

	// ビューポート設定
	D3D11_VIEWPORT vp;
	vp.Width = (FLOAT)win_x;
	vp.Height = (FLOAT)win_y;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	m_ImmediateContext->RSSetViewports(1, &vp);
}

void DirectXGraphics::InitState()
{
	// ラスタライザステート設定
	D3D11_RASTERIZER_DESC rd;
	ZeroMemory(&rd, sizeof(rd));
	rd.FillMode = D3D11_FILL_SOLID;
	rd.CullMode = D3D11_CULL_BACK;
	rd.DepthClipEnable = TRUE;
	rd.MultisampleEnable = FALSE;

	ID3D11RasterizerState *rs;
	m_Device->CreateRasterizerState(&rd, &rs);
	m_ImmediateContext->RSSetState(rs);

	// ブレンドステート設定	
	const std::vector<BlendMode::EMode> m_BlendList
	{
		BlendMode::EMode::BLEND_MODE_NONE,
		BlendMode::EMode::BLEND_MODE_NORMAL,
		BlendMode::EMode::BLEND_MODE_ADDITION,
		BlendMode::EMode::BLEND_MODE_ADDITIONALPHA,
		BlendMode::EMode::BLEND_MODE_SUBTRACTION,
		BlendMode::EMode::BLEND_MODE_SCREEN
	};
	for (size_t i = 0; i < m_BlendList.size(); i++)
	{
		m_BlendMode[i] = std::make_unique<BlendMode>(m_Device.Get(), m_BlendList[i]);
	}
	SetBlendState(BlendMode::BLEND_MODE_NONE);

	// 深度ステンシルステート設定
	D3D11_DEPTH_STENCIL_DESC depthStencilDesc;
	ZeroMemory(&depthStencilDesc, sizeof(depthStencilDesc));
	depthStencilDesc.DepthEnable = TRUE;
	depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
	depthStencilDesc.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
	depthStencilDesc.StencilEnable = FALSE;
	m_Device->CreateDepthStencilState(&depthStencilDesc, &m_DepthStateEnable);//深度有効ステート
	depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
	m_Device->CreateDepthStencilState(&depthStencilDesc, &m_DepthStateDisable);//深度無効ステート
	m_ImmediateContext->OMSetDepthStencilState(m_DepthStateEnable.Get(), NULL);

	// サンプラーステート設定
	D3D11_SAMPLER_DESC samplerDesc;
	ZeroMemory(&samplerDesc, sizeof(samplerDesc));
	samplerDesc.Filter = D3D11_FILTER_ANISOTROPIC;
	samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.MipLODBias = 0;
	samplerDesc.MaxAnisotropy = 16;
	samplerDesc.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
	samplerDesc.MinLOD = 0;
	samplerDesc.MaxLOD = D3D11_FLOAT32_MAX;

	ID3D11SamplerState* samplerState = NULL;
	m_Device->CreateSamplerState(&samplerDesc, &samplerState);
	m_ImmediateContext->PSSetSamplers(0, 1, &samplerState);

	// コンスタントバッファ設定
	m_ConstantBuffer = std::make_unique<ConstantBuffer>(m_Device.Get(), m_ImmediateContext.Get());
}
