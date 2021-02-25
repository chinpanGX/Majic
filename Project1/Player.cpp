/*-------------------------------------------------------------

	[Player.cpp]
	Author : èoçá„ƒëæ

---------------------------------------------------------------*/
#include "Player.h"
#include "StateMachine.h"
#include "PlayerController.h"
#include "PlayerStateManager.h"

void Player::Init()
{
	m_StateMachine = std::make_unique<StateMachine>();
	m_Controller = std::make_unique<PlayerController>();
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
