/*---------------------------------------------------------

	[Resource.cpp]
	Author : 出合翔太

	[説明]
	Resourceに必要なものを管理するクラス

----------------------------------------------------------*/
#include "Resource.h"
#include "Application.h"
#include <io.h>
#include "Manager.h"

void Resource::Begin()
{
	// バックバッファクリア
	float ClearColor[4] = { 0.0f, 0.5f, 0.0f, 1.0f };
	m_ImmediateContext->ClearRenderTargetView(m_RenderTargetView.Get(), ClearColor);
	m_ImmediateContext->ClearDepthStencilView(m_DepthStencilView.Get(), D3D11_CLEAR_DEPTH, 1.0f, 0);
}

void Resource::End()
{
	m_SwapChain->Present(1, 0);
}

void Resource::SetDepthEnable(bool Enable)
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

void Resource::SetWorldViewProjection2D()
{
	auto &app = Application::GetInstance();
	SIZE winsize = app.GetWindowSize();

	D3DXMATRIX world;
	D3DXMatrixIdentity(&world);
	D3DXMatrixTranspose(&world, &world);

	m_ImmediateContext->UpdateSubresource(m_WorldBuffer.Get(), 0, NULL, &world, 0, 0);

	D3DXMATRIX view;
	D3DXMatrixIdentity(&view);
	D3DXMatrixTranspose(&view, &view);
	m_ImmediateContext->UpdateSubresource(m_ViewBuffer.Get(), 0, NULL, &view, 0, 0);

	D3DXMATRIX projection;
	D3DXMatrixOrthoOffCenterLH(&projection, 0.0f, (float)winsize.cx, (float)winsize.cy, 0.0f, 0.0f, 1.0f);
	D3DXMatrixTranspose(&projection, &projection);
	m_ImmediateContext->UpdateSubresource(m_ProjectionBuffer.Get(), 0, NULL, &projection, 0, 0);
}

void Resource::SetWorldMatrix(D3DXMATRIX * WorldMatrix)
{
	D3DXMATRIX world;
	D3DXMatrixTranspose(&world, WorldMatrix);
	m_ImmediateContext->UpdateSubresource(m_WorldBuffer.Get(), 0, NULL, &world, 0, 0);
}

void Resource::SetViewMatrix(D3DXMATRIX * ViewMatrix)
{
	D3DXMATRIX view;
	D3DXMatrixTranspose(&view, ViewMatrix);
	m_ImmediateContext->UpdateSubresource(m_ViewBuffer.Get(), 0, NULL, &view, 0, 0);
}

void Resource::SetProjectionMatrix(D3DXMATRIX * ProjectionMatrix)
{
	D3DXMATRIX projection;
	D3DXMatrixTranspose(&projection, ProjectionMatrix);
	m_ImmediateContext->UpdateSubresource(m_ProjectionBuffer.Get(), 0, NULL, &projection, 0, 0);
}

void Resource::SetMaterial(Material Material)
{
	m_ImmediateContext->UpdateSubresource(m_MaterialBuffer.Get(), 0, NULL, &Material, 0, 0);
}

void Resource::SetLight(Light Light)
{
	m_ImmediateContext->UpdateSubresource(m_LightBuffer.Get(), 0, NULL, &Light, 0, 0);
}

void Resource::SetCameraPosition(D3DXVECTOR3 CameraPosition)
{
	m_ImmediateContext->UpdateSubresource(m_CameraBuffer.Get(), 0, NULL, &D3DXVECTOR4(CameraPosition.x, CameraPosition.y, CameraPosition.z, 1.0f), 0, 0);
}

void Resource::SetParameter(D3DXVECTOR4 Parameter)
{
	m_ImmediateContext->UpdateSubresource(m_ParameterBuffer.Get(), 0, NULL, &Parameter, 0, 0);
}

void Resource::CreateVertexShader(ID3D11VertexShader ** VertexShader, ID3D11InputLayout ** InputLayout, const char * FileName)
{
	FILE* file;
	long int fsize;

	file = fopen(FileName, "rb");
	fsize = _filelength(_fileno(file));
	unsigned char* buffer = new unsigned char[fsize];
	fread(buffer, fsize, 1, file);
	fclose(file);
	
	m_Device->CreateVertexShader(buffer, fsize, NULL, VertexShader);
	
	// 入力レイアウト生成
	D3D11_INPUT_ELEMENT_DESC layout[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "NORMAL",   0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 4 * 3, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 4 * 6, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 4 * 10, D3D11_INPUT_PER_VERTEX_DATA, 0 }
	};
	UINT numElements = ARRAYSIZE(layout);
	m_Device->CreateInputLayout(layout, numElements, buffer, fsize, InputLayout);
	delete[] buffer;
}

