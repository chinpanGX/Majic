/*-------------------------------------------------------------

	[Controller.cpp]
	Author : 出合翔太

	[説明]
	プレイヤーの入力処理

--------------------------------------------------------------*/
#include "Input.h"
#include "Player.h"
#include "PlayerController.h"
#include "PlayerState.h"
#include "CrystallizeAura.h"
#include "SacredBlast.h"
#include "Apocalypsis.h"
#include "AstralFlare.h"
#include "PlayerEditer.h"

PlayerController::PlayerController(Player* player)
{
	
}

PlayerController::~PlayerController()
{
	delete m_pPattern;
}

void PlayerController::Update(Player * player)
{
	if (player->GetEditer()->GetIsAction() == true)
	{
		Attack(player);
		Guard(player);
		Skill_1(player);
		Skill_2(player);
		Skill_3(player);
		Skill_4(player);
		m_pPattern->Update(player);
	}
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

void PlayerController::Attack(Player * player)
{
	if (GamePad::IsTrigger(0, BTN_2))
	{
		ChangePattern(m_pPattern);
		SetPattern<NormalAttack>(player);
	}
}

void PlayerController::Guard(Player * player)
{
	if (GamePad::IsTrigger(0, BTN_1))
	{
		ChangePattern(m_pPattern);
		SetPattern<PlayerGurad>(player);
	}
}

void PlayerController::Skill_1(Player * player)
{
	if (IsSkillSelection() == true && GamePad::IsTrigger(0, BTN_1))
	{
		ChangePattern(m_pPattern);
		SetPattern<SacredBlast>(player);
	}
}

void PlayerController::Skill_2(Player * player)
{
	if (IsSkillSelection() == true && GamePad::IsTrigger(0, BTN_2))
	{
		ChangePattern(m_pPattern);
		SetPattern<AstralFlare>(player);
	}
}

void PlayerController::Skill_3(Player * player)
{
	if (IsSkillSelection() == true && GamePad::IsTrigger(0, BTN_4))
	{
		ChangePattern(m_pPattern);
		SetPattern<Apocalypsis>(player);
	}
}

void PlayerController::Skill_4(Player * player)
{
	if (IsSkillSelection() == true && GamePad::IsTrigger(0, BTN_3))
	{
		ChangePattern(m_pPattern);
		SetPattern<CrystallizeAura>(player);
	}
}

template<typename T>
void PlayerController::SetPattern(Player * p)
{
	m_pPattern = new T(*p->GetStateMachine());
}


void PlayerController::ChangePattern(PlayerPattern * p)
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
