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
	const __int32 SkillPatternNum = 3;		// �X�L���̃p�^�[���̐�
	const __int32 SkillCountUpperLimit = 3; // �X�L�����������
	const __int32 NurmalStateNum = 2;		// �ʏ�s��
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
	std::shared_ptr<class StateSwitch> m_State[SkillTypeNum * SkillPatternNum + NurmalStateNum];	// �o�^����X�e�[�g��
	std::string m_SkillName[SkillTypeNum][SkillPatternNum];						// �o�^����X�L����[][]
	std::string m_Name[2]; // �ʏ�s��
	__int32 m_Count;	// �X�L���̔�����
	__int32 m_Type;		// �����X�L���̃^�C�v
	__int32 m_Pattern;  // �����X�L���̃p�^�[��
};

