/*-----------------------------------------------

	[AstralFlare.cpp]
	Author : 出合翔太

	[説明]
	アストラルフレアの処理

------------------------------------------------*/
#include "AstralFlare.h"

AstralFlare::AstralFlare()
{
	m_Count = 0;
	m_EnableThis = true;
	m_Pattern[0] = std::make_unique<AstralFlareA>();
	m_Pattern[1] = std::make_unique<AstralFlareB>();
	m_Pattern[2] = std::make_unique<AstralFlareC>();
}

AstralFlare::~AstralFlare()
{

}

void AstralFlare::Update(Player * p)
{
	IsAttackCountLimit();
	if (m_EnableThis == true)
	{
		m_Pattern[m_Count]->Update(p)
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

void AstralFlareA::Update(Player * p)
{
}

void AstralFlareB::Update(Player * p)
{
}

void AstralFlareC::Update(Player * p)
{
}
