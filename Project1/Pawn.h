/*-----------------------------------------------

	[Pawn.h]
	Author : �o���đ�

	[����]


-----------------------------------------------*/
#pragma once
#include "GameObject.h"
#include "StateMachine.h"

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
	__int32 m_AnimFrame;	// �A�j���[�V����
	float m_BlendRate;		// �A�j���[�V�����u�����h
	D3DXVECTOR3 m_Velocity; // ���x
};

