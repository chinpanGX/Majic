/*-------------------------------------------------------------

	[Emitter.cpp]
	Author : 出合翔太

	パーティクルの管理

--------------------------------------------------------------*/
#include "Math.h"
#include "Emitter.h"
#include "GameManager.h"
#include "Scene.h"
#include "Camera.h"
#include "ObjectPool.h"

Emitter::Emitter() : m_SizeWidth(50.0f), m_SizeHeight(50.0f)
{
	//CreateVertex();
}

Emitter::~Emitter()
{
}

void Emitter::Uninit()
{
}

void Emitter::Update()
{
	for (int nCntParticle = 0; nCntParticle < m_NumMax; nCntParticle++)
	{
		if (m_Particle[nCntParticle].m_Use)
		{// 使用中
			m_Particle[nCntParticle].m_Position.x += m_Particle[nCntParticle].m_Velocity.x;
			m_Particle[nCntParticle].m_Position.z += m_Particle[nCntParticle].m_Velocity.z;

			m_Particle[nCntParticle].m_Position.y += m_Particle[nCntParticle].m_Velocity.y;
			if (m_Particle[nCntParticle].m_Position.y <= m_Particle[nCntParticle].m_SizeHeight / 2)
			{// 着地した
				m_Particle[nCntParticle].m_Position.y = m_Particle[nCntParticle].m_SizeHeight / 2;
				m_Particle[nCntParticle].m_Velocity.y = -m_Particle[nCntParticle].m_Velocity.y * 0.75f;
			}

			m_Particle[nCntParticle].m_Velocity.x += (0.0f - m_Particle[nCntParticle].m_Velocity.x) * 0.015f;
			m_Particle[nCntParticle].m_Velocity.y -= 0.25f;
			m_Particle[nCntParticle].m_Velocity.z += (0.0f - m_Particle[nCntParticle].m_Velocity.z) * 0.015f;


			m_Particle[nCntParticle].m_Life--;
			if (m_Particle[nCntParticle].m_Life <= 0)
			{
				m_Particle[nCntParticle].m_Use = false;
				//					ReleaseShadow(m_Particle[nCntParticle].nIdxShadow);
				//m_Particle[nCntParticle].m_nIdxShadow = -1;
			}
			else
			{
				if (m_Particle[nCntParticle].m_Life <= 80)
				{
					m_Particle[nCntParticle].m_Color.r = 0.60f - (float)(80 - m_Particle[nCntParticle].m_Life) / 8.0f * 0.06f + 0.2f;
					m_Particle[nCntParticle].m_Color.g = 0.70f - (float)(80 - m_Particle[nCntParticle].m_Life) / 8.0f * 0.07f;
					m_Particle[nCntParticle].m_Color.b = 0.05f;
				}

				if (m_Particle[nCntParticle].m_Life <= 20)
				{
					// α値設定
					m_Particle[nCntParticle].m_Color.a -= 0.05f;
					if (m_Particle[nCntParticle].m_Color.a < 0.0f)
					{
						m_Particle[nCntParticle].m_Color.a = 0.0f;
					}
				}

				// 色の設定
				SetColor(nCntParticle, m_Particle[nCntParticle].m_Color);
			}
		}
		
		// パーティクル発生
		{
			D3DXVECTOR3 pos;
			D3DXVECTOR3 move;
			D3DXCOLOR	color;
			float fAngle;
			float fLength = 10.0f;
			int nLife;
			float fSize;

			pos = D3DXVECTOR3(0.0f,5.0f, 0.0f) ;	//	パーティクル発生位置 
#if 0
			color.r = (float)(rand() % 255 - 125) / 100.0f;	//	r値
			color.g = (float)(rand() % 255 - 125) / 100.0f;	//	g値
			color.b = (float)(rand() % 255 - 125) / 100.0f;	//	b値
#else
			color.r = (float)(rand() % 255 / 2) / 100.0f;	//	r値
			color.g = (float)(rand() % 255 / 2) / 100.0f;	//	g値
			color.b = (float)(rand() % 255 / 2) / 100.0f;	//	b値
#endif
			fAngle = (float)(rand() % 628 - 314) / 100.0f;	//	発生位置から飛んでいく方向の角度
			//fLength = rand() % (int)(m_SizeWidth * 200) / 100.0f - m_SizeWidth;	//	発生位置から飛んでいく距離
			move.x = sinf(fAngle) * fLength;
			move.y = rand() % 300 / 100.0f + m_SizeHeight;
			move.z = cosf(fAngle) * fLength;
			nLife = rand() % 100 + 200;		//	寿命
			fSize = (float)(rand() % 30 + 20);	//	パーティクルの大きさ

			pos.y = fSize / 2;

			// ビルボードの設定
			SetParticle(pos, move, D3DXCOLOR(color.r, color.g, color.b,0.85f));
		}
	}
}

void Emitter::Draw()
{
	auto& dg = DirectXGraphics::GetInstance();
	auto* camera = GameManager::GetInstance().GetScene()->GetGameObject<Camera>(Scene::ELayer::L_CAMERA);
	Resource::Light light;
	light.Enable = false;
	dg.SetLight(light);
	// 加算合成
	dg.SetBlendState(BlendMode::BLEND_MODE_ADDITION);
	for (int i = 0; i < m_NumMax; i++)
	{
		if (m_Particle[i].m_Use)
		{
			D3DXMatrixIdentity(&m_Matrix);
			D3DXMATRIX view = camera->GetView();
			m_Matrix._11 = view._11;
			m_Matrix._12 = view._21;
			m_Matrix._13 = view._31;
			m_Matrix._21 = view._12;
			m_Matrix._22 = view._22;
			m_Matrix._23 = view._32;
			m_Matrix._31 = view._13;
			m_Matrix._32 = view._23;
			m_Matrix._33 = view._33;
			m_Matrix._41 = 0.0f;
			m_Matrix._42 = 0.0f;
			m_Matrix._44 = 0.0f;

			D3DXMATRIX m, s, t;
			D3DXMatrixScaling(&s, m_Particle[i].m_Scale.x, m_Particle[i].m_Scale.y, m_Particle[i].m_Scale.z);
			D3DXMatrixTranslation(&t, m_Particle[i].m_Position.x, m_Particle[i].m_Position.y, m_Particle[i].m_Position.z);
			m = s * m_Matrix * t;
			dg.SetWorldMatrix(&m);
			
			UINT stride = sizeof(Resource::Vertex);
			UINT offset = 0;
			dg.GetDeviceContext()->IASetVertexBuffers(0, 1, &m_VertexBuffer, &stride, &offset);

			//マテリアル設定
			Resource::Material material;
			ZeroMemory(&material, sizeof(material));
			material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			dg.SetMaterial(material);

			ObjectPool::SetTexture(dg, 0, Prefabs::Texture::EFFECT);
			dg.GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
			dg.GetDeviceContext()->Draw(4, 0);
		}
	}
	light.Enable = true;
	dg.SetLight(light);
	dg.SetBlendState(BlendMode::BLEND_MODE_NORMAL);
}

void Emitter::CreateVertex()
{
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
			m_Particle[i].m_Position = D3DXVECTOR3(Pos);
			m_Particle[i].m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_Particle[i].m_Scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
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
