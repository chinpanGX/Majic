
#include "PrefabsTexture.h"

LoadTexture::LoadTexture() : m_Texture(nullptr){}
LoadTexture::~LoadTexture() {}

void LoadTexture::Load(DirectXGraphics & dx, std::string FileName)
{
	D3DX11CreateShaderResourceViewFromFile(dx.GetDevice(), FileName.c_str(), NULL, NULL, m_Texture.GetAddressOf(), NULL);	
}

Prefabs::Texture::Texture() {}

Prefabs::Texture::Texture(DirectXGraphics & dx)
{
	for (std::int32_t i = 0; i < m_Size; i++)
	{
		m_Texture[i] = std::make_unique<LoadTexture>();
	}
	m_Texture[0]->Load(dx, "Asset/Texture/black.png");
	m_Texture[1]->Load(dx, "Asset/Texture/Title.png");
	m_Texture[2]->Load(dx, "Asset/Texture/Game.png");
	m_Texture[3]->Load(dx, "Asset/Texture/field004.jpg");
	m_Texture[4]->Load(dx, "Asset/Texture/waffuru.tif");
	m_Texture[5]->Load(dx, "Asset/Texture/Effect.jpg");
}

Prefabs::Texture::~Texture() {}

ID3D11ShaderResourceView * Prefabs::Texture::GetTexture(int32_t Id)
{
	return m_Texture[Id]->GetTexture().Get();
}
