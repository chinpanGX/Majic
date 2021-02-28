/*-------------------------------------------------------------

	[PlayerState.cpp]
	Author : 出合翔太

	[説明]
	プレイヤーのステート

-------------------------------------------------------------*/
#include "PlayerState.h"
#include "Player.h"

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
	for (int i = 0; i < g_CountUpperLimit; i++)
	{
		m_StateMachine.Delete(m_Name[i]);
	}
}

void NormalAttack::Update(Player * player)
{
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

PlayerGurad::PlayerGurad(StateMachine & s) : m_StateMachine(s)
{
	m_State = std::make_shared<StateSwitch>(std::make_shared<PlayerGuardPattern>(), "ガード");
	m_StateMachine.Register("ガード", m_State);
}

PlayerGurad::~PlayerGurad()
{
	m_StateMachine.Delete("ガード");
}

void PlayerGurad::Update(Player * player)
{
}

void PlayerAttackA::Start()
{
}

void PlayerAttackA::Update(Pawn * p)
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

void PlayerAttackB::Update(Pawn * p)
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

void PlayerAttackC::Update(Pawn * p)
{
}

void PlayerAttackC::Update()
{
}


void PlayerAttackC::ChangeEvent()
{
}

void PlayerGuardPattern::Start()
{
}

void PlayerGuardPattern::Update(Pawn * p)
{
}

void PlayerGuardPattern::Update()
{
}

void PlayerGuardPattern::ChangeEvent()
{
}

void PlayerAttackA::Update(Player * p)
{
}

void PlayerAttackB::Update(Player * p)
{
}

void PlayerAttackC::Update(Player * p)
{
}
