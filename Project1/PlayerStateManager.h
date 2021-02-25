/*-------------------------------------------------------------
	
	[PlayerStateManager.h]
	Author : �o���đ�

	[����]
	�v���C���[�̃X�e�[�g�̊Ǘ�

--------------------------------------------------------------*/
#pragma once
#include <memory>
#include <string>

namespace
{
	const __int32 SkillTypeNum = 4;			// �X�L���̎��
	const __int32 PatternNum = 3;			// �ʏ�U���A�X�L���̃p�^�[���̐�
	const __int32 SkillCountUpperLimit = 3; // �X�L�����������
	const __int32 NormalTypeNum = 3;		// �ʏ�s���̎��
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
		e_Attack_1,
		E_Attack_2,
		E_Attack_3,
		E_Attack_NONE
	};
	std::unique_ptr<class StateMachine> m_StateMachine;
	std::shared_ptr<class StateSwitch> m_State[SkillTypeNum * PatternNum + (NormalTypeNum * PatternNum -1)];	// �o�^����X�e�[�g��[17]
	std::string m_SkillName[SkillTypeNum][PatternNum];						// �o�^����X�L����[][]
	std::string m_AttackName[PatternNum];		// �ʏ�U��
	std::string m_NormalName[NormalTypeNum - 1];
	__int32 m_Count;	// �X�L���̔�����
	__int32 m_Type;		// �����X�L���̃^�C�v
	__int32 m_Pattern;  // �����X�L���̃p�^�[��
};
