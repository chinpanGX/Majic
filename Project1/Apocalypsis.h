/*----------------------------------------------

	[Apocalypsis.h]
	Author : 出合翔太

	[説明]
	アポカリプスの処理

-----------------------------------------------*/
#pragma once
#include "StateMachine.h"

class Apocalypsis
{
public:
	Apocalypsis(StateMachine& s);
	~Apocalypsis();
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

class ApocalypsisA : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};

class ApocalypsisB : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};

class ApocalypsisC : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};