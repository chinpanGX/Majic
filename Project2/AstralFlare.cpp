/*-----------------------------------------------

	[AstralFlare.cpp]
	Author : �o���đ�

	[����]
	�A�X�g�����t���A�̏���

------------------------------------------------*/
#include "AstralFlare.h"
#include "Player.h"

int g_CallCount = 100;

AstralFlare::AstralFlare()
{
	m_Count = 0;
	m_EnableThis = true;
	m_Pattern = std::make_unique<AstralFlareA>(5);
}

AstralFlare::~AstralFlare()
{
	
}

void AstralFlare::Update(Player* p)
{
	IsAttackCountLimit();
	if (m_EnableThis == true)
	{
		switch (m_Count)
		{
		case 2:
			auto tmp = m_Pattern.release();
			delete tmp;
			// AP�������AP�������Ȃ��Ƃ��A�X�L���͎g�p�ł��Ȃ�
			if (m_tmpApCost >= p->GetAp())
			{
				m_EnableThis = false;
				break;
			}
			else
			{
				SetPattern<AstralFlareB>(5);
				m_Pattern->Update(p);
				break;
			}
			break;
		case 3:
			SetPattern<AstralFlareC>(5);
			break;
		}
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
		m_Count++;
	}
}

template<typename T>
void AstralFlare::SetPattern(__int32 ap)
{
	m_Pattern = std::make_unique<T>();
	m_EnableThis = true;
}


void AstralFlareA::Update(Player* p)
{
	p->AP_Comsume(m_CostAp);
}

void AstralFlareB::Update(Player* p)
{
	p->AP_Comsume(m_CostAp);
}

void AstralFlareC::Update(Player* p)
{
	p->AP_Comsume(m_CostAp);
}
