/*-------------------------------------------------------------

	[Player.h]
	Author : �o���đ�

	[����]
	Player : �v���C���[�̏������܂Ƃ߂�

--------------------------------------------------------------*/
#pragma once
#include "Pawn.h"

class Player : public Pawn
{
public:
	Player(){}
	~Player(){}
	void Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
	/*std::shared_ptr<class IPlayerStateManager> GetPlayerStateManager()const
	{
		return m_State;
	}*/
	std::shared_ptr<class StateMachine> GetStateMachine()const
	{
		return m_StateMachine;
	}
	std::shared_ptr<class PlayerController> GetController()const
	{
		return m_Controller;
	}
	std::shared_ptr<class PlayerEditer> GetEditer()const
	{
		return m_Editer;
	}
	
private:
	std::shared_ptr<class StateMachine> m_StateMachine;
	std::shared_ptr<class PlayerController> m_Controller;
	std::shared_ptr<class PlayerEditer> m_Editer;
};

