/*-------------------------------------------------------------

	[PlayerState.cpp]
	Author : 出合翔太

	[説明]
	プレイヤーのステート

-------------------------------------------------------------*/
#include "PlayerState.h"

NormalAttack::NormalAttack(StateMachine& s) : m_StateMachine(s)
{
	m_Count = 0;
	m_EnableThis = true;
	m_Name[g_CountUpperLimit] = "攻撃", "攻撃+", "攻撃++";
	m_State[0] = std::make_shared<StateSwitch>(std::make_shared<PlayerAttackA>(),m_Name[0]);
	m_State[1] = std::make_shared<StateSwitch>(std::make_shared<PlayerAttackB>(), m_Name[1]);
	m_State[2] = std::make_shared<StateSwitch>(std::make_shared<PlayerAttackC>(), m_Name[2]);
	for (int i = 0; i < g_CountUpperLimit; i++)
	{
		m_StateMachine.Register(m_Name[i], m_State[i]);
	}
}

NormalAttack::~NormalAttack()
{
	m_StateMachine.Delete();
}

void NormalAttack::SetActive()
{
	IsAttackCountLimit();
	if (m_EnableThis == true)
	{
		m_StateMachine.SetStartState(m_Name[m_Count]);
		m_StateMachine.Update();
	}
}

void NormalAttack::IsAttackCountLimit()
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


void PlayerAttackA::Start()
{
}

void PlayerAttackA::Update()
{
}

void PlayerAttackA::ChangeEvent()
{
}

void PlayerAttackB::Start()
{
}

void PlayerAttackB::Update()
{
}

void PlayerAttackB::ChangeEvent()
{
}

void PlayerAttackC::Start()
{
}

void PlayerAttackC::Update()
{
}

void PlayerAttackC::ChangeEvent()
{
}

void PlayerGuard::Start()
{
}

void PlayerGuard::Update()
{
}

void PlayerGuard::ChangeEvent()
{
}

void PlayerWait::Start()
{
}

void PlayerWait::Update()
{
}

void PlayerWait::ChangeEvent()
{
}