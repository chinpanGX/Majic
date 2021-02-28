/*-----------------------------------------------

	[GameScene.cpp]
	Author : �o���đ�

	[����]
	�Q�[���V�[���̊Ǘ�

-------------------------------------------------*/
#include "Bg.h"
#include "GameScene.h"
#include "Input.h"
#include "Manager.h"
#include "Player.h"

// �^�C�g���V�[��
#pragma region GameScene_Title_Func
void GameScene::Title::Init()
{
	AddGameObject<GameBg::Title>(L_2D_BG);
	AddGameObject<Player>(L_3D);
}

void GameScene::Title::Uninit()
{

}

void GameScene::Title::Update()
{
	Scene::Update();
	if (KeyBoard::IsTrigger(DIK_T) || GamePad::IsTrigger(0, BTN_L2))
	{
		GameManager::GetInstance().SetScene<Game>();
	}
}

void GameScene::Title::Draw()
{
	Scene::Draw();
}
#pragma endregion Title�̃N���X�̊֐���`

// �Q�[���V�[��
#pragma region GameScene_Game_Func
// ������
void GameScene::Game::Init()
{
	//AddGameObject<SettingShader>(LAYER_3D);
	
}

void GameScene::Game::Uninit()
{

}

// �X�V
void GameScene::Game::Update()
{
	Scene::Update();
	if (KeyBoard::IsTrigger(DIK_T) || GamePad::IsTrigger(0, BTN_L2))
	{
		GameManager::GetInstance().SetScene<Result>();
	}
}

// �`��
void GameScene::Game::Draw()
{
	Scene::Draw();
}
#pragma endregion Game�N���X�̊֐���`

// ������
void GameScene::Result::Init()
{
	//AddGameObject<SettingShader>(LAYER_3D);
	AddGameObject<GameBg::Result>(L_2D_BG);
}

void GameScene::Result::Uninit()
{

}

// �X�V
void GameScene::Result::Update()
{
	Scene::Update();
	if (KeyBoard::IsTrigger(DIK_T) || GamePad::IsTrigger(0, BTN_L2))
	{
		GameManager::GetInstance().SetScene<Title>();
	}
}

// �`��
void GameScene::Result::Draw()
{
	Scene::Draw();
}