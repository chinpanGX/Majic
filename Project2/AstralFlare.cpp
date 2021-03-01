/*-----------------------------------------------

	[AstralFlare.cpp]
	Author : 出合翔太

	[説明]
	アストラルフレアの処理

------------------------------------------------*/
#include "AstralFlare.h"
#include "Player.h"
#include "PlayerEditor.h"

AstralFlare::AstralFlare()
{
	m_Count = 0;
	m_EnableThis = true;
	m_Pattern[0] = new AstralFlareA;
	m_Pattern[1] = new AstralFlareB;
	m_Pattern[2] = new AstralFlareC;
}

AstralFlare::~AstralFlare()
{
	delete m_Pattern[2];
	delete m_Pattern[1];
	delete m_Pattern[0];
}

void AstralFlare::Update(const Player& p)
{
	IsAttackCountLimit();
	if (m_EnableThis == true)
	{
		m_Pattern[m_Count]->Update(p);
	}
}

void AstralFlare::IsAttackCountLimit()
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

void AstralFlareA::Update(const Player& p)
{
	m_tmpAp = p.GetEditer()->GetAp();
	m_tmpAp = m_tmpAp - m_CostAp;
	p.GetEditer()->SetAp(m_tmpAp);
}

void AstralFlareB::Update(const Player& p)
{
	m_tmpAp = p.GetEditer()->GetAp();
	m_tmpAp = m_tmpAp - m_CostAp;
	p.GetEditer()->SetAp(m_tmpAp);
}

void AstralFlareC::Update(const Player& p)
{
	m_tmpAp = p.GetEditer()->GetAp();
	m_tmpAp = m_tmpAp - m_CostAp;
	p.GetEditer()->SetAp(m_tmpAp);
}
