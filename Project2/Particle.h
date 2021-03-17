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
	D3DXVECTOR3 m_Velocity; // 速度　　positionに加算
	D3DXVECTOR3 m_Gravity;  // 重力値　Velocityに加算する
	D3DCOLOR m_Color;		// 色
};

