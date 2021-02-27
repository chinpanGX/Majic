/*-------------------------------------------------------------

	[Player.h]
	Author : 出合翔太

	[説明]
	Player : プレイヤーの処理をまとめる

--------------------------------------------------------------*/
#pragma once
#include "Pawn.h"

class Player : public Pawn
{
public:
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
private:
	std::shared_ptr<class StateMachine> m_StateMachine;
	std::shared_ptr<class PlayerController> m_Controller;
	//std::shared_ptr<class IPlayerStateManager> m_State;
	unsigned __int32 m_ActionPoint; // Ap->スキルで消費
};

