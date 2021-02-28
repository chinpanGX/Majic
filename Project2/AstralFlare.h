/*-----------------------------------------------

	[AstralFlare.h]
	Author : 出合翔太

	[説明]
	アストラルフレアの処理

------------------------------------------------*/
#pragma once
#include <memory>
#include "PlayerPattern.h"
#include <vector>

class AstralFlare : public PlayerPatternManager
{
public:
	AstralFlare();
	~AstralFlare();
	void Update(class Player* p)override;
	bool GetEnable() { return m_EnableThis; }
private:
	void IsAttackCountLimit(); // 攻撃回数で有効かどうか調べる
	std::vector<std::unique_ptr<PlayerPattern>> m_Pattern;
};

class AstralFlareA : public PlayerPattern
{
public:
	virtual ~AstralFlareA(){}
	void Update(class Player* p)override;
private:
	const unsigned __int32 m_CostAp = 5;
};

class AstralFlareB : public PlayerPattern
{
public:
	virtual ~AstralFlareB() {}
	void Update(class Player* p)override;
private:
	const unsigned __int32 m_CostAp = 5;
};

class AstralFlareC : public PlayerPattern
{
public:
	virtual ~AstralFlareC() {}
	void Update(class Player* p)override;
private:
	const unsigned __int32 m_CostAp = 5;
};