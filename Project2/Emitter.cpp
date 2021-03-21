/*-------------------------------------------------------------

	[Emitter.cpp]
	Author : 出合翔太

	パーティクルの管理

--------------------------------------------------------------*/
#include "Emitter.h"
#include "GameManager.h"
#include "Scene.h"
#include "Camera.h"

Emitter::Emitter() : m_VertexBuffer(nullptr), m_NumMax(512),m_SizeWidth(50.0f), m_SizeHeight(50.0f)
{
}

Emitter::~Emitter()
{
}

void Emitter::Init()
{

}

void Emitter::Uninit()
{
}

void Emitter::Update()
{
}

void Emitter::Draw()
{
	auto camera = GameManager::GetInstance().GetScene()->GetGameObject<Camera>(Scene::ELayer::L_CAMERA);

}

void Emitter::CreateVertex()
{
	//頂点バッファ生成
	auto& r = DirectXGraphics::GetInstance();
	Resource::Vertex* v;
	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DYNAMIC;
	bd.ByteWidth = sizeof(Resource::Vertex) * 4 * m_NumMax;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

	D3D11_SUBRESOURCE_DATA sd;
	ZeroMemory(&sd, sizeof(sd));
	//sd.pSysMem = v;
	r.GetDevice()->CreateBuffer(&bd, &sd, m_VertexBuffer.GetAddressOf());

	D3D11_MAPPED_SUBRESOURCE msr;
	r.GetDeviceContext()->Map(m_VertexBuffer.Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);
	v = (Resource::Vertex*)msr.pData;

	for (int32_t i = 0; i < m_NumMax; i++ , v += 4)
	{
		v[0].Position = D3DXVECTOR3(-m_SizeWidth * 0.5f, -m_SizeHeight * 0.5f, 0.0f);
		v[1].Position = D3DXVECTOR3( m_SizeWidth * 0.5f, -m_SizeHeight * 0.5f, 0.0f);
		v[2].Position = D3DXVECTOR3(-m_SizeWidth * 0.5f,  m_SizeHeight * 0.5f, 0.0f);
		v[3].Position = D3DXVECTOR3( m_SizeWidth * 0.5f,  m_SizeHeight * 0.5f, 0.0f);

		v[0].Normal = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		v[1].Normal = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		v[2].Normal = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		v[3].Normal = D3DXVECTOR3(0.0f, 0.0f, -1.0f);

		v[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		v[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		v[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		v[3].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);

		v[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);
		v[1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);
		v[2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);
		v[3].TexCoord = D3DXVECTOR2(1.0f, 1.0f);
	}
	r.GetDeviceContext()->Unmap(m_VertexBuffer.Get(), 0);
}

void Emitter::SetVertex(int32_t Index, float Width, float Height)
{
	auto& r = DirectXGraphics::GetInstance();
	Resource::Vertex* v;
	D3D11_MAPPED_SUBRESOURCE msr;
	r.GetDeviceContext()->Map(m_VertexBuffer.Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);
	v = (Resource::Vertex*)msr.pData;
	v += (Index * 4);
	// 座標の設定
	v[0].Position = D3DXVECTOR3(-Width * 0.5f, -Height * 0.5f, 0.0f);
	v[1].Position = D3DXVECTOR3( Width * 0.5f, -Height * 0.5f, 0.0f);
	v[2].Position = D3DXVECTOR3(-Width * 0.5f,  Height * 0.5f, 0.0f);
	v[3].Position = D3DXVECTOR3( Width * 0.5f,  Height * 0.5f, 0.0f);
	r.GetDeviceContext()->Unmap(m_VertexBuffer.Get(), 0);
}

int32_t Emitter::SetParticle(D3DXVECTOR3 Pos, D3DXVECTOR3 Move, D3DXCOLOR Color)
{
	int32_t index;
	for (int32_t i = 0; i < m_NumMax; i++)
	{
		if (!m_Particle[i].m_Use)
		{
			m_Particle[i].SetPosition(Pos);
			m_Particle[i].SetRotation(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			m_Particle[i].SetScale(D3DXVECTOR3(1.0f, 1.0f, 1.0f));
			m_Particle[i].m_Velocity = Move;
			m_Particle[i].m_Use = true;

			SetVertex(i, m_SizeWidth, m_SizeHeight);
			index = i;
			break;
		}
	}
	return index;
}

void Emitter::SetColor(int32_t Index, D3DXCOLOR Color)
{
	auto& r = DirectXGraphics::GetInstance();
	Resource::Vertex* v;
	D3D11_MAPPED_SUBRESOURCE msr;
	r.GetDeviceContext()->Map(m_VertexBuffer.Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);
	v = (Resource::Vertex*)msr.pData;
	v += (Index * 4);
	// 座標の設定
	v[0].Diffuse = v[1].Diffuse = v[2].Diffuse = v[3].Diffuse = (D3DXVECTOR4)Color;
	r.GetDeviceContext()->Unmap(m_VertexBuffer.Get(), 0);
}
