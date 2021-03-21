/*-------------------------------------------------------------

	[DirectXGraphics.cpp]
	Author : �o���đ�

	DirectX�֘A�̏���

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
	HRESULT hr = S_OK;
	auto &app = Application::GetInstance();
	SIZE winsize = app.GetWindowSize();
	D3D_FEATURE_LEVEL featurelevel = D3D_FEATURE_LEVEL_11_0;

	// �f�o�C�X�A�X���b�v�`�F�[���A�R���e�L�X�g����
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

	// �����_�[�^�[�Q�b�g�r���[�����A�ݒ�
	ID3D11Texture2D* pBackBuffer = NULL;
	m_SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
	m_Device->CreateRenderTargetView(pBackBuffer, NULL, &m_RenderTargetView);
	pBackBuffer->Release();

	//�[�x�X�e���V���p�e�N�X�`���[�쐬
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

	//�[�x�X�e���V���^�[�Q�b�g�쐬
	D3D11_DEPTH_STENCIL_VIEW_DESC dsvd;
	ZeroMemory(&dsvd, sizeof(dsvd));
	dsvd.Format = td.Format;
	dsvd.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
	dsvd.Flags = 0;
	m_Device->CreateDepthStencilView(depthTexture, &dsvd, m_DepthStencilView.GetAddressOf());
	m_ImmediateContext->OMSetRenderTargets(1, m_RenderTargetView.GetAddressOf(), *m_DepthStencilView.GetAddressOf());

	// �r���[�|�[�g�ݒ�
	D3D11_VIEWPORT vp;
	vp.Width = (FLOAT)winsize.cx;
	vp.Height = (FLOAT)winsize.cy;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	m_ImmediateContext->RSSetViewports(1, &vp);

	// ���X�^���C�U�X�e�[�g�ݒ�
	D3D11_RASTERIZER_DESC rd;
	ZeroMemory(&rd, sizeof(rd));
	rd.FillMode = D3D11_FILL_SOLID;
	rd.CullMode = D3D11_CULL_BACK;
	rd.DepthClipEnable = TRUE;
	rd.MultisampleEnable = FALSE;

	ID3D11RasterizerState *rs;
	m_Device->CreateRasterizerState(&rd, &rs);
	m_ImmediateContext->RSSetState(rs);

	// �u�����h�X�e�[�g�ݒ�	
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
		m_BlendMode[i].reset(new BlendMode(m_Device.Get(),m_BlendList[i]));
	}
	SetBlendState(BlendMode::BLEND_MODE_NONE);

	// �[�x�X�e���V���X�e�[�g�ݒ�
	D3D11_DEPTH_STENCIL_DESC depthStencilDesc;
	ZeroMemory(&depthStencilDesc, sizeof(depthStencilDesc));
	depthStencilDesc.DepthEnable = TRUE;
	depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
	depthStencilDesc.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
	depthStencilDesc.StencilEnable = FALSE;
	m_Device->CreateDepthStencilState(&depthStencilDesc, &m_DepthStateEnable);//�[�x�L���X�e�[�g
	depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
	m_Device->CreateDepthStencilState(&depthStencilDesc, &m_DepthStateDisable);//�[�x�����X�e�[�g
	m_ImmediateContext->OMSetDepthStencilState(m_DepthStateEnable.Get(), NULL);

	// �T���v���[�X�e�[�g�ݒ�
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

	// �R���X�^���g�o�b�t�@�ݒ�
	m_ConstantBuffer.reset(new ConstantBuffer(m_Device.Get(), m_ImmediateContext.Get()));

	// ���C�g������
	Resource::Light light;
	light.Enable = false;
	SetLight(light);

	// �}�e���A��������
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
	// �o�b�N�o�b�t�@�N���A
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

	m_ImmediateContext->UpdateSubresource(m_ConstantBuffer->Get(ConstantBuffer::EBuffer::CONSTANT_BUFFER_WORLD), 0, NULL, &world, 0, 0);

	D3DXMATRIX view;
	D3DXMatrixIdentity(&view);
	D3DXMatrixTranspose(&view, &view);
	m_ImmediateContext->UpdateSubresource(m_ConstantBuffer->Get(ConstantBuffer::EBuffer::CONSTANT_BUFFER_VIEW), 0, NULL, &view, 0, 0);

	D3DXMATRIX projection;
	D3DXMatrixOrthoOffCenterLH(&projection, 0.0f, win_x, win_y, 0.0f, 0.0f, 1.0f);
	D3DXMatrixTranspose(&projection, &projection);
	m_ImmediateContext->UpdateSubresource(m_ConstantBuffer->Get(ConstantBuffer::EBuffer::CONSTANT_BUFFER_PROJECTION), 0, NULL, &projection, 0, 0);
}

void DirectXGraphics::SetWorldMatrix(D3DXMATRIX * WorldMatrix)
{
	D3DXMATRIX world;
	D3DXMatrixTranspose(&world, WorldMatrix);
	m_ImmediateContext->UpdateSubresource(m_ConstantBuffer->Get(ConstantBuffer::EBuffer::CONSTANT_BUFFER_WORLD), 0, NULL, &world, 0, 0);
}

void DirectXGraphics::SetViewMatrix(D3DXMATRIX * ViewMatrix)
{
	D3DXMATRIX view;
	D3DXMatrixTranspose(&view, ViewMatrix);
	m_ImmediateContext->UpdateSubresource(m_ConstantBuffer->Get(ConstantBuffer::EBuffer::CONSTANT_BUFFER_VIEW), 0, NULL, &view, 0, 0);
}

void DirectXGraphics::SetProjectionMatrix(D3DXMATRIX * ProjectionMatrix)
{
	D3DXMATRIX projection;
	D3DXMatrixTranspose(&projection, ProjectionMatrix);
	m_ImmediateContext->UpdateSubresource(m_ConstantBuffer->Get(ConstantBuffer::EBuffer::CONSTANT_BUFFER_PROJECTION), 0, NULL, &projection, 0, 0);
}

void DirectXGraphics::SetMaterial(Resource::Material Material)
{
	m_ImmediateContext->UpdateSubresource(m_ConstantBuffer->Get(ConstantBuffer::EBuffer::CONSTANT_BUFFER_MATERIAL), 0, NULL, &Material, 0, 0);
}

void DirectXGraphics::SetLight(Resource::Light Light)
{
	m_ImmediateContext->UpdateSubresource(m_ConstantBuffer->Get(ConstantBuffer::EBuffer::CONSTANT_BUFFER_LIGHT), 0, NULL, &Light, 0, 0);
}

void DirectXGraphics::SetCameraPosition(D3DXVECTOR3 CameraPosition)
{
	m_ImmediateContext->UpdateSubresource(m_ConstantBuffer->Get(ConstantBuffer::EBuffer::CONSTANT_BUFFER_CAMERA), 0, NULL, 
		&D3DXVECTOR4(CameraPosition.x, CameraPosition.y, CameraPosition.z, 1.0f), 0, 0);
}

void DirectXGraphics::SetParameter(D3DXVECTOR4 Parameter)
{
	m_ImmediateContext->UpdateSubresource(m_ConstantBuffer->Get(ConstantBuffer::EBuffer::CONSTANT_BUFFER_PARAMETER), 0, NULL, &Parameter, 0, 0);
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
