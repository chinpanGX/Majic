/*-------------------------------------------------------------

	[Manager.cpp]
	Author : 出合翔太

	[説明]
	Manager : ゲームシーンの管理

--------------------------------------------------------------*/
#include <time.h>
#include "GameScene.h"
#include "Manager.h"

void GameManager::Init()
{
	srand((unsigned int)time(NULL));
	m_Manager.Init();
	m_Fade.Init();
	SetScene<GameScene::Title>();
	m_Fade.m_State = m_Fade.E_IN;
	SceneChange(m_Fade.m_Next);
}

void GameManager::Uninit()
{
	m_Fade.Uninit();
	m_Scene->Uninit();
	delete m_Scene;
}

void GameManager::Update()
{
	m_Scene->Update();
	m_Fade.Update();
}

void GameManager::Draw()
{
	m_Manager.Begin();
	//3D用ライト設定
	DirectX11::Light light;
	light.Enable = true;
	light.Direction = D3DXVECTOR4(1.0f, -1.0f, 1.0f, 0.0f);
	D3DXVec4Normalize(&light.Direction, &light.Direction);
	light.Ambient = D3DXCOLOR(0.1f, 0.1f, 0.1f, 1.0f);
	light.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	m_Manager.SetLight(light);

	m_Scene->Draw();
	m_Fade.Draw();

	light.Enable = false;
	m_Manager.SetLight(light);

	m_Manager.End();
}

void GameManager::SceneChange(Scene * s)
{
	if (m_Scene)
	{
		m_Scene->Uninit();
		delete m_Scene;
	}
	m_Scene = s;
	s->Init();
}
