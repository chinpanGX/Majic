/*-----------------------------------------------

	[SacredBlast.cpp]
	Author : 出合翔太

------------------------------------------------*/
#include "SacredBlast.h"
#include "Player.h"
#include "PlayerEditor.h"

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
