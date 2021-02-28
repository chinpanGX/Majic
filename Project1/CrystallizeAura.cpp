/*-----------------------------------------------

	[CrystallizeAura.cpp]
	Author : �o���đ�

	[����]
	�N���X�^���C�Y�I�[��

-----------------------------------------------*/
#include "CrystallizeAura.h"
#include "PlayerEditer.h"
#include "Player.h"

CrystallizeAura::CrystallizeAura()
{
	m_Count = 0;
	m_EnableThis = true;
	m_Pattern[0] = std::make_unique<CrystallizeAuraA>();
	m_Pattern[1] = std::make_unique<CrystallizeAuraB>();
	m_Pattern[2] = std::make_unique<CrystallizeAuraC>();
}

CrystallizeAura::~CrystallizeAura()
{

}

void CrystallizeAura::Update(Player * p)
{
	IsAttackCountLimit();
	if (m_EnableThis == true)
	{
		m_Pattern[m_Count]->Update(p);
	}
}

void CrystallizeAura::IsAttackCountLimit()
{
	if (m_Count > g_CountUpperLimit) // �J�E���g������𒴂����Ƃ�
	{
		m_Count = 0;
		m_EnableThis = false; // �����ɂ���
	}
	else
	{
		m_EnableThis = true;
		m_Count++;
	}
}

void CrystallizeAuraA::Update(Player * p)
{
	m_tmpAp = p->GetEditer()->GetAp();
	m_tmpAp = m_tmpAp - m_CostAp;
	p->GetEditer()->SetAp(m_tmpAp);
}

void CrystallizeAuraB::Update(Player * p)
{
	m_tmpAp = p->GetEditer()->GetAp();
	m_tmpAp = m_tmpAp - m_CostAp;
	p->GetEditer()->SetAp(m_tmpAp);
}

void CrystallizeAuraC::Update(Player * p)
{
	m_tmpAp = p->GetEditer()->GetAp();
	m_tmpAp = m_tmpAp - m_CostAp;
	p->GetEditer()->SetAp(m_tmpAp);
}
