/*-------------------------------------------------------------

	[PlayerStateManager.cpp]
	Author : �o���đ�

	[����]
	�v���C���[�̃X�e�[�g�̊Ǘ�

--------------------------------------------------------------*/
#include "PlayerStateManager.h"
#include "StateMachine.h"

PlayerStateManager::PlayerStateManager() : m_StateMachine(std::make_unique<StateMachine>()),
	m_SkillName{ "�Z�C�N���b�h�u���X�g", "�Z�C�N���b�h�u���X�g+",  "�Z�C�N���b�h�u���X�g++",
				 "�A�X�g�����t���A",	 "�A�X�g�����t���A+",	   "�A�X�g�����t���A++",
				 "�A�|�J���v�X",		 "�A�|�J���v�X+",		   "�A�|�J���v�X++",
				 "�N���X�^���C�Y�I�[��", "�N���X�^���C�Y�I�[��+",  "�N���X�^���C�Y�I�[��++" },
	m_AttackName{"�U��", "�U���Q", "�U���R"},
	m_NormalName{"�K�[�h","�ҋ@"},
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
