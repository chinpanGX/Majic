/*-----------------------------------------------

	[Pawn.h]
	Author : �o���đ�

	[����]


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
	// ���S����
	void PawnDisable() { m_Enable = false; } 
	
	// �v���p�e�B
	D3DXVECTOR3 GetVelocity()const { return m_Velocity; }
	void SetVelocity(D3DXVECTOR3 v)
	{
		m_Velocity = v;
	}
	int32_t GetHp() { return m_Hp; }
	void SetHp(int32_t hp) { m_Hp = hp; }

protected:
	__int32 m_AnimFrame;	// �A�j���[�V����
	float m_BlendRate;		// �A�j���[�V�����u�����h
	D3DXVECTOR3 m_Velocity; // ���x
	int32_t m_Hp;  // Hp
	bool m_Enable;			// �������Ă��邩�ǂ���
	float m_WaitTime;		// �s���ł��Ȃ�����
};

