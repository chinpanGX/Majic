/*-----------------------------------------------

	[Pawn.h]
	Author : 出合翔太

	[説明]


-----------------------------------------------*/
#pragma once
#include "GameObject.h"

class Pawn : public GameObject
{
public:
	Pawn(){}
	virtual ~Pawn(){}
	virtual void Init() = 0;
	virtual void Uninit() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
protected:
	__int32 m_AnimFrame; // アニメーション
	float m_BlendRate;  // アニメーションブレンド
};

