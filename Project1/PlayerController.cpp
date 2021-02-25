/*-------------------------------------------------------------

	[Controller.cpp]
	Author : 出合翔太

	[説明]
	プレイヤーの入力処理

--------------------------------------------------------------*/
#include "PlayerController.h"
#include "Input.h"
#include "PlayerStateManager.h"

void PlayerController::Update(Player * player)
{
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
		
	}
}

void PlayerController::Guard(Player * player)
{
	if (GamePad::IsTrigger(0, BTN_1))
	{
		
	}
}

void PlayerController::Skill_1(Player * player)
{
	if (IsSkillSelection() == true && GamePad::IsTrigger(0, BTN_1))
	{
		player->GetPlayerStateManager()->ActiveSkill(PlayerStateManager::ESkill::E_Skill_1);
	}
}

void PlayerController::Skill_2(Player * player)
{
	if (IsSkillSelection() == true && GamePad::IsTrigger(0, BTN_2))
	{
		player->GetPlayerStateManager()->ActiveSkill(PlayerStateManager::ESkill::E_Skill_2);
	}
}

void PlayerController::Skill_3(Player * player)
{
	if (IsSkillSelection() == true && GamePad::IsTrigger(0, BTN_4))
	{
		player->GetPlayerStateManager()->ActiveSkill(PlayerStateManager::ESkill::E_Skill_3);
	}
}

void PlayerController::Skill_4(Player * player)
{
	if (IsSkillSelection() == true && GamePad::IsTrigger(0, BTN_3))
	{
		player->GetPlayerStateManager()->ActiveSkill(PlayerStateManager::ESkill::E_Skill_4);
	}
}
