/*-----------------------------------------------

	[CrystallizeAura.cpp]
	Author : �o���đ�

	[����]
	�N���X�^���C�Y�I�[��

-----------------------------------------------*/
#include "CrystallizeAura.h"

CrystallizeAura::CrystallizeAura(StateMachine & s) : m_StateMachine(s)
{
	m_Count = 0;
	m_EnableThis = true;
	m_Name[g_CountUpperLimit] = "�N���X�^���C�Y�I�[��", "�N���X�^���C�Y�I�[��+", "�N���X�^���C�Y�I�[��++";
	m_State[0] = std::make_shared<StateSwitch>(std::make_shared<CrystallizeAuraA>(), m_Name[0]);
	m_State[1] = std::make_shared<StateSwitch>(std::make_shared<CrystallizeAuraB>(), m_Name[1]);
	m_State[2] = std::make_shared<StateSwitch>(std::make_shared<CrystallizeAuraC>(), m_Name[2]);
	for (int i = 0; i < g_CountUpperLimit; i++)
	{
		m_StateMachine.Register(m_Name[i], m_State[i]);
	}
}

CrystallizeAura::~CrystallizeAura()
{
	m_StateMachine.Delete();
}

void CrystallizeAura::Update(Player * player)
{
}

void CrystallizeAura::SetActive()
{
	IsAttackCountLimit();
	if (m_EnableThis == true)
	{
		m_StateMachine.SetStartState(m_Name[m_Count]);
		m_StateMachine.Update();
	}
}

void CrystallizeAura::IsAttackCountLimit()
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

void CrystallizeAuraA::Start()
{
}

void CrystallizeAuraA::Update()
{
}

void CrystallizeAuraA::ChangeEvent()
{
}

void CrystallizeAuraB::Start()
{
}

void CrystallizeAuraB::Update()
{
}

void CrystallizeAuraB::ChangeEvent()
{
}

void CrystallizeAuraC::Start()
{
}

void CrystallizeAuraC::Update()
{
}

void CrystallizeAuraC::ChangeEvent()
{
}
