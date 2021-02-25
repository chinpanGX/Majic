/*-------------------------------------------------------------

	[PlayerStateManager.cpp]
	Author : 出合翔太

	[説明]
	プレイヤーのステートの管理

--------------------------------------------------------------*/
#include "PlayerStateManager.h"
#include "StateMachine.h"

PlayerStateManager::PlayerStateManager() : m_StateMachine(std::make_unique<StateMachine>()),
	m_SkillName{ "セイクリッドブラスト", "セイクリッドブラスト+",  "セイクリッドブラスト++",
				 "アストラルフレア",	 "アストラルフレア+",	   "アストラルフレア++",
				 "アポカリプス",		 "アポカリプス+",		   "アポカリプス++",
				 "クリスタライズオーラ", "クリスタライズオーラ+",  "クリスタライズオーラ++" },
	m_Name{"攻撃","ガード"},
	m_Count(0),
	m_Type(0),
	m_Pattern(0)
{
}

void PlayerStateManager::Init()
{
}

void PlayerStateManager::Uninit()
{
	m_StateMachine->Delete;
}

void PlayerStateManager::Update(Player & p)
{
}
