/*-----------------------------------------------

	[SacredBlast.cpp]
	Author : �o���đ�

------------------------------------------------*/
#include "SacredBlast.h"

SacredBlast::SacredBlast(StateMachine & s) : m_StateMachine(s)
{
	m_Count = 0;
	m_EnableThis = true;
	m_Name[g_CountUpperLimit] = "�Z�C�N���b�h�u���X�g", "�Z�C�N���b�h�u���X�g+", "�Z�C�N���b�h�u���X�g++";
	m_State[0] = std::make_shared<StateSwitch>(std::make_shared<SacredBlastA>(), m_Name[0]);
	m_State[1] = std::make_shared<StateSwitch>(std::make_shared<SacredBlastB>(), m_Name[1]);
	m_State[2] = std::make_shared<StateSwitch>(std::make_shared<SacredBlastC>(), m_Name[2]);
	for (int i = 0; i < g_CountUpperLimit; i++)
	{
		m_StateMachine.Register(m_Name[i], m_State[i]);
	}
}

SacredBlast::~SacredBlast()
{
	m_StateMachine.Delete();
}

void SacredBlast::Update(Player * player)
{
}

void SacredBlast::SetActive()
{
	IsAttackCountLimit();
	if (m_EnableThis == true)
	{
		m_StateMachine.SetStartState(m_Name[m_Count]);
		m_StateMachine.Update();
	}
}

void SacredBlast::IsAttackCountLimit()
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


void SacredBlastA::Start()
{
}

void SacredBlastA::Update()
{
}

void SacredBlastA::ChangeEvent()
{
}

void SacredBlastB::Start()
{
}

void SacredBlastB::Update()
{
}

void SacredBlastB::ChangeEvent()
{
}

void SacredBlastC::Start()
{
}

void SacredBlastC::Update()
{
}

void SacredBlastC::ChangeEvent()
{
}