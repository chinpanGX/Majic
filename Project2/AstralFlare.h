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
	void Update(class Player* p)override;
	bool GetEnable() { return m_EnableThis; }
private:
	void IsAttackCountLimit(); // 攻撃回数で有効かどうか調べる
	template<typename T>
	void SetPattern(__int32 ap);

	__int32 m_tmpApCost; // 消費するAPを一時保存
	std::unique_ptr<PlayerPattern> m_Pattern;
};

class AstralFlareA : public PlayerPattern
{
public:
	AstralFlareA() : m_CostAp(0){}
	AstralFlareA(__int32 ap) : m_CostAp(ap) {}
	virtual ~AstralFlareA(){}
	void Update(class Player* p)override;
private:
	const __int32 m_CostAp;
};

class AstralFlareB : public PlayerPattern
{
public:
	AstralFlareB() : m_CostAp(0) {}
	AstralFlareB(__int32 ap) : m_CostAp(ap) {}
	virtual ~AstralFlareB() {}
	void Update(class Player* p)override;
private:
	const __int32 m_CostAp;
};

class AstralFlareC : public PlayerPattern
{
public:
	AstralFlareC() : m_CostAp(0) {}
	AstralFlareC(__int32 ap) : m_CostAp(ap) {}
	virtual ~AstralFlareC() {}
	void Update(class Player* p)override;
private:
	const __int32 m_CostAp;
};

