/*-------------------------------------------------------------

	[Controller.cpp]
	Author : �o���đ�

	[����]
	�v���C���[�̓��͏���

--------------------------------------------------------------*/
#include "Input.h"
#include "Player.h"
#include "PlayerController.h"
#include "CrystallizeAura.h"
#include "SacredBlast.h"
#include "Apocalypsis.h"
#include "AstralFlare.h"
#include "PlayerEditor.h"
#include "PlayerNormalAttack.h"
#include "PlayerGurad.h"
#include "PlayerWait.h"

PlayerController::PlayerController()
{
	m_pPattern = std::make_unique<PlayerWait>();
}

PlayerController::~PlayerController()
{
	
}

void PlayerController::Update(const Player& p)
{
	//if (p.GetEditer()->GetIsAction() == true)
	{
		IsSkillSelection();
		Attack(p);
		Guard(p);
		Skill_1(p);
		Skill_2(p);
		Skill_3(p);
		Skill_4(p);
	}
	//else
	{
		//ChangePattern(m_pPattern);
		//SetPattern<PlayerWait>(p);
	}
	m_pPattern->Update(p);
}

bool PlayerController::IsSkillSelection()
{
	bool Is = false;
	//R1�������Ă����true��Ԃ��āA�X�L���I�����Ă��邱�Ƃ�������
	if(GamePad::IsPress(0, BTN_R1)) 
	{
		Is = true;
	}
	return Is;
}

void PlayerController::Attack(const Player&  p)
{
	if (GamePad::IsTrigger(0, BTN_2))
	{
		ChangePattern(m_pPattern.release());
		SetPattern<NormalAttack>(p);
	}
}

void PlayerController::Guard(const Player&  p)
{
	if (GamePad::IsTrigger(0, BTN_1))
	{
		ChangePattern(m_pPattern.release());
		SetPattern<PlayerGurad>(p);
	}
}

void PlayerController::Skill_1(const Player&  p)
{
	if (IsSkillSelection() == true && GamePad::IsTrigger(0, BTN_1))
	{
		ChangePattern(m_pPattern.release());
		SetPattern<SacredBlast>(p);
	}
}

void PlayerController::Skill_2(const Player&  p)
{
	if (IsSkillSelection() == true && GamePad::IsTrigger(0, BTN_2))
	{
		ChangePattern(m_pPattern.release());
		SetPattern<AstralFlare>(p);
	}
}

void PlayerController::Skill_3(const Player&  p)
{
	if (IsSkillSelection() == true && GamePad::IsTrigger(0, BTN_4))
	{
		ChangePattern(m_pPattern.release());
		SetPattern<Apocalypsis>(p);
	}
}

void PlayerController::Skill_4(const Player&  p)
{
	if (IsSkillSelection() == true && GamePad::IsTrigger(0, BTN_3))
	{
		ChangePattern(m_pPattern.release());
		SetPattern<CrystallizeAura>(p);
	}
}

template<typename T>
void PlayerController::SetPattern(const Player& p)
{
	m_pPattern = std::make_unique<T>(p);
}

void PlayerController::ChangePattern(PlayerPatternManager* p)
{
	if (p == nullptr)
	{
		// nullptr�̏ꍇ�������Ȃ�
	}
	else
	{
		delete p;
	}
}
