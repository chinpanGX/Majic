/*-----------------------------------------------

	[AstralFlare.cpp]
	Author : �o���đ�

	[����]
	�A�X�g�����t���A�̏���

------------------------------------------------*/
#include "AstralFlare.h"

AstralFlare::AstralFlare(StateMachine & s) : m_StateMachine(s)
{
	m_Count = 0;
	m_EnableThis = true;
	m_Name[g_CountUpperLimit] = "�A�X�g�����t���A", "�A�X�g�����t���A+", "�A�X�g�����t���A++";
	m_State[0] = std::make_shared<StateSwitch>(std::make_shared<AstralFlareA>(), m_Name[0]);
	m_State[1] = std::make_shared<StateSwitch>(std::make_shared<AstralFlareB>(), m_Name[1]);
	m_State[2] = std::make_shared<StateSwitch>(std::make_shared<AstralFlareC>(), m_Name[2]);
	for (int i = 0; i < g_CountUpperLimit; i++)
	{
		m_StateMachine.Register(m_Name[i], m_State[i]);
	}
}

AstralFlare::~AstralFlare()
{
	m_StateMachine.Delete();
}

void AstralFlare::SetActive()
{
	IsAttackCountLimit();
	if (m_EnableThis == true)
	{
		m_StateMachine.SetStartState(m_Name[m_Count]);
		m_StateMachine.Update();
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


void AstralFlareA::Start()
{
}

void AstralFlareA::Update()
{
}

void AstralFlareA::ChangeEvent()
{
}

void AstralFlareB::Start()
{
}

void AstralFlareB::Update()
{
}

void AstralFlareB::ChangeEvent()
{
}

void AstralFlareC::Start()
{
}

void AstralFlareC::Update()
{
}

void AstralFlareC::ChangeEvent()
{
}