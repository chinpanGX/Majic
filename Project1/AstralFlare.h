/*-----------------------------------------------

	[AstralFlare.h]
	Author : 出合翔太

	[説明]
	アストラルフレアの処理

------------------------------------------------*/
#pragma once
#include <memory>
#include "PlayerPattern.h"

class AstralFlare : public PlayerPatternManager
{
public:
	AstralFlare();
	~AstralFlare();
	void Update(Player* p)override;
	bool GetEnable() { return m_EnableThis; }
private:
	void IsAttackCountLimit(); // 攻撃回数で有効かどうか調べる
	std::unique_ptr<PlayerPattern> m_Pattern[g_StateIndex];
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