/*-------------------------------------------------------------

	[Player.cpp]
	Author : �o���đ�

---------------------------------------------------------------*/
#include "Player.h"
#include "PlayerController.h"

Player::Player() : m_MaxWaitTime(60), m_MaxAp(30), m_Waittime(10), m_ActionPoint(5), m_IsAction(false)
{
}

void Player::Init()
{
	m_Controller = std::make_shared<PlayerController>();
}

void Player::Uninit()
{
}

void Player::Update()
{
	m_Controller->Update(this);
	m_Waittime--;
	// AP���ő�l�𒴂��Ȃ��悤�ɍő�l�ŌŒ�
	if (m_ActionPoint > m_MaxAp)
	{
		m_ActionPoint = m_MaxAp;
	}

	// �҂����Ԃ��ő�l�𒴂��Ȃ��悤�ɍő�l�ŌŒ�
	if (m_Waittime > m_MaxWaitTime)
	{
		m_Waittime = m_MaxWaitTime;
	}

	// �҂����Ԃ�0�ɂȂ�����s���ł���
	if (m_Waittime <= 0)
	{
		m_IsAction = true;
		m_Waittime = 0;
	}
	else
	{
		m_IsAction = false;
	}
}

void Player::Draw()
{
}
