/*-------------------------------------------------------------

	[Particle.h]
	Author : 出合翔太

	パーティクルの処理
	エミッターを基準に生成する

--------------------------------------------------------------*/
#pragma once
#include "GameObject.h"

class Particle : public GameObject
{
public:
	Particle()
	{
		m_Position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_Scale = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_Velocity = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_Gravity = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_Color = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);
		m_SizeWidth = 50.0f;
		m_sizeHeight = 50.0f;
		m_Life = 0;
		m_Use = false;
	}
	~Particle(){}
	D3DXVECTOR3 m_Velocity; // 速度　　positionに加算
	D3DXVECTOR3 m_Gravity;  // 重力値　Velocityに加算する
	D3DCOLOR m_Color;		// 色
	float m_SizeWidth;		// 横幅
	float m_sizeHeight;		// 縦幅
	int32_t	m_Life;			// 有効時間	
	bool m_Use;				// 有効かどうか
};

