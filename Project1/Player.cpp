/*-------------------------------------------------------------

	[Player.cpp]
	Author : �o���đ�

---------------------------------------------------------------*/
#include "Player.h"
#include "StateMachine.h"

void Player::Init()
{
	m_StateMachine = new StateMachine;
}

void Player::Uninit()
{
}

void Player::Update()
{
	//m_Controller.Update(this);
}

void Player::Draw()
{
}
