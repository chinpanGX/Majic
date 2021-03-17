/*-----------------------------------------------------------

	[ObjectPool.cpp]
	Author : èoçá„ƒëæ

------------------------------------------------------------*/
#include "ObjectPool.h"

std::unique_ptr<Prefabs::Texture> ObjectPool::m_Texture;
std::unique_ptr<Prefabs::VertexShader> ObjectPool::m_VertexShader;
std::unique_ptr<Prefabs::PixelShader> ObjectPool::m_PixelShader;

void ObjectPool::Init()
{
	auto & dx = Resource::GetInstance();
	m_Texture = std::make_unique<Prefabs::Texture>();
	m_Texture->Load(dx);
	m_VertexShader = std::make_unique <Prefabs::VertexShader>();
	m_VertexShader->Load(dx);
	m_PixelShader = std::make_unique<Prefabs::PixelShader>();
	m_PixelShader->Load(dx);
}

void ObjectPool::Uninit()
{
	m_PixelShader->Unload();
	m_VertexShader->Unload();
	m_Texture->Unload();
}

void ObjectPool::Update(Resource & dx,int32_t Id, const char * AnimationName1, const char * AnimationName2, float BlendRate, int Frame)
{
	//m_Model->GetModel(Id)->Update(dx, AnimationName1, AnimationName2, BlendRate, Frame);
}

void ObjectPool::Draw(Resource & dx,int32_t Id)
{
	//m_Model ->GetModel(Id)->Draw(dx);
}

ID3D11ShaderResourceView * ObjectPool::GetTexture(int32_t Id)
{
	return m_Texture->GetTexture(Id);
}

void ObjectPool::SetTexture(Resource & dx, int slot,int32_t Id)
{
	ID3D11ShaderResourceView* t = m_Texture->GetTexture(Id);
	dx.GetDeviceContext()->PSSetShaderResources(slot, 1, &t);
}

void ObjectPool::SetVertexShader(Resource & dx,int32_t Id)
{
	dx.GetDeviceContext()->VSSetShader(m_VertexShader->GetVertexShader(Id), NULL, 0);
}

void ObjectPool::SetInputLayout(Resource & dx,int32_t Id)
{
	dx.GetDeviceContext()->IASetInputLayout(m_VertexShader->GetInputLayout(Id));
}

void ObjectPool::SetPixelShader(Resource & dx,int32_t Id)
{
	dx.GetDeviceContext()->PSSetShader(m_PixelShader->GetPixelShader(Id), NULL, 0);
}
