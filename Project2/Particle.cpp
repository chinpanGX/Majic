#include "Particle.h"
/*-------------------------------------------------------------

	[Particle.h]
	Author : 出合翔太

	パーティクルの処理
	エミッターを基準に生成する

--------------------------------------------------------------*/

Particle::Particle()
{
	m_Position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Scale = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Velocity = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Gravity = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Color = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);
	m_SizeWidth = 50.0f;
	m_SizeHeight = 50.0f;
	m_Life = 0;
	m_Use = false;
}

Particle::~Particle()
{
}
