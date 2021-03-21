/*-----------------------------------------------------------

	[Prefabs.cpp]
	Author : èoçá„ƒëæ

------------------------------------------------------------*/
#include "Prefabs.h"
#include <io.h>

Prefabs::Texture::Texture(DirectXGraphics & dx)
{
	for (std::int32_t i = 0; i < m_Size; i++)
	{
		m_Texture[i].reset(new LoadTexture);
	}
	m_Texture[0]->Load(dx, "Asset/Texture/black.png");
	m_Texture[1]->Load(dx, "Asset/Texture/Title.png");
	m_Texture[2]->Load(dx, "Asset/Texture/Game.png");
	m_Texture[3]->Load(dx, "Asset/Texture/field004.jpg");
	m_Texture[4]->Load(dx, "Asset/Texture/waffuru.tif");
	m_Texture[5]->Load(dx, "Asset/Texture/Effect.jpg");
}

ID3D11ShaderResourceView * Prefabs::Texture::GetTexture(int32_t Id)
{
	return m_Texture[Id]->GetTexture().Get();
}

Prefabs::VertexShader::VertexShader(DirectXGraphics & dx)
{
	for (int32_t i = 0; i < m_Size; i++)
	{
		m_VertexShader[i].reset(new Shader::VertexShader);
	}
	m_VertexShader[0]->Load(dx, "Asset/Shader/vertexShader.cso");
	m_VertexShader[1]->Load(dx, "Asset/Shader/MappingVS.cso");
}

ID3D11VertexShader * Prefabs::VertexShader::GetVertexShader(int32_t Id)
{
	return m_VertexShader[Id]->GetVertexShader().Get();
}

ID3D11InputLayout * Prefabs::VertexShader::GetInputLayout(int32_t Id)
{
	return m_VertexShader[Id]->GetInputLayout().Get();
}

Prefabs::PixelShader::PixelShader(DirectXGraphics & dx)
{
	for (int32_t i = 0; i < m_Size; i++)
	{
		m_PixelShader[i].reset(new Shader::PixelShader);
	}
	m_PixelShader[0]->Load(dx, "Asset/Shader/pixelShader.cso");
	m_PixelShader[1]->Load(dx, "Asset/Shader/MappingPS.cso");
}

ID3D11PixelShader * Prefabs::PixelShader::GetPixelShader(int32_t Id)
{
	return m_PixelShader[Id]->GetPixelShader().Get();
}
