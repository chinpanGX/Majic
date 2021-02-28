/*-----------------------------------------------------------

	[Prefabs.cpp]
	Author : 出合翔太

------------------------------------------------------------*/
#include "Prefabs.h"

#pragma region Prefabs_Texture_Func
void Prefabs::Texture::Load(DirectX11::Manager& dx)
{
	m_Texture = new Loader::Texture[m_Size];
	m_Texture[0].Load(dx, "Asset/Texture/black.png");
	m_Texture[1].Load(dx, "Asset/Texture/Title.png");
	m_Texture[2].Load(dx, "Asset/Texture/Game.png");
	m_Texture[3].Load(dx, "Asset/Texture/field004.jpg");
	m_Texture[4].Load(dx, "Asset/Texture/waffuru.tif");
}

void Prefabs::Texture::Unload()
{
	for (int i = m_Size -1; i >= 0; i--)
	{
		m_Texture[i].Unload();
	}
	delete[] m_Texture;
}

ID3D11ShaderResourceView * Prefabs::Texture::GetTexture(unsigned __int32 Id)
{
	return m_Texture[Id].GetTexture();
}
#pragma endregion Prefabs_Textureクラスの関数定義

#pragma region Prefabs_VertexShader_Func
void Prefabs::VertexShader::Load(DirectX11::Manager& dx)
{
	m_VertexShader = new Loader::VertexShader[m_Size];
	m_VertexShader[0].Load(dx, "Asset/Shader/vertexShader.cso");
	m_VertexShader[1].Load(dx, "Asset/Shader/MappingVS.cso");
}

void Prefabs::VertexShader::Unload()
{
	for (int i = m_Size -1; i >= 0; i--)
	{
		m_VertexShader[i].Unload();
	}
	delete[] m_VertexShader;
}

ID3D11VertexShader * Prefabs::VertexShader::GetVertexShader(unsigned __int32 Id)
{
	return m_VertexShader[Id].GetVertexShader();
}

ID3D11InputLayout * Prefabs::VertexShader::GetInputLayout(unsigned __int32 Id)
{
	return m_VertexShader[Id].GetInputLayout();
}
#pragma endregion Prefabs_VertexShaderクラスの関数定義

#pragma region Prefabs_PixelShader_Func
void Prefabs::PixelShader::Load(DirectX11::Manager & dx)
{
	m_PixelShader = new Loader::PixelShader[m_Size];
	m_PixelShader[0].Load(dx, "Asset/Shader/pixelShader.cso");
	m_PixelShader[1].Load(dx, "Asset/Shader/MappingPS.cso");
}

void Prefabs::PixelShader::Unload()
{
	for (int i = m_Size -1; i >= 0; i--)
	{
		m_PixelShader[i].Unload();
	}
	delete[] m_PixelShader;
}

ID3D11PixelShader * Prefabs::PixelShader::GetPixelShader(unsigned __int32 Id)
{
	return m_PixelShader[Id].GetPixelShader();
}
#pragma endregion Prefabs_PixelShaderクラスの関数定義
