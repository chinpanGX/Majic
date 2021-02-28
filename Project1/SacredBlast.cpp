/*-----------------------------------------------

	[SacredBlast.cpp]
	Author : 出合翔太

------------------------------------------------*/
#include "SacredBlast.h"
#include "Player.h"

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

void SacredBlast::Update(Player * p)
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

void SacredBlastA::Update(Player * p)
{
}

void SacredBlastB::Update(Player * p)
{
}

void SacredBlastC::Update(Player * p)
{
}