void Resource::CreatePixelShader(ID3D11PixelShader ** PixelShader, const char * FileName)
{
	FILE* file;
	long int fsize;

	file = fopen(FileName, "rb");
	fsize = _filelength(_fileno(file));
	unsigned char* buffer = new unsigned char[fsize];
	fread(buffer, fsize, 1, file);
	fclose(file);

	m_Device->CreatePixelShader(buffer, fsize, NULL, PixelShader);

	delete[] buffer;
}

Resource::Resource()
{
	HRESULT hr = S_OK;
	auto &app = Application::GetInstance();
	SIZE winsize = app.GetWindowSize();
	D3D_FEATURE_LEVEL featurelevel = D3D_FEATURE_LEVEL_11_0;

	// デバイス、スワップチェーン、コンテキスト生成
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.BufferCount = 1;
	sd.BufferDesc.Width = winsize.cx;
	sd.BufferDesc.Height = winsize.cy;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = app.Gethwnd();
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = TRUE;
	hr = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, 0, NULL, 0, D3D11_SDK_VERSION, &sd, m_SwapChain.ReleaseAndGetAddressOf(),
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
	vp.Width = (FLOAT)winsize.cx;
	vp.Height = (FLOAT)winsize.cy;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	m_ImmediateContext->RSSetViewports(1, &vp);

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
	D3D11_BLEND_DESC blendDesc;
	ZeroMemory(&blendDesc, sizeof(blendDesc));
	blendDesc.AlphaToCoverageEnable = FALSE;
	blendDesc.IndependentBlendEnable = FALSE;
	blendDesc.RenderTarget[0].BlendEnable = TRUE;
	blendDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
	blendDesc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
	blendDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
	blendDesc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
	blendDesc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
	blendDesc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
	blendDesc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;

	float blendFactor[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
	ID3D11BlendState* blendState = NULL;
	m_Device->CreateBlendState(&blendDesc, &blendState);
	m_ImmediateContext->OMSetBlendState(blendState, blendFactor, 0xffffffff);

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

	// 定数バッファ生成
	D3D11_BUFFER_DESC hBufferDesc;
	hBufferDesc.ByteWidth = sizeof(D3DXMATRIX);
	hBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	hBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	hBufferDesc.CPUAccessFlags = 0;
	hBufferDesc.MiscFlags = 0;
	hBufferDesc.StructureByteStride = sizeof(float);

	m_Device->CreateBuffer(&hBufferDesc, NULL, m_WorldBuffer.GetAddressOf());
	m_ImmediateContext->VSSetConstantBuffers(0, 1, m_WorldBuffer.GetAddressOf());

	m_Device->CreateBuffer(&hBufferDesc, NULL, m_ViewBuffer.GetAddressOf());
	m_ImmediateContext->VSSetConstantBuffers(1, 1, m_ViewBuffer.GetAddressOf());

	m_Device->CreateBuffer(&hBufferDesc, NULL, m_ProjectionBuffer.GetAddressOf());
	m_ImmediateContext->VSSetConstantBuffers(2, 1, m_ProjectionBuffer.GetAddressOf());

	hBufferDesc.ByteWidth = sizeof(Material);
	m_Device->CreateBuffer(&hBufferDesc, NULL, m_MaterialBuffer.GetAddressOf());
	m_ImmediateContext->VSSetConstantBuffers(3, 1, m_MaterialBuffer.GetAddressOf());

	hBufferDesc.ByteWidth = sizeof(Light);
	m_Device->CreateBuffer(&hBufferDesc, NULL, m_LightBuffer.GetAddressOf());
	m_ImmediateContext->VSSetConstantBuffers(4, 1, m_LightBuffer.GetAddressOf());
	m_ImmediateContext->PSSetConstantBuffers(4, 1, m_LightBuffer.GetAddressOf());

	hBufferDesc.ByteWidth = sizeof(D3DXVECTOR4);
	m_Device->CreateBuffer(&hBufferDesc, NULL, m_CameraBuffer.GetAddressOf());
	m_ImmediateContext->PSSetConstantBuffers(5, 1, m_CameraBuffer.GetAddressOf());

	hBufferDesc.ByteWidth = sizeof(D3DXVECTOR4);
	m_Device->CreateBuffer(&hBufferDesc, NULL, m_ParameterBuffer.GetAddressOf());
	m_ImmediateContext->PSSetConstantBuffers(6, 1, m_ParameterBuffer.GetAddressOf());


	// ライト無効化
	Light light;
	light.Enable = false;
	SetLight(light);

	// マテリアル初期化
	Material material;
	ZeroMemory(&material, sizeof(material));
	material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	material.Ambient = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	SetMaterial(material);
}
