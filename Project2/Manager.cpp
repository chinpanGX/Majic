/*-------------------------------------------------------------

	[Manager.cpp]
	Author : 出合翔太

	[説明]
	Manager : ゲームシーンの管理

--------------------------------------------------------------*/
#include <time.h>
#include "GameScene.h"
#include "Manager.h"
#include "Player.h"
#include "ObjectPool.h"

void Manager::Init()
{
	srand((unsigned int)time(NULL));
	ObjectPool::Init();
	m_Fade.Init();
	SetScene<GameScene::Title>();
	m_Fade.m_State = m_Fade.E_IN;
	SceneChange(m_Fade.m_Next);
}

void Manager::Uninit()
{
	m_Fade.Uninit();
	ObjectPool::Uninit();
	m_Scene->Uninit();
	delete m_Scene;
}

void Manager::Update()
{
	m_Scene->Update();
	m_Fade.Update();
}

void Manager::Draw()
{
	m_Manager.Begin();
	//3D用ライト設定
	Resource::Light light;
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

void Manager::SceneChange(Scene * s)
{
	if (m_Scene)
	{
		m_Scene->Uninit();
		delete m_Scene;
	}
	m_Scene = s;
	s->Init();
}
