/*-----------------------------------------------

	[AstralFlare.cpp]
	Author : �o���đ�

	[����]
	�A�X�g�����t���A�̏���

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

void AstralFlareA::Update(Player * p)
{
}

void AstralFlareB::Update(Player * p)
{
}

void AstralFlareC::Update(Player * p)
{
}
