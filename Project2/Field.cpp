/*-------------------------------------------------------------

	[Field.h]
	Author : o‡ãÄ‘¾

--------------------------------------------------------------*/
#include "ObjectPool.h"
#include "Resource.h"
#include "Field.h"

Field::Field() : m_Res(Resource::GetInstance())
{
}

void Field::Init()
{
	Resource::Vertex v[4];
	Create(v);
	m_Polygon.reset(new Polygon3D(m_Res, v));

	m_Position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Scale = D3DXVECTOR3(10.0f, 10.0f, 10.0f);
}

void Field::Uninit()
{
	//delete m_Polygon;
}

void Field::Update()
{
}

void Field::Draw()
{
	ObjectPool::SetInputLayout(m_Res, Prefabs::VertexShader::MAPPING);
	ObjectPool::SetVertexShader(m_Res, Prefabs::VertexShader::MAPPING);
	ObjectPool::SetPixelShader(m_Res, Prefabs::PixelShader::MAPPING);
	ObjectPool::SetTexture(m_Res, 0, Prefabs::Texture::FIELD);
	ObjectPool::SetTexture(m_Res, 1, Prefabs::Texture::WAFFURU);
	m_Polygon->DrawPolygon(m_Res, m_Position, m_Rotation, m_Scale);
}

void Field::Create(Resource::Vertex Vertex[4])
{
	Vertex[0].Position = D3DXVECTOR3(-10.0f, 0.0f, 10.0f);
	Vertex[0].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	Vertex[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	Vertex[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

	Vertex[1].Position = D3DXVECTOR3(10.0f, 0.0f, 10.0f);
	Vertex[1].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	Vertex[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	Vertex[1].TexCoord = D3DXVECTOR2(10.0f, 0.0f);

	Vertex[2].Position = D3DXVECTOR3(-10.0f, 0.0f, -10.0f);
	Vertex[2].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	Vertex[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	Vertex[2].TexCoord = D3DXVECTOR2(0.0f, 10.0f);

	Vertex[3].Position = D3DXVECTOR3(10.0f, 0.0f, -10.0f);
	Vertex[3].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	Vertex[3].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	Vertex[3].TexCoord = D3DXVECTOR2(10.0f, 10.0f);
}
