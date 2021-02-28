/*----------------------------------------------

	[Apocalypsis.cpp]
	Author : 出合翔太

	[説明]
	アポカリプスの処理

-----------------------------------------------*/
#include "Apocalypsis.h"

Apocalypsis::Apocalypsis()
{
	m_Count = 0;
	m_EnableThis = true;
	m_Pattern[0] = std::make_unique<ApocalypsisA>();
	m_Pattern[1] = std::make_unique<ApocalypsisB>();
	m_Pattern[2] = std::make_unique<ApocalypsisC>();
}

Apocalypsis::~Apocalypsis()
{
	
}

void Apocalypsis::Update(Player * p)
{
	IsAttackCountLimit();
	if (m_EnableThis == true)
	{
		m_Pattern[m_Count]->Update(p);
	}
}

void Apocalypsis::IsAttackCountLimit()
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

void ApocalypsisA::Update(Player * p)
{
}

void ApocalypsisB::Update(Player * p)
{
}

void ApocalypsisC::Update(Player * p)
{
}
