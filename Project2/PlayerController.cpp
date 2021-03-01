/*-------------------------------------------------------------

	[Controller.cpp]
	Author : 出合翔太

	[説明]
	プレイヤーの入力処理

--------------------------------------------------------------*/
#include "Input.h"
#include "Player.h"
#include "PlayerController.h"
#include "CrystallizeAura.h"
#include "SacredBlast.h"
#include "Apocalypsis.h"
#include "AstralFlare.h"
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

void PlayerController::Update(Player* p)
{
	if (p->GetIsAction() == true)
	{
		IsSkillSelection();
		//Attack(p);
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
	//R1を押している間trueを返して、スキル選択していることを教える
	if(GamePad::IsPress(0, BTN_R1)) 
	{
		Is = true;
	}
	return Is;
}

void PlayerController::Attack(Player*  p)
{
	if (GamePad::IsTrigger(0, BTN_2))
	{
		ChangePattern(m_pPattern.release());
		SetPattern<NormalAttack>();
	}
}

void PlayerController::Guard(Player*  p)
{
	if (GamePad::IsTrigger(0, BTN_1))
	{
		ChangePattern(m_pPattern.release());
		SetPattern<PlayerGurad>();
	}
}

void PlayerController::Skill_1(Player*  p)
{
	if (IsSkillSelection() == true && GamePad::IsTrigger(0, BTN_1))
	{
		ChangePattern(m_pPattern.release());
		SetPattern<SacredBlast>();
	}
}

void PlayerController::Skill_2(Player*  p)
{
	if (IsSkillSelection() == true && GamePad::IsTrigger(0, BTN_2))
	{
		ChangePattern(m_pPattern.release());
		SetPattern<AstralFlare>();
	}
}

void PlayerController::Skill_3(Player*  p)
{
	if (IsSkillSelection() == true && GamePad::IsTrigger(0, BTN_4))
	{
		ChangePattern(m_pPattern.release());
		SetPattern<Apocalypsis>();
	}
}

void PlayerController::Skill_4(Player*  p)
{
	if (IsSkillSelection() == true && GamePad::IsTrigger(0, BTN_3))
	{
		ChangePattern(m_pPattern.release());
		SetPattern<CrystallizeAura>();
	}
}

template<typename T>
void PlayerController::SetPattern()
{
	m_pPattern = std::make_unique<T>();
}

void PlayerController::ChangePattern(PlayerPatternManager* p)
{
	delete p;
}
