/*-----------------------------------------------

	[AstralFlare.cpp]
	Author : �o���đ�

	[����]
	�A�X�g�����t���A�̏���

------------------------------------------------*/
#include "AstralFlare.h"
#include "Player.h"
#include "PlayerEditor.h"

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
