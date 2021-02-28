/*-----------------------------------------------

	[SacredBlast.cpp]
	Author : �o���đ�

------------------------------------------------*/
#include "SacredBlast.h"
#include "Player.h"
#include "PlayerEditor.h"

SacredBlast::SacredBlast()
{
	m_Count = 0;
	m_EnableThis = true;
	m_Pattern[0] = std::make_unique<SacredBlastA>();
	m_Pattern[1] = std::make_unique<SacredBlastB>();
	m_Pattern[2] = std::make_unique<SacredBlastC>();
}

SacredBlast::~SacredBlast()
{
	
}

void SacredBlast::Update(const Player& p)
{
	IsAttackCountLimit();
	if (m_EnableThis == true)
	{
		m_Pattern[m_Count]->Update(p);
	}
}

void SacredBlast::IsAttackCountLimit()
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

void SacredBlastA::Update(const Player& p)
{
	m_tmpAp = p.GetEditer()->GetAp();
	m_tmpAp = m_tmpAp - m_CostAp;
	p.GetEditer()->SetAp(m_tmpAp);
}

void SacredBlastB::Update(const Player& p)
{
	m_tmpAp = p.GetEditer()->GetAp();
	m_tmpAp = m_tmpAp - m_CostAp;
	p.GetEditer()->SetAp(m_tmpAp);
}

void SacredBlastC::Update(const Player& p)
{
	m_tmpAp = p.GetEditer()->GetAp();
	m_tmpAp = m_tmpAp - m_CostAp;
	p.GetEditer()->SetAp(m_tmpAp);
}
