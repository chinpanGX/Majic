/*-----------------------------------------------

	[CrystallizeAura.h]
	Author : 出合翔太

	[説明]
	クリスタライズオーラ

-----------------------------------------------*/
#pragma once
#include "PlayerPattern.h"

class CrystallizeAura : public PlayerPattern
{
public:
	CrystallizeAura(StateMachine& s);
	~CrystallizeAura();
	void Update(Player* player)override;
	bool GetEnable() { return m_EnableThis; }
private:
	void IsAttackCountLimit(); // 攻撃回数で有効かどうか調べる
	StateMachine& m_StateMachine;
	std::shared_ptr<StateSwitch> m_State[StateIndex]{};	// 登録するステート名[]
	std::string m_Name[StateIndex]; // 登録名
	unsigned __int32 m_Count;	// 発動回数
	bool m_EnableThis;			// 有効化どうか
};

class CrystallizeAuraA : public PlayerPattern
{
public:
	virtual ~CrystallizeAuraA(){}
	void Update(class Player* p)override;
};

class CrystallizeAuraB : public PlayerPattern
{
public:
	virtual ~CrystallizeAuraB() {}
	void Update(class Player* p)override;
};

class CrystallizeAuraC : public PlayerPattern
{
public:
	virtual ~CrystallizeAuraC() {}
	void Update(class Player* p)override;
};


