/*-------------------------------------------------------------

	[PlayerStateManager.cpp]
	Author : �o���đ�

	[����]
	�v���C���[�̃X�e�[�g�̊Ǘ�

--------------------------------------------------------------*/
#include "PlayerStateManager.h"
#include "StateMachine.h"
#include "PlayerSkillState.h"
#include "PlayerState.h"
#include "Player.h"

PlayerStateManager::PlayerStateManager() : 
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

void PlayerStateManager::Init(Player* player)
{
	using namespace std;
	/*
	//�@�Z�C�N���b�h�u���X�g
	m_State[0] = make_shared<StateSwitch>(make_shared<SacredBlastA>(), m_SkillName[0][0]);
	m_State[1] = make_shared<StateSwitch>(make_shared<SacredBlastB>(), m_SkillName[0][1]);
	m_State[2] = make_shared<StateSwitch>(make_shared<SacredBlastC>(), m_SkillName[0][2]);
	// �A�X�g�����t���A
	m_State[3] = make_shared<StateSwitch>(make_shared<AstralFlareA>(), m_SkillName[1][0]);
	m_State[4] = make_shared<StateSwitch>(make_shared<AstralFlareB>(), m_SkillName[1][1]);
	m_State[5] = make_shared<StateSwitch>(make_shared<AstralFlareC>(), m_SkillName[1][2]);
	// �A�|�J���v�X
	m_State[6] = make_shared<StateSwitch>(make_shared<ApocalypsisA>(), m_SkillName[2][0]);
	m_State[7] = make_shared<StateSwitch>(make_shared<ApocalypsisB>(), m_SkillName[2][1]);
	m_State[8] = make_shared<StateSwitch>(make_shared<ApocalypsisC>(), m_SkillName[2][2]);
	// �N���X�^���C�Y�I�[��
	m_State[9] = make_shared<StateSwitch>(make_shared<CrystallizeAuraA>(), m_SkillName[3][0]);
	m_State[10] = make_shared<StateSwitch>(make_shared<CrystallizeAuraB>(), m_SkillName[3][1]);
	m_State[11] = make_shared<StateSwitch>(make_shared<CrystallizeAuraC>(), m_SkillName[3][2]);
	// �ʏ�U��
	m_State[12] = make_shared<StateSwitch>(make_shared<PlayerAttackA>(), m_AttackName[0]);
	m_State[13] = make_shared<StateSwitch>(make_shared<PlayerAttackB>(), m_AttackName[1]);
	m_State[14] = make_shared<StateSwitch>(make_shared<PlayerAttackC>(), m_AttackName[2]);
	// ���̑�
	m_State[15] = make_shared<StateSwitch>(make_shared<PlayerGuard>(), m_NormalName[0]);
	m_State[16] = make_shared<StateSwitch>(make_shared<PlayerWait>(), m_NormalName[1]);
	
	// ���W�X�^�Ɋi�[
	__int32 c = 0;
	for (int i = 0; i < SkillTypeNum; i++)
	{
		for (int j = 0; j < PatternNum; j++)
		{
			player->GetStateMachine()->Register(m_SkillName[i][j], m_State[c++]);
		}
	}

	for (int i = 0; i < PatternNum; i++)
	{
		player->GetStateMachine()->Register(m_AttackName[i], m_State[c++]);
	}

	for (int i = 0; i < 2; i++)
	{
		player->GetStateMachine()->Register(m_NormalName[i], m_State[c++]);
	}*/
}

void PlayerStateManager::Uninit(Player* player)
{
	player->GetStateMachine()->Delete();
}

void PlayerStateManager::Update(Player* player)
{
	if (m_Pattern > SkillCountUpperLimit)
	{
		m_Pattern = 0;
	}
	player->GetStateMachine()->SetStartState(m_SkillName[m_Type][m_Pattern]);
	player->GetStateMachine()->Update();
}

bool PlayerStateManager::ActiveAttack(__int32 check)
{
	//m_State[]
	return false;
}

bool PlayerStateManager::ActiveGurad()
{
	return false;
}

bool PlayerStateManager::ActiveSkill(__int32 check)
{
	if (CheckTypeAndCount(check) == false)
	{
		m_State[check * 3]->GetState()->SetIsNext(false);
		return false;
	}
	else
	{
		return true;
	}
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

