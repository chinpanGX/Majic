/*-----------------------------------------------

	[AstralFlare.h]
	Author : 出合翔太

	[説明]
	アストラルフレアの処理

------------------------------------------------*/
#pragma once
#include "PlayerPattern.h"

class AstralFlare : public PlayerPattern
{
public:
	AstralFlare(StateMachine& s);
	~AstralFlare();
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

class AstralFlareA : public PlayerPattern
{
public:
	virtual ~AstralFlareA(){}
	void Update(class Player* p)override;
};

class AstralFlareB : public PlayerPattern
{
public:
	virtual ~AstralFlareB() {}
	void Update(class Player* p)override;
};

class AstralFlareC : public PlayerPattern
{
public:
	virtual ~AstralFlareC() {}
	void Update(class Player* p)override;
};