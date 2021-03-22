/*-----------------------------------------------------------

	[ObjectPool.cpp]
	Author : èoçá„ƒëæ

------------------------------------------------------------*/
#include "ObjectPool.h"

std::unique_ptr<Prefabs::Texture> ObjectPool::m_Texture;
std::unique_ptr<Prefabs::VertexShader> ObjectPool::m_VertexShader;
std::unique_ptr<Prefabs::PixelShader> ObjectPool::m_PixelShader;

ObjectPool::~ObjectPool()
{
}

void ObjectPool::Init()
{
	auto & dx = DirectXGraphics::GetInstance();
	m_Texture = std::make_unique<Prefabs::Texture>(dx);
	m_VertexShader = std::make_unique <Prefabs::VertexShader>(dx);
	m_PixelShader = std::make_unique<Prefabs::PixelShader>(dx);
}


void ObjectPool::Update(DirectXGraphics & dx,int32_t Id, const char * AnimationName1, const char * AnimationName2, float BlendRate, int Frame)
{
	//m_Model->GetModel(Id)->Update(dx, AnimationName1, AnimationName2, BlendRate, Frame);
}

void ObjectPool::Draw(DirectXGraphics & dx,int32_t Id)
{
	//m_Model ->GetModel(Id)->Draw(dx);
}

ID3D11ShaderResourceView * ObjectPool::GetTexture(int32_t Id)
{
	return m_Texture->GetTexture(Id);
}

void ObjectPool::SetTexture(DirectXGraphics & dx, int slot,int32_t Id)
{
	ID3D11ShaderResourceView* t = m_Texture->GetTexture(Id);
	dx.GetDeviceContext()->PSSetShaderResources(slot, 1, &t);
}

void ObjectPool::SetVertexShader(DirectXGraphics & dx,int32_t Id)
{
	dx.GetDeviceContext()->VSSetShader(m_VertexShader->GetVertexShader(Id), NULL, 0);
}

void ObjectPool::SetInputLayout(DirectXGraphics & dx,int32_t Id)
{
	dx.GetDeviceContext()->IASetInputLayout(m_VertexShader->GetInputLayout(Id));
}

void ObjectPool::SetPixelShader(DirectXGraphics & dx,int32_t Id)
{
	dx.GetDeviceContext()->PSSetShader(m_PixelShader->GetPixelShader(Id), NULL, 0);
}
