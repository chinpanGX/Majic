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
	void Update(class Player* p)override;
	bool GetEnable() { return m_EnableThis; }
private:
	void IsAttackCountLimit(); // 攻撃回数で有効かどうか調べる
	std::vector<PlayerPattern*> m_Pattern;
};

class ApocalypsisA : public PlayerPattern
{
public:
	virtual ~ApocalypsisA(){}
	void Update(class Player* p)override;
private:
	const int32_t m_CostAp = 5;
};

class ApocalypsisB : public PlayerPattern
{
public:
	virtual ~ApocalypsisB() {}
	void Update(class Player* p)override;
private:
	const int32_t m_CostAp = 5;
};

class ApocalypsisC : public PlayerPattern
{
public:
	virtual ~ApocalypsisC() {}
	void Update(class Player* p)override;
private:
	const int32_t m_CostAp = 5;
};