/*-------------------------------------------------------------

	[PlayerStateManager.cpp]
	Author : 出合翔太

	[説明]
	プレイヤーのステートの管理

--------------------------------------------------------------*/
#include "PlayerStateManager.h"
#include "StateMachine.h"
#include "PlayerSkillState.h"
#include "PlayerState.h"
#include "Player.h"

PlayerStateManager::PlayerStateManager(Player& player) : m_StateMachine(player.GetStateMachine()),
	m_SkillName{ "セイクリッドブラスト", "セイクリッドブラスト+",  "セイクリッドブラスト++",
				 "アストラルフレア",	 "アストラルフレア+",	   "アストラルフレア++",
				 "アポカリプス",		 "アポカリプス+",		   "アポカリプス++",
				 "クリスタライズオーラ", "クリスタライズオーラ+",  "クリスタライズオーラ++" },
	m_AttackName{"攻撃", "攻撃２", "攻撃３"},
	m_NormalName{"ガード","待機"},
	m_Count(0),
	m_Type(0),
	m_Pattern(0)
{
}

void PlayerStateManager::Init()
{
	using namespace std;
	//　セイクリッドブラスト
	m_State[0] = make_shared<StateSwitch>(make_shared<SacredBlastA>(), m_SkillName[0][0]);
	m_State[1] = make_shared<StateSwitch>(make_shared<SacredBlastB>(), m_SkillName[0][1]);
	m_State[2] = make_shared<StateSwitch>(make_shared<SacredBlastC>(), m_SkillName[0][2]);
	// アストラルフレア
	m_State[3] = make_shared<StateSwitch>(make_shared<AstralFlareA>(), m_SkillName[1][0]);
	m_State[4] = make_shared<StateSwitch>(make_shared<AstralFlareB>(), m_SkillName[1][1]);
	m_State[5] = make_shared<StateSwitch>(make_shared<AstralFlareC>(), m_SkillName[1][2]);
	// アポカリプス
	m_State[6] = make_shared<StateSwitch>(make_shared<ApocalypsisA>(), m_SkillName[2][0]);
	m_State[7] = make_shared<StateSwitch>(make_shared<ApocalypsisB>(), m_SkillName[2][1]);
	m_State[8] = make_shared<StateSwitch>(make_shared<ApocalypsisC>(), m_SkillName[2][2]);
	// クリスタライズオーラ
	m_State[9] = make_shared<StateSwitch>(make_shared<CrystallizeAuraA>(), m_SkillName[3][0]);
	m_State[10] = make_shared<StateSwitch>(make_shared<CrystallizeAuraB>(), m_SkillName[3][1]);
	m_State[11] = make_shared<StateSwitch>(make_shared<CrystallizeAuraC>(), m_SkillName[3][2]);
	// 通常攻撃
	m_State[12] = make_shared<StateSwitch>(make_shared<PlayerAttackA>(), m_AttackName[0]);
	m_State[13] = make_shared<StateSwitch>(make_shared<PlayerAttackB>(), m_AttackName[1]);
	m_State[14] = make_shared<StateSwitch>(make_shared<PlayerAttackC>(), m_AttackName[2]);
	// その他
	m_State[15] = make_shared<StateSwitch>(make_shared<PlayerGuard>(), m_NormalName[0]);
	m_State[16] = make_shared<StateSwitch>(make_shared<PlayerWait>(), m_NormalName[1]);

	// レジスタに格納
	__int32 c = 0;
	for (int i = 0; i < SkillTypeNum; i++)
	{
		for (int j = 0; j < PatternNum; j++)
		{
			m_StateMachine.Register(m_SkillName[i][j], m_State[c++]);
		}
	}

	for (int i = 0; i < PatternNum; i++)
	{
		m_StateMachine.Register(m_AttackName[i], m_State[c++]);
	}

	for (int i = 0; i < 2; i++)
	{
		m_StateMachine.Register(m_NormalName[i], m_State[c++]);
	}
}

void PlayerStateManager::Uninit()
{
	m_StateMachine.Delete();
}

void PlayerStateManager::Update()
{
	//m_StateMachine.SetStartState(m_SkillName[Type][Pattern]);
	//m_StateMachine.Update();
}

bool PlayerStateManager::ActiveSkill(__int32 check)
{
	if (CheckTypeAndCount(check) == false)
	{
		m_State[check * 3]->GetState()->SetIsNext(false);
		return false;
	}
	return true;
}

bool PlayerStateManager::CheckTypeAndCount(__int32 check)
{
	bool IsUse = true;
	if (m_Type != check)
	{
		m_Type = check;
		m_Count = 0;
		m_Pattern = 0;
	}
	if (m_Count > SkillCountUpperLimit)
	{
		m_Count = 0;
		IsUse = false;
	}
	if (IsUse == true)
	{
		m_Pattern = m_Count;
		m_Count++;
	}
	return IsUse;
}

