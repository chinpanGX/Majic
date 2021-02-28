/*-----------------------------------------------

	[GameScene.cpp]
	Author : 出合翔太

	[説明]
	ゲームシーンの管理

-------------------------------------------------*/
#include "Bg.h"
#include "GameScene.h"
#include "Input.h"
#include "Manager.h"
#include "Player.h"

// タイトルシーン
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
	if (KeyBoard::IsTrigger(DIK_T) || GamePad::IsTrigger(0, BTN_2))
	{
		GameManager::GetInstance().SetScene<Game>();
	}
}

void GameScene::Title::Draw()
{
	Scene::Draw();
}
#pragma endregion Titleのクラスの関数定義

// ゲームシーン
#pragma region GameScene_Game_Func
// 初期化
void GameScene::Game::Init()
{
	//AddGameObject<SettingShader>(LAYER_3D);
	
}

void GameScene::Game::Uninit()
{

}

// 更新
void GameScene::Game::Update()
{
	Scene::Update();
	if (KeyBoard::IsTrigger(DIK_T) || GamePad::IsTrigger(0, BTN_2))
	{
		GameManager::GetInstance().SetScene<Result>();
	}
}

// 描画
void GameScene::Game::Draw()
{
	Scene::Draw();
}
#pragma endregion Gameクラスの関数定義

// 初期化
void GameScene::Result::Init()
{
	//AddGameObject<SettingShader>(LAYER_3D);
	AddGameObject<GameBg::Result>(L_2D_BG);
}

void GameScene::Result::Uninit()
{

}

// 更新
void GameScene::Result::Update()
{
	Scene::Update();
	if (KeyBoard::IsTrigger(DIK_T) || GamePad::IsTrigger(0, BTN_2))
	{
		GameManager::GetInstance().SetScene<Title>();
	}
}

// 描画
void GameScene::Result::Draw()
{
	Scene::Draw();
}