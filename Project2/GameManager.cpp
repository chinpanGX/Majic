/*-------------------------------------------------------------

	[GameManager.cpp]
	Author : 出合翔太

	[説明]
	GameManager : ゲームシーンの管理

--------------------------------------------------------------*/
#include <time.h>
#include "GameScene.h"
#include "GameManager.h"
#include "Fade.h"
#include "ObjectPool.h"

void GameManager::Init()
{
	srand((unsigned int)time(NULL));
	ObjectPool::Init();
	m_Fade = std::make_unique<Fade>();
	m_Fade->Init();
	SetScene<GameScene::Title>();
	m_Fade->m_State = m_Fade->E_IN;
	SceneChange(m_Fade->m_Next);
}

void GameManager::Uninit()
{
	m_Fade->Uninit();
	m_Scene->Uninit();
	delete m_Scene;
}

void GameManager::Update()
{
	m_Scene->Update();
	m_Fade->Update();
}

void GameManager::Draw()
{
	m_GameManager.Begin();
	//3D用ライト設定
	Resource::Light light;
	light.Enable = true;
	light.Direction = D3DXVECTOR4(1.0f, -1.0f, 1.0f, 0.0f);
	D3DXVec4Normalize(&light.Direction, &light.Direction);
	light.Ambient = D3DXCOLOR(0.1f, 0.1f, 0.1f, 1.0f);
	light.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	m_GameManager.SetLight(light);

	m_Scene->Draw();
	m_Fade->Draw();

	light.Enable = false;
	m_GameManager.SetLight(light);

	m_GameManager.End();
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

GameManager::GameManager() : m_GameManager(Resource::GetInstance())
{
}

template<typename T>
void GameManager::SetScene()
{
	if (m_Fade->m_State != Fade::E_NONE)
	{
		return;
	}
	m_Fade->m_State = Fade::E_OUT;
	T* scene = new T;
	m_Fade->m_Next = scene;	
}
