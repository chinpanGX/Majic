/*-------------------------------------------------------------

	[Player.cpp]
	Author : 出合翔太

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
	// APが最大値を超えないように最大値で固定
	if (m_ActionPoint > m_MaxAp)
	{
		m_ActionPoint = m_MaxAp;
	}

	// 待ち時間が最大値を超えないように最大値で固定
	if (m_Waittime > m_MaxWaitTime)
	{
		m_Waittime = m_MaxWaitTime;
	}

	// 待ち時間が0になったら行動できる
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
