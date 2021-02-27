/*-----------------------------------------------

	[AstralFlare.h]
	Author : 出合翔太

	[説明]
	アストラルフレアの処理

------------------------------------------------*/
#pragma once
#include "StateMachine.h"
#include "PlayerPattern.h"

class AstralFlare : public PlayerPattern
{
public:
	AstralFlare(StateMachine& s);
	~AstralFlare();
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

class AstralFlareA : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};

class AstralFlareB : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};

class AstralFlareC : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};