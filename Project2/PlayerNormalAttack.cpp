
#include "Player.h"
#include "PlayerEditor.h"
#include "PlayerNormalAttack.h"


NormalAttack::NormalAttack()
{
	m_Count = 0;
	m_EnableThis = true;
	m_Pattern[0] = new PlayerAttackA;
	m_Pattern[1] = new PlayerAttackB;
	m_Pattern[2] = new PlayerAttackC;
}

NormalAttack::~NormalAttack()
{
	delete m_Pattern[2];
	delete m_Pattern[1];
	delete m_Pattern[0];
}

void NormalAttack::Update(const Player& p)
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

void PlayerAttackA::Update(const Player& p)
{
}

void PlayerAttackB::Update(const Player& p)
{
}

void PlayerAttackC::Update(const Player& p)
{
}