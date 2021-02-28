/*----------------------------------------------

	[Apocalypsis.cpp]
	Author : 出合翔太

	[説明]
	アポカリプスの処理

-----------------------------------------------*/
#include "Apocalypsis.h"

Apocalypsis::Apocalypsis(StateMachine & s) : m_StateMachine(s)
{
	m_Count = 0;
	m_EnableThis = true;
	m_Name[g_CountUpperLimit] = "アポカリプス", "アポカリプス+", "アポカリプス++";
	m_State[0] = std::make_shared<StateSwitch>(std::make_shared<ApocalypsisA>(), m_Name[0]);
	m_State[1] = std::make_shared<StateSwitch>(std::make_shared<ApocalypsisB>(), m_Name[1]);
	m_State[2] = std::make_shared<StateSwitch>(std::make_shared<ApocalypsisC>(), m_Name[2]);
	for (int i = 0; i < g_CountUpperLimit; i++)
	{
		m_StateMachine.Register(m_Name[i], m_State[i]);
	}
}

Apocalypsis::~Apocalypsis()
{
	for (int i = 0; i < g_CountUpperLimit; i++)
	{
		m_StateMachine.Delete(m_Name[i]);
	}
}

void Apocalypsis::Update(Player * player)
{
	IsAttackCountLimit();
	if (m_EnableThis == true)
	{
		m_StateMachine.SetStartState(m_Name[m_Count]);
		m_StateMachine.Update();
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

void ApocalypsisA::Start()
{
}

void ApocalypsisA::Update()
{
}

void ApocalypsisA::ChangeEvent()
{
}

void ApocalypsisB::Start()
{
}

void ApocalypsisB::Update()
{
}

void ApocalypsisB::ChangeEvent()
{
}

void ApocalypsisC::Start()
{
}

void ApocalypsisC::Update()
{
}

void ApocalypsisC::ChangeEvent()
{
}