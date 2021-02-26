/*----------------------------------------------
	
	[Config.h]
	Author : 出合翔太

	[説明]
	グローバル変数の管理

-----------------------------------------------*/
#pragma once
#include "StateMachine.h"

namespace
{
	const unsigned __int32 g_CountUpperLimit = 2; // ステートのカウント上限
}

class IPlayerStatePattern : public StateBase
{
public:
	IPlayerStatePattern() {}
	virtual ~IPlayerStatePattern(){}
	virtual void Update(class Player* pPlayer) = 0;
};

class IPlayerState
{
public:
	IPlayerState(){}
	virtual ~IPlayerState(){}
	virtual void SetActive() = 0;
	bool GetEnable() { return m_EnableThis; }
protected:
	std::shared_ptr<StateSwitch> m_State[g_CountUpperLimit];	// 登録するステート名[]
	std::string m_Name[g_CountUpperLimit]; // 登録名
	unsigned __int32 m_Count;	// 発動回数
	bool m_EnableThis;			// 有効化どうか
};