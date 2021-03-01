
#include "Player.h"
#include "PlayerNormalAttack.h"


NormalAttack::NormalAttack()
{
	m_Count = 0;
	m_EnableThis = true;
	m_Pattern = std::make_unique<PlayerAttackA>(3);
}

NormalAttack::~NormalAttack()
{

}

void NormalAttack::Update(Player* p)
{
	IsAttackCountLimit(p);
	if (m_EnableThis == true)
	{
		m_Pattern->Update(p);
	}
}

void NormalAttack::IsAttackCountLimit(Player* p)
{
	if (m_Count > g_CountUpperLimit) // �J�E���g������𒴂����Ƃ�
	{
		m_Count = 0;
		m_EnableThis = false; // �����ɂ���
	}
	else
	{
		if (m_Count == 2)
		{
			m_Pattern = std::make_unique<PlayerAttackB>(3);
		}
		else if(m_Count == 3)
		{
			m_Pattern = std::make_unique<PlayerAttackC>(3);
		}
		m_EnableThis = true;
		m_Count++;
	}
}

void PlayerAttackA::Update(Player* p)
{
	p->Ap_Add(m_AddAp);
}

void PlayerAttackB::Update(Player* p)
{
	p->Ap_Add(m_AddAp);
}

void PlayerAttackC::Update(Player* p)
{
	p->Ap_Add(m_AddAp);
	p->WaitTime_Add(5);
}