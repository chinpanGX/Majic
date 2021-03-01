/*-----------------------------------------------

	[CrystallizeAura.cpp]
	Author : 出合翔太

	[説明]
	クリスタライズオーラ

-----------------------------------------------*/
#include "CrystallizeAura.h"
#include "Player.h"

CrystallizeAura::CrystallizeAura()
{
	m_Count = 0;
	m_EnableThis = true;
	m_Pattern[0] = new CrystallizeAuraA;
	m_Pattern[1] = new CrystallizeAuraB;
	m_Pattern[2] = new CrystallizeAuraC;
}

CrystallizeAura::~CrystallizeAura()
{
	delete m_Pattern[2];
	delete m_Pattern[1];
	delete m_Pattern[0];
}

void CrystallizeAura::Update(Player* p)
{
	IsAttackCountLimit();
	if (m_EnableThis == true)
	{
		m_Pattern[m_Count]->Update(p);
	}
}

void CrystallizeAura::IsAttackCountLimit()
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

void CrystallizeAuraA::Update(Player* p)
{
	p->AP_Comsume(m_CostAp);
}

void CrystallizeAuraB::Update(Player* p)
{
	p->AP_Comsume(m_CostAp);
}

void CrystallizeAuraC::Update(Player* p)
{
	p->AP_Comsume(m_CostAp);
}
