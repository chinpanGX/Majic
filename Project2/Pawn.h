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
	Pawn() : m_AnimFrame(0),m_BlendRate(0.0f),m_Velocity(D3DXVECTOR3(0.0f,0.0f,0.0f)),m_Enable(true){}
	virtual ~Pawn(){}
	virtual void Init() = 0;
	virtual void Uninit() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	// 死亡判定
	void PawnDisable() { m_Enable = false; } 
	
	// プロパティ
	D3DXVECTOR3 GetVelocity()const { return m_Velocity; }
	void SetVelocity(D3DXVECTOR3 v)
	{
		m_Velocity = v;
	}
	int32_t GetHp() { return m_Hp; }
	void SetHp(int32_t hp) { m_Hp = hp; }

protected:
	__int32 m_AnimFrame;	// アニメーション
	float m_BlendRate;		// アニメーションブレンド
	D3DXVECTOR3 m_Velocity; // 速度
	int32_t m_Hp;  // Hp
	bool m_Enable;			// 生存しているかどうか
	float m_WaitTime;		// 行動できない時間
};

