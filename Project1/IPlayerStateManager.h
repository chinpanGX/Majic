/*-------------------------------------------------------------
	
	[PlayerStateManager.h]
	Author : 出合翔太

	[説明]
	プレイヤーのステートの管理

--------------------------------------------------------------*/
#pragma once
#include <memory>
#include <string>

class IPlayerStateManager
{
public:
	IPlayerStateManager(class Player* p);
	~IPlayerStateManager();	
	template<typename T>
	void SetState()
	{
		T* = new T;
	}
private:
	class SacredBlast* m_SacedBlast;
	class AstralFlare* m_AstralFlare;
	class Apocalypsis* m_Apocalypsis;
	class CrystallizeAura* m_CrystallizeAura;
	class NormalAttack* m_NormalAttack;
	class PlayerGurad* m_Gurad;
	class PlayerWait* m_Wait;
};

#if 0
namespace
{
	const __int32 SkillTypeNum = 4;			// スキルの種類
	const __int32 PatternNum = 3;			// 通常攻撃、スキルのパターンの数
	const __int32 SkillCountUpperLimit = 3; // スキル発動上限回数
	const __int32 NormalTypeNum = 3;		// 通常行動の種類
}

class PlayerStateManager
{
public:
	enum ESkill : int
	{
		E_Skill_1,
		E_Skill_2,
		E_Skill_3,
		E_Skill_4,
		E_Skill_NONE,
	};
	enum Attack : int
	{
		e_Attack_1 = 11,
		E_Attack_2 = 12,
		E_Attack_3 = 13,
		//E_Attack_NONE,
	};
	PlayerStateManager();
	~PlayerStateManager(){}
	void Init(class Player* player);
	void Uninit(class Player* player);
	void Update(class Player* player);
	bool ActiveAttack(__int32 check);
	bool ActiveGurad();
	// スキルの有効にする
	bool ActiveSkill(__int32 check);
private:	
	std::shared_ptr<class StateSwitch> m_State[SkillTypeNum * PatternNum + (NormalTypeNum + PatternNum -1)];	// 登録するステート名[17]
	std::string m_SkillName[SkillTypeNum][PatternNum];						// 登録するスキル名[][]
	std::string m_AttackName[PatternNum];		// 通常攻撃
	std::string m_NormalName[NormalTypeNum - 1];
	__int32 m_Count;	// スキルの発動回
	__int32 m_Type;		// 発動スキルのタイプ
	__int32 m_Pattern;  // 発動スキルのパターン

	// スキルの種類とパターンのチェック
	bool CheckTypeAndCount(__int32 check); 
};

#endif