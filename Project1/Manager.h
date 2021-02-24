/*-------------------------------------------------------------

	[Manager.h]
	Author : 出合翔太

	[説明]
	Manager : ゲームシーンの管理

--------------------------------------------------------------*/
#pragma once
#include "Singleton.h"
#include "DirectX11.h"
#include "Fade.h"

class GameManager : public Singleton<GameManager>
{
	friend Singleton<GameManager>;
public:
	void Init();
	void Uninit();
	void Update();
	void Draw();
	class Scene* GetScene() { return m_Scene; }
	void SceneChange(class Scene* s);
	template<typename T>
	void SetScene()
	{
	//	if ()
	}
protected:
	GameManager() : m_Manager(DirectX11::Manager::GetInstance()) {}
	~GameManager(){}
private:
	class Scene* m_Scene = nullptr;
	class Fade m_Fade;
	DirectX11::Manager& m_Manager;
};
