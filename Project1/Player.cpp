/*-------------------------------------------------------------

	[Player.cpp]
	Author : �o���đ�

---------------------------------------------------------------*/
#include "Player.h"
#include "StateMachine.h"

void Player::Init()
{
	m_StateMachine = std::make_unique<StateMachine>();
}

void Player::Uninit()
{
}

void Player::Update()
{
}

void Player::Draw()
{
}
