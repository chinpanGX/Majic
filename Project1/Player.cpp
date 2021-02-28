/*-------------------------------------------------------------

	[Player.cpp]
	Author : èoçá„ƒëæ

---------------------------------------------------------------*/
#include "Player.h"
#include "PlayerController.h"
#include "PlayerEditer.h"

void Player::Init()
{
	m_Controller = std::make_shared<PlayerController>(this);
	m_Editer = std::make_shared<PlayerEditer>();
}

void Player::Uninit()
{
}

void Player::Update()
{
	m_Controller->Update(this);
	m_Editer->Update();
}

void Player::Draw()
{
}
