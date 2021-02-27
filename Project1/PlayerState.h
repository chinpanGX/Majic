/*-------------------------------------------------------------

	[PlayerState.h]
	Author : 出合翔太

	[説明]
	プレイヤーのステート

-------------------------------------------------------------*/
#pragma once
#include "StateMachine.h"
#include "PlayerPattern.h"

class Player;

class NormalAttack : public PlayerPattern
{
public:
	NormalAttack(StateMachine& s);
	~NormalAttack();
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

class PlayerGurad : public PlayerPattern
{
public:
	PlayerGurad(StateMachine& s);
	~PlayerGurad();
	void Update(Player* player);
private:
	StateMachine& m_StateMachine;
};

class PlayerWait : public PlayerPattern
{
public:
	PlayerWait(StateMachine& s);
	~PlayerWait();
	void Update(Player* player)override;
	unsigned __int32 GetWaitTime()
	{
		return m_Waittime;
	}
	void SetWaitTime(unsigned __int32 time)
	{
		m_Waittime = time;
	}
private:
	StateMachine& m_StateMachine;
	unsigned __int32 m_Waittime;
};


class PlayerAttackA : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};

class PlayerAttackB : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};

class PlayerAttackC : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};

class PlayerGuardPattern : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};

class PlayerWaitPattern : public StateBase 
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};