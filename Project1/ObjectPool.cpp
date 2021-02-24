/*-----------------------------------------------------------

	[ObjectPool.cpp]
	Author : o‡ãÄ‘¾

------------------------------------------------------------*/
#include "ObjectPool.h"

Prefabs::Texture* ObjectPool::m_Texture;
Prefabs::VertexShader* ObjectPool::m_VertexShader;
Prefabs::PixelShader* ObjectPool::m_PixelShader;

void ObjectPool::Init()
{
	auto & dx = DirectX11::Manager::GetInstance();
	m_Texture = new Prefabs::Texture;
	m_Texture->Load(dx);
	m_VertexShader = new Prefabs::VertexShader();
	m_VertexShader->Load(dx);
	m_PixelShader = new Prefabs::PixelShader();
	m_PixelShader->Load(dx);
}

void ObjectPool::Uninit()
{
	m_PixelShader->Unload();
	delete m_PixelShader;
	m_VertexShader->Unload();
	delete m_VertexShader;
	m_Texture->Unload();
	delete m_Texture;
}

void ObjectPool::Update(DirectX11::Manager & dx, unsigned __int32 Id, const char * AnimationName1, const char * AnimationName2, float BlendRate, int Frame)
{
	//m_Model->GetModel(Id)->Update(dx, AnimationName1, AnimationName2, BlendRate, Frame);
}

void ObjectPool::Draw(DirectX11::Manager & dx, unsigned __int32 Id)
{
	//m_Model ->GetModel(Id)->Draw(dx);
}

ID3D11ShaderResourceView * ObjectPool::GetTexture(unsigned int Id)
{
	return m_Texture->GetTexture(Id);
}

void ObjectPool::SetTexture(DirectX11::Manager & dx, int slot, unsigned int Id)
{
	ID3D11ShaderResourceView* t = m_Texture->GetTexture(Id);
	dx.GetDeviceContext()->PSSetShaderResources(slot, 1, &t);
}

void ObjectPool::SetVertexShader(DirectX11::Manager & dx, unsigned int Id)
{
	dx.GetDeviceContext()->VSSetShader(m_VertexShader->GetVertexShader(Id), NULL, 0);
}

void ObjectPool::SetInputLayout(DirectX11::Manager & dx, unsigned int Id)
{
	dx.GetDeviceContext()->IASetInputLayout(m_VertexShader->GetInputLayout(Id));
}

void ObjectPool::SetPixelShader(DirectX11::Manager & dx, unsigned int Id)
{
	dx.GetDeviceContext()->PSSetShader(m_PixelShader->GetPixelShader(Id), NULL, 0);
}
