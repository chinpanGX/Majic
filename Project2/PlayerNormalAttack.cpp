
#include "Player.h"
#include "PlayerEditor.h"
#include "PlayerNormalAttack.h"


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
	if (m_Count > g_CountUpperLimit) // ƒJƒEƒ“ƒg‚ªãŒÀ‚ğ’´‚¦‚½‚Æ‚«
	{
		m_Count = 0;
		m_EnableThis = false; // –³Œø‚É‚·‚é
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