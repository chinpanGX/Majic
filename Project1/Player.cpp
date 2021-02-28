/*-------------------------------------------------------------

	[Player.cpp]
	Author : èoçá„ƒëæ

---------------------------------------------------------------*/
#include "Player.h"
#include "StateMachine.h"
#include "PlayerController.h"
#include "PlayerEditer.h"

void Player::Init()
{
	m_StateMachine = std::make_shared<StateMachine>();
	m_Controller = std::make_shared<PlayerController>(this);
	m_Editer = std::make_shared<PlayerEditer>();
	//m_State = std::make_shared<IPlayerStateManager>(this);
}

void Player::Uninit()
{
}

void Player::Update()
{
	m_Controller->Update(this);
}

void Player::Draw()
{
}
