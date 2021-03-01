/*----------------------------------------------

	[Apocalypsis.h]
	Author : 出合翔太

	[説明]
	アポカリプスの処理

-----------------------------------------------*/
#pragma once
#include <memory>
#include "PlayerPattern.h"
#include <vector>

class Apocalypsis : public PlayerPatternManager
{
public:
	Apocalypsis();
	~Apocalypsis();
	void Update(const class Player& p)override;
	bool GetEnable() { return m_EnableThis; }
private:
	void IsAttackCountLimit(); // 攻撃回数で有効かどうか調べる
	std::vector<PlayerPattern*> m_Pattern;
};

class ApocalypsisA : public PlayerPattern
{
public:
	virtual ~ApocalypsisA(){}
	void Update(const class Player& p)override;
private:
	const unsigned __int32 m_CostAp = 5;
};

class ApocalypsisB : public PlayerPattern
{
public:
	virtual ~ApocalypsisB() {}
	void Update(const class Player& p)override;
private:
	const unsigned __int32 m_CostAp = 5;
};

class ApocalypsisC : public PlayerPattern
{
public:
	virtual ~ApocalypsisC() {}
	void Update(const class Player& p)override;
private:
	const unsigned __int32 m_CostAp = 5;
};