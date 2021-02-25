/*-------------------------------------------------------------

	[Player.h]
	Author : �o���đ�

	[����]
	Player : �v���C���[�̏������܂Ƃ߂�

--------------------------------------------------------------*/
#pragma once
#include "Pawn.h"
#include "StateMachine.h"
#include "PlayerStateManager.h"

class Player : public Pawn
{
public:
	void Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
	PlayerStateManager& GetPlayerStateManager()const
	{
		return *m_State;
	}
	StateMachine& GetStateMachine()const
	{
		return *m_StateMachine;
	}
private:
	class StateMachine* m_StateMachine;
	class PlayerController* m_Controller;
	class PlayerStateManager* m_State;
	unsigned __int32 m_ActionPoint; // Ap->�X�L���ŏ���
};

