/*-------------------------------------------------------------

	[PlayerState.cpp]
	Author : 出合翔太

	[説明]
	プレイヤーのステート

-------------------------------------------------------------*/
#include "PlayerState.h"
#include "Player.h"

NormalAttack::NormalAttack()
{
	m_Count = 0;
	m_EnableThis = true;
	m_Pattern[0] = std::make_unique<PlayerAttackA>();
	m_Pattern[1] = std::make_unique<PlayerAttackB>();
	m_Pattern[2] = std::make_unique<PlayerAttackC>();
}

NormalAttack::~NormalAttack()
{
	
}

void NormalAttack::Update(Player * p)
{
	IsAttackCountLimit();
	if (m_EnableThis == true)
	{
		m_Pattern[m_Count]->Update(p);
	}
}

void NormalAttack::IsAttackCountLimit()
{
	if (m_Count > g_CountUpperLimit) // カウントが上限を超えたとき
	{
		m_Count = 0;
		m_EnableThis = false; // 無効にする
	}
	else
	{
		m_EnableThis = true;
		m_Count++;
	}
}

void PlayerAttackA::Update(Player * p)
{
}

void PlayerAttackB::Update(Player * p)
{
}

void PlayerAttackC::Update(Player * p)
{
}

PlayerGurad::PlayerGurad()
{
}

PlayerGurad::~PlayerGurad()
{
}

void PlayerGurad::Update(Player * p)
{
}

void PlayerGuardPattern::Update(Player * p)
{
}

