/*-----------------------------------------------

	[CrystallizeAura.h]
	Author : 出合翔太

	[説明]
	クリスタライズオーラ

-----------------------------------------------*/
#pragma once
#include <memory>
#include "PlayerPattern.h"
#include <vector>

class CrystallizeAura : public PlayerPatternManager
{
public:
	CrystallizeAura();
	~CrystallizeAura();
	void Update(const class Player& p)override;
	bool GetEnable() { return m_EnableThis; }
private:
	void IsAttackCountLimit(); // 攻撃回数で有効かどうか調べる
	std::vector<std::unique_ptr<PlayerPattern>> m_Pattern;
};

class CrystallizeAuraA : public PlayerPattern
{
public:
	virtual ~CrystallizeAuraA(){}
	void Update(const class Player& p)override;
private:
	const unsigned __int32 m_CostAp = 5;
};

class CrystallizeAuraB : public PlayerPattern
{
public:
	virtual ~CrystallizeAuraB() {}
	void Update(const class Player& p)override;
private:
	const unsigned __int32 m_CostAp = 5;
};

class CrystallizeAuraC : public PlayerPattern
{
public:
	virtual ~CrystallizeAuraC() {}
	void Update(const class Player& p)override;
private:
	const unsigned __int32 m_CostAp = 5;
};


