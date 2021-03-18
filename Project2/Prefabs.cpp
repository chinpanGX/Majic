/*-----------------------------------------------------------

	[Prefabs.cpp]
	Author : 出合翔太

------------------------------------------------------------*/
#include "Prefabs.h"

void Prefabs::Texture::Load(Resource& dx)
{
	m_Texture.reset(new Loader::Texture[m_Size]);
	m_Texture[0].Load(dx, "Asset/Texture/black.png");
	m_Texture[1].Load(dx, "Asset/Texture/Title.png");
	m_Texture[2].Load(dx, "Asset/Texture/Game.png");
	m_Texture[3].Load(dx, "Asset/Texture/field004.jpg");
	m_Texture[4].Load(dx, "Asset/Texture/waffuru.tif");
	m_Texture[5].Load(dx, "Asset/Texture/Effect.jpg");
}

void Prefabs::Texture::Unload()
{
	for (int i = m_Size - 1; i >= 0; i--)
	{
		m_Texture[i].Unload();
	}
}

ID3D11ShaderResourceView * Prefabs::Texture::GetTexture(int32_t Id)
{
	return m_Texture[Id].GetTexture();
}
#pragma endregion Prefabs_Textureクラスの関数定義

#pragma region Prefabs_VertexShader_Func
void Prefabs::VertexShader::Load(Resource& dx)
{
	m_VertexShader.reset(new Loader::VertexShader[m_Size]);
	m_VertexShader[0].Load(dx, "Asset/Shader/vertexShader.cso");
	m_VertexShader[1].Load(dx, "Asset/Shader/MappingVS.cso");
}

void Prefabs::VertexShader::Unload()
{
	for (int i = m_Size - 1; i >= 0; i--)
	{
		m_VertexShader[i].Unload();
	}
}

ID3D11VertexShader * Prefabs::VertexShader::GetVertexShader(int32_t Id)
{
	return m_VertexShader[Id].GetVertexShader();
}

ID3D11InputLayout * Prefabs::VertexShader::GetInputLayout(int32_t Id)
{
	return m_VertexShader[Id].GetInputLayout();
}

void Prefabs::PixelShader::Load(Resource & dx)
{
	m_PixelShader.reset(new Loader::PixelShader[m_Size]);
	m_PixelShader[0].Load(dx, "Asset/Shader/pixelShader.cso");
	m_PixelShader[1].Load(dx, "Asset/Shader/MappingPS.cso");
}

void Prefabs::PixelShader::Unload()
{
	for (int i = m_Size - 1; i >= 0; i--)
	{
		m_PixelShader[i].Unload();
	}
}

ID3D11PixelShader * Prefabs::PixelShader::GetPixelShader(int32_t Id)
{
	return m_PixelShader[Id].GetPixelShader();
}
