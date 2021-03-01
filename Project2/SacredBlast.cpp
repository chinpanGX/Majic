/*-----------------------------------------------

	[SacredBlast.cpp]
	Author : �o���đ�

------------------------------------------------*/
#include "SacredBlast.h"
#include "Player.h"

SacredBlast::SacredBlast()
{
	m_Count = 0;
	m_EnableThis = true;
	m_Pattern[0] = new SacredBlastA;
	m_Pattern[1] = new SacredBlastB;
	m_Pattern[2] = new SacredBlastC;
}

SacredBlast::~SacredBlast()
{
	delete m_Pattern[2];
	delete m_Pattern[1];
	delete m_Pattern[0];
}

void SacredBlast::Update(Player* p)
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

void SacredBlastA::Update(Player* p)
{
	p->AP_Comsume(m_CostAp);
}

void SacredBlastB::Update(Player* p)
{
	p->AP_Comsume(m_CostAp);
}

void SacredBlastC::Update(Player* p)
{
	p->AP_Comsume(m_CostAp);

}
