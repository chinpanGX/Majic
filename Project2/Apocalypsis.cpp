/*----------------------------------------------

	[Apocalypsis.cpp]
	Author : 出合翔太

	[説明]
	アポカリプスの処理

-----------------------------------------------*/
#include "Apocalypsis.h"
#include "Player.h"

Apocalypsis::Apocalypsis()
{
	m_Count = 0;
	m_EnableThis = true;
	m_Pattern[0] = new ApocalypsisA;
	m_Pattern[1] = new ApocalypsisB;
	m_Pattern[2] = new ApocalypsisC;
}

Apocalypsis::~Apocalypsis()
{
	delete m_Pattern[2];
	delete m_Pattern[1];
	delete m_Pattern[0];
}

void Apocalypsis::Update(Player* p)
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

void ApocalypsisA::Update(Player* p)
{
	p->AP_Comsume(m_CostAp);
}

void ApocalypsisB::Update(Player* p)
{
	p->AP_Comsume(m_CostAp);
}

void ApocalypsisC::Update(Player* p)
{
	p->AP_Comsume(m_CostAp);
}
