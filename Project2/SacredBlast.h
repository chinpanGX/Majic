/*-----------------------------------------------

	[SacredBlast.h]
	Author : 出合翔太

	[説明]
	スキル：セイクリッドブラストの処理

------------------------------------------------*/
#pragma once
#include <memory>
#include "PlayerPattern.h"
#include <vector>

class SacredBlast : public PlayerPatternManager

{
public:
	SacredBlast();
	~SacredBlast();
	void Update(class Player* player)override;
	bool GetEnable() { return m_EnableThis; }
private:
	void IsAttackCountLimit(); // 攻撃回数で有効かどうか調べる
	std::vector<PlayerPattern*> m_Pattern;
};

class SacredBlastA : public PlayerPattern
{
public:
	virtual ~SacredBlastA(){}
	void Update(class Player* p)override;
private:
	const int32_t m_CostAp = 5;
};

class SacredBlastB : public PlayerPattern
{
public:
	virtual ~SacredBlastB() {}
	void Update(class Player* p)override;
private:
	const int32_t m_CostAp = 5;
};

class SacredBlastC : public PlayerPattern
{
public:
	virtual ~SacredBlastC() {}
	void Update(class Player* p)override;
private:
	const int32_t m_CostAp = 5;
};