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
	const unsigned __int32 g_CountUpperLimit = 3; // ステートのカウント上限
}

class IStateConfig
{
public:
	IStateConfig(){}
	virtual ~IStateConfig(){}
	virtual void SetActive() = 0;
protected:
	std::shared_ptr<StateSwitch> m_State[g_CountUpperLimit];	// 登録するステート名[]
	std::string m_Name[g_CountUpperLimit]; // 登録名
	unsigned __int32 m_Count;	// 発動回数
	bool m_EnableThis;			// 有効化どうか
};