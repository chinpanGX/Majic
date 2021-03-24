#include "ComputeEffect.h"
#include "Shader.h"
#include "Effect.h"


int Amount = 512;

void ComputeEffect::Init()
{
	float Size = 50.0f;
	VertexPraticle vertex[4];
	vertex[0].m_Position = D3DXVECTOR3(-Size, Size, 0.0f);
	vertex[0].m_TexCoord = D3DXVECTOR2(0.0f, 0.0f);
	vertex[1].m_Position = D3DXVECTOR3(Size, Size, 0.0f);
	vertex[1].m_TexCoord = D3DXVECTOR2(1.0f, 0.0f);
	vertex[2].m_Position = D3DXVECTOR3(-Size, -Size, 0.0f);
	vertex[2].m_TexCoord = D3DXVECTOR2(0.0f, 1.0f);
	vertex[3].m_Position = D3DXVECTOR3(Size, -Size, 0.0f);
	vertex[3].m_TexCoord = D3DXVECTOR2(1.0f, 1.0f);

	for (size_t i = 0; i < Amount; i++)
	{
		m_Particle[i] = std::make_unique<ParticleCompute>();
		m_Particle[i]->m_Velocity = D3DXVECTOR3(0, 1, 0);
		m_Particle[i]->m_Life = 300;
		m_Particle[i]->m_Position = D3DXVECTOR3(0, 0, 0);
	}
	
	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DYNAMIC;
	bd.ByteWidth = sizeof(VertexPraticle) * 4;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	D3D11_SUBRESOURCE_DATA sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.pSysMem = vertex;
	auto dev = DirectXGraphics::GetInstance().GetDevice();
	dev->CreateBuffer(&bd, &sd, m_VertexBuffer.GetAddressOf());
	
	// SRVの生成
	D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
	ZeroMemory(&srvDesc, sizeof(srvDesc));
	srvDesc.Format = DXGI_FORMAT_UNKNOWN;
	srvDesc.ViewDimension = D3D11_SRV_DIMENSION_BUFFER;
	srvDesc.Buffer.ElementWidth = Amount;
	dev->CreateShaderResourceView(m_VertexBuffer.Get(), &srvDesc, m_ParticleSRV.GetAddressOf());
	
	// SRVの生成
	D3D11_SHADER_RESOURCE_VIEW_DESC sDesc;
	ZeroMemory(&sDesc, sizeof(sDesc));
	sDesc.Format = DXGI_FORMAT_UNKNOWN;
	sDesc.ViewDimension = D3D11_SRV_DIMENSION_BUFFER;
	sDesc.Buffer.ElementWidth = Amount;
	dev->CreateShaderResourceView(m_VertexBuffer.Get(), &sDesc, m_PositionSRV.GetAddressOf());

	// UAVの生成
	D3D11_UNORDERED_ACCESS_VIEW_DESC uavDesc;
	ZeroMemory(&uavDesc, sizeof(uavDesc));
	uavDesc.Format = DXGI_FORMAT_UNKNOWN;
	uavDesc.ViewDimension = D3D11_UAV_DIMENSION_BUFFER;
	uavDesc.Buffer.NumElements = Amount;
	dev->CreateUnorderedAccessView(m_VertexBuffer.Get(), &uavDesc, m_ResultUAV.GetAddressOf());
}

void ComputeEffect::Uninit()
{
	
}

void ComputeEffect::Update()
{
	auto context = DirectXGraphics::GetInstance().GetDeviceContext();
	D3D11_MAPPED_SUBRESOURCE sub;
	context->Map(m_ParticleBuffer.Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &sub);
	ParticleCompute* pType = (ParticleCompute*)sub.pData;
	for (size_t i = 0; i < Amount; i++)
	{
		memcpy(sub.pData, m_Particle[i].get(), sizeof(ParticleCompute) * Amount);
	}
	context->Unmap(m_VertexBuffer.Get(), 0);
}

void ComputeEffect::Draw()
{
}

/*
using namespace Microsoft::WRL;
// SRVとUAVで構造化バッファを作成するためのヘルパー関数
HRESULT CreateStructuedBuffer(UINT NumElements, ComPtr<ID3D11Buffer> ppBuffer, ComPtr<ID3D11ShaderResourceView> ppSRV, ComPtr<ID3D11UnorderedAccessView> ppUAV)
{
	// デバイスの取得
	auto& dev = Resource::GetInstance().GetDevice();

	HRESULT hr = S_OK;

	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.ByteWidth = NumElements; * sizeof(T);
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.BindFlags = D3D11_BIND_UNORDERED_ACCESS | D3D11_BIND_SHADER_RESOURCE;
	bd.MiscFlags = D3D11_RESOURCE_MISC_BUFFER_STRUCTURED;
	bd.CPUAccessFlags = D3D10_CPU_ACCESS_WRITE;
	bd.StructureByteStride = sizeof(T);

	D3D11_SUBRESOURCE_DATA sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.pSysMem = pInitData;
	dev->CreateBuffer(&bd, (pInitData) ? &sd : nullptr, ppBuffer);

	// SRVの生成
	D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
	ZeroMemory(&srvDesc, sizeof(srvDesc));
	srvDesc.Format = DXGI_FORMAT_UNKNOWN;
	srvDesc.ViewDimension = D3D11_SRV_DIMENSION_BUFFER;
	srvDesc.Buffer.ElementWidth = NumElements;
	dev->CreateShaderResourceView(*ppBuffer, &srvDesc, ppSRV);

	// UAVの生成
	D3D11_UNORDERED_ACCESS_VIEW_DESC uavDesc;
	ZeroMemory(&uavDesc, sizeof(uavDesc));
	uavDesc.Format = DXGI_FORMAT_UNKNOWN;
	uavDesc.ViewDimension = D3D11_UAV_DIMENSION_BUFFER;
	uavDesc.Buffer.NumElements = NumElements;
	dev->CreateUnorderedAccessView(*ppBuffer, &uavDesc, ppUAV);

	return hr;
}*/