/*-----------------------------------------------
	
	[PlayerState.h]
	Author : 出合翔太

------------------------------------------------*/
#pragma once

namespace
{
	const __int32 g_StateIndex = 3; // ステートの配列の数ウント上限
	const __int32 g_CountUpperLimit = 3; // ステートのカ
}

class PlayerPatternManager
{
public:
	virtual ~PlayerPatternManager(){}
	virtual void Update(class Player* p) = 0;
	bool GetEnable() { return m_EnableThis; }
protected:
	__int32 m_Count;	// 発動回数
	bool m_EnableThis;			// 有効化どうか
};

class PlayerPattern
{
public:
	virtual ~PlayerPattern() {}
	virtual void Update(class Player* p) = 0;
protected:
};

class PlayerPatternNone : public PlayerPattern
{
public:
	virtual ~PlayerPatternNone(){}
	virtual void Update(class Player* p)override{}
};
