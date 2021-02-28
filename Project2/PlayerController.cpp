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
#include "PlayerEditor.h"
#include "PlayerNormalAttack.h"
#include "PlayerGurad.h"
#include "PlayerWait.h"

PlayerController::PlayerController()
{
	m_pPattern = new PlayerWait;
}

PlayerController::~PlayerController()
{
	delete m_pPattern;
}

void PlayerController::Update(const Player& p)
{
	if (p.GetEditer()->GetIsAction() == true)
	{
		IsSkillSelection();
		Attack(p);
		//Guard(p);
		Skill_1(p);
		/*Skill_2(p);
		Skill_3(p);
		Skill_4(p);*/
	}
	else
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

void PlayerController::Attack(const Player&  p)
{
	if (GamePad::IsTrigger(0, BTN_2))
	{
		ChangePattern(m_pPattern);
		SetPattern<NormalAttack>(p);
	}
}

void PlayerController::Guard(const Player&  p)
{
	if (GamePad::IsTrigger(0, BTN_1))
	{
		ChangePattern(m_pPattern);
		SetPattern<PlayerGurad>(p);
	}
}

void PlayerController::Skill_1(const Player&  p)
{
	if (IsSkillSelection() == true && GamePad::IsTrigger(0, BTN_1))
	{
		ChangePattern(m_pPattern);
		SetPattern<SacredBlast>(p);
	}
}

void PlayerController::Skill_2(const Player&  p)
{
	if (IsSkillSelection() == true && GamePad::IsTrigger(0, BTN_2))
	{
		ChangePattern(m_pPattern);
		SetPattern<AstralFlare>(p);
	}
}

void PlayerController::Skill_3(const Player&  p)
{
	if (IsSkillSelection() == true && GamePad::IsTrigger(0, BTN_4))
	{
		ChangePattern(m_pPattern);
		SetPattern<Apocalypsis>(p);
	}
}

void PlayerController::Skill_4(const Player&  p)
{
	if (IsSkillSelection() == true && GamePad::IsTrigger(0, BTN_3))
	{
		ChangePattern(m_pPattern);
		SetPattern<CrystallizeAura>(p);
	}
}

template<typename T>
void PlayerController::SetPattern(const Player&)
{
	m_pPattern = new T;
}

void PlayerController::ChangePattern(PlayerPatternManager * p)
{
	if (p == nullptr)
	{
		// nullptrの場合何もしない
	}
	else
	{
		delete p;
	}
}
