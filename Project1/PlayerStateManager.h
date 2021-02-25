/*-------------------------------------------------------------
	
	[PlayerStateManager.h]
	Author : 出合翔太

	[説明]
	プレイヤーのステートの管理

--------------------------------------------------------------*/
#pragma once
#include <memory>
#include <string>

namespace
{
	const __int32 SkillTypeNum = 4;			// スキルの種類
	const __int32 SkillPatternNum = 3;		// スキルのパターンの数
	const __int32 SkillCountUpperLimit = 3; // スキル発動上限回数
	const __int32 NurmalStateNum = 2;		// 通常行動
}

class PlayerStateManager
{
public:
	PlayerStateManager();
	~PlayerStateManager(){}
	void Init();
	void Uninit();
	void Update(class Player& p);
private:
	enum : int
	{
		E_Skill_1,
		E_Skill_2,
		E_Skill_3,
		E_Skill_4,
		E_Skill_NONE,
		E_Attack,
		E_Guard,
	};
	std::unique_ptr<class StateMachine> m_StateMachine;
	std::shared_ptr<class StateSwitch> m_State[SkillTypeNum * SkillPatternNum + NurmalStateNum];	// 登録するステート名
	std::string m_SkillName[SkillTypeNum][SkillPatternNum];						// 登録するスキル名[][]
	std::string m_Name[2]; // 通常行動
	__int32 m_Count;	// スキルの発動回
	__int32 m_Type;		// 発動スキルのタイプ
	__int32 m_Pattern;  // 発動スキルのパターン
};

