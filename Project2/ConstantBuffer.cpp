/*--------------------------------------------------------------

	[ConstantBuffer.cpp]
	Author : 出合翔太

	定数バッファの管理

---------------------------------------------------------------*/
#include "ConstantBuffer.h"
#include "Application.h"

namespace
{
	const float g_WindowWidth = Application::GetInstance().GetWindowSize().cx;
	const float g_WindowHeight = Application::GetInstance().GetWindowSize().cy;
}

ConstantBuffer::ConstantBuffer()
{
}

ConstantBuffer::ConstantBuffer(ID3D11Device* Dev, ID3D11DeviceContext* Context)
{
	auto dev = Dev;
	auto con = Context;
	// 定数バッファ生成
	D3D11_BUFFER_DESC hBufferDesc;
	hBufferDesc.ByteWidth = sizeof(D3DXMATRIX);
	hBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	hBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	hBufferDesc.CPUAccessFlags = 0;
	hBufferDesc.MiscFlags = 0;
	hBufferDesc.StructureByteStride = sizeof(float);

	for (size_t i = 0; i < m_Buffer.size(); i++)
	{
		switch (i)
		{
		case ConstantBuffer::CONSTANT_BUFFER_WORLD:
			dev->CreateBuffer(&hBufferDesc, NULL, m_Buffer[i].GetAddressOf());
			con->VSSetConstantBuffers(0, 1, m_Buffer[i].GetAddressOf());
			break;
		case ConstantBuffer::CONSTANT_BUFFER_VIEW:
			dev->CreateBuffer(&hBufferDesc, NULL, m_Buffer[i].GetAddressOf());
			con->VSSetConstantBuffers(1, 1, m_Buffer[i].GetAddressOf());
			break;
		case ConstantBuffer::CONSTANT_BUFFER_PROJECTION:
			dev->CreateBuffer(&hBufferDesc, NULL, m_Buffer[i].GetAddressOf());
			con->VSSetConstantBuffers(2, 1, m_Buffer[i].GetAddressOf());
			break;
		case ConstantBuffer::CONSTANT_BUFFER_MATERIAL:
			hBufferDesc.ByteWidth = sizeof(Resource::Material);
			dev->CreateBuffer(&hBufferDesc, NULL, m_Buffer[i].GetAddressOf());
			con->VSSetConstantBuffers(3, 1, m_Buffer[i].GetAddressOf());
			break;
		case ConstantBuffer::CONSTANT_BUFFER_LIGHT:
			hBufferDesc.ByteWidth = sizeof(Resource::Light);
			dev->CreateBuffer(&hBufferDesc, NULL, m_Buffer[i].GetAddressOf());
			con->VSSetConstantBuffers(4, 1, m_Buffer[i].GetAddressOf());
			con->PSSetConstantBuffers(4, 1, m_Buffer[i].GetAddressOf());
			break;
		case ConstantBuffer::CONSTANT_BUFFER_CAMERA:
			hBufferDesc.ByteWidth = sizeof(D3DXVECTOR4);
			dev->CreateBuffer(&hBufferDesc, NULL, m_Buffer[i].GetAddressOf());
			con->PSSetConstantBuffers(5, 1, m_Buffer[i].GetAddressOf());
			break;
		case ConstantBuffer::CONSTANT_BUFFER_PARAMETER:
			hBufferDesc.ByteWidth = sizeof(D3DXVECTOR4);
			dev->CreateBuffer(&hBufferDesc, NULL, m_Buffer[i].GetAddressOf());
			con->PSSetConstantBuffers(6, 1, m_Buffer[i].GetAddressOf());
			break;
		}
	}
}

ConstantBuffer::~ConstantBuffer()
{
}

ID3D11Buffer * ConstantBuffer::Get(EBuffer Buf) const
{
	return m_Buffer[Buf].Get();	
}
