/*-------------------------------------------------------------

	[Particle.h]
	Author : 出合翔太

	パーティクルの処理
	エミッターを基準に生成する

--------------------------------------------------------------*/
#pragma once
#include "GameObject.h"

class Particle
{
public:
	Particle();
	~Particle();
	D3DXVECTOR3 m_Position;
	D3DXVECTOR3 m_Rotation;
	D3DXVECTOR3 m_Scale;
	//D3DXVECTOR3 m_Gravity;  // 重力値　Velocityに加算する
	D3DXCOLOR m_Color;		// 色
	int32_t	m_Life;			// 有効時間	
	bool m_Use;				// 有効かどうか
};
;