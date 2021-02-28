/*----------------------------------------------

	[Apocalypsis.h]
	Author : 出合翔太

	[説明]
	アポカリプスの処理

-----------------------------------------------*/
#pragma once
#include <memory>
#include "PlayerPattern.h"

class Apocalypsis : public PlayerPatternManager
{
public:
	Apocalypsis();
	~Apocalypsis();
	void Update(Player* p)override;
	bool GetEnable() { return m_EnableThis; }
private:
	void IsAttackCountLimit(); // 攻撃回数で有効かどうか調べる
	std::unique_ptr<PlayerPattern> m_Pattern[g_StateIndex];
};

class ApocalypsisA : public PlayerPattern
{
public:
	virtual ~ApocalypsisA(){}
	void Update(class Player* p)override;
};

class ApocalypsisB : public PlayerPattern
{
public:
	virtual ~ApocalypsisB() {}
	void Update(class Player* p)override;
};

class ApocalypsisC : public PlayerPattern
{
public:
	virtual ~ApocalypsisC() {}
	void Update(class Player* p)override;
};