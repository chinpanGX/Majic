/*-------------------------------------------------------------

	[Player.cpp]
	Author : èoçá„ƒëæ

---------------------------------------------------------------*/
#include "Player.h"
#include "PlayerController.h"
#include "PlayerEditor.h"

void Player::Init()
{
	m_Controller = std::make_shared<PlayerController>(this);
	m_Editor = std::make_shared<PlayerEditor>();
}

void Player::Uninit()
{
}

void Player::Update()
{
	m_Controller->Update(this);
	//m_Editor->Update();
}

void Player::Draw()
{
}
