/*-----------------------------------------------

	[SacredBlast.cpp]
	Author : 出合翔太

------------------------------------------------*/
#include "SacredBlast.h"
#include "Player.h"

SacredBlast::SacredBlast(StateMachine & s) : m_StateMachine(s)
{
	m_Count = 0;
	m_EnableThis = true;
	m_Name[g_CountUpperLimit] = "セイクリッドブラスト", "セイクリッドブラスト+", "セイクリッドブラスト++";
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
	for (int i = 0; i < g_CountUpperLimit; i++)
	{
		m_StateMachine.Delete(m_Name[i]);
	}
}

void SacredBlast::Update(Player * player)
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


void SacredBlastA::Start()
{
	
}

void SacredBlastA::Update()
{
	m_IsNext = true;

}

void SacredBlastA::ChangeEvent()
{
	m_IsNext = false;
}

void SacredBlastB::Start()
{
}

void SacredBlastB::Update()
{
	m_IsNext = true;
}

void SacredBlastB::ChangeEvent()
{
	m_IsNext = false;
}

void SacredBlastC::Start()
{
}

void SacredBlastC::Update()
{
	m_IsNext = true;
}

void SacredBlastC::ChangeEvent()
{
	m_IsNext = false;
}