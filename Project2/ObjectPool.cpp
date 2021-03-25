/*-----------------------------------------------------------

	[ObjectPool.cpp]
	Author : èoçá„ƒëæ

------------------------------------------------------------*/
#include "ObjectPool.h"

namespace
{
	std::unique_ptr<Prefabs::Texture> g_Texture;
	std::unique_ptr<Prefabs::VertexShader> g_VertexShader;
	std::unique_ptr<Prefabs::PixelShader> g_PixelShader;
	std::unique_ptr<Prefabs::ComputeShader> g_ComputeShader;
}

void ObjectPool::Init()
{
	auto & dx = DirectXGraphics::GetInstance();
	g_Texture = std::make_unique<Prefabs::Texture>(dx);
	g_VertexShader = std::make_unique <Prefabs::VertexShader>(dx);
	g_PixelShader = std::make_unique<Prefabs::PixelShader>(dx);
}

ID3D11ShaderResourceView * GetTexture(int32_t Id)
{
	return g_Texture->GetTexture(Id);
}

void SetTexture(DirectXGraphics & dx, int slot,int32_t Id)
{
	ID3D11ShaderResourceView* t = g_Texture->GetTexture(Id);
	dx.GetDeviceContext()->PSSetShaderResources(slot, 1, &t);
}

void SetVertexShader(DirectXGraphics & dx,int32_t Id)
{
	dx.GetDeviceContext()->VSSetShader(g_VertexShader->GetVertexShader(Id), NULL, 0);
}

void SetInputLayout(DirectXGraphics & dx,int32_t Id)
{
	dx.GetDeviceContext()->IASetInputLayout(g_VertexShader->GetInputLayout(Id));
}

void SetPixelShader(DirectXGraphics & dx,int32_t Id)
{
	dx.GetDeviceContext()->PSSetShader(g_PixelShader->GetPixelShader(Id), NULL, 0);
}

void SetGeometryShader(DirectXGraphics & dx, int32_t Id)
{
}

void SetComputeShader(DirectXGraphics & dx, int32_t Id)
{
}
