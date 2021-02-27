/*-----------------------------------------------

	[CrystallizeAura.h]
	Author : 出合翔太

	[説明]
	クリスタライズオーラ

-----------------------------------------------*/
#pragma once
#include "StateMachine.h"
#include "PlayerPattern.h"

class CrystallizeAura : public PlayerPattern
{
public:
	CrystallizeAura(StateMachine& s);
	~CrystallizeAura();
	void Update(Player* player)override;
	void SetActive();
	bool GetEnable() { return m_EnableThis; }
private:
	void IsAttackCountLimit(); // 攻撃回数で有効かどうか調べる
	StateMachine& m_StateMachine;
	std::shared_ptr<StateSwitch> m_State[StateIndex]{};	// 登録するステート名[]
	std::string m_Name[StateIndex]; // 登録名
	unsigned __int32 m_Count;	// 発動回数
	bool m_EnableThis;			// 有効化どうか
};

class CrystallizeAuraA : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};

class CrystallizeAuraB : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};

class CrystallizeAuraC : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};


