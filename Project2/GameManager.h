/*-------------------------------------------------------------

	[GameManager.h]
	Author : 出合翔太

	[説明]
	GameManager : ゲームシーンの管理

--------------------------------------------------------------*/
#pragma once
#include "Singleton.h"
#include "Fade.h"
#include <memory>

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
		if (m_Fade->m_State != Fade::E_NONE)
		{
			return;
		}
		m_Fade->m_State = Fade::E_OUT;
		T* scene = new T;
		m_Fade->m_Next = scene;
	}
protected:
	GameManager() : m_DirectX(DirectXGraphics::GetInstance()){}
	~GameManager(){}
private:
	class Scene* m_Scene = nullptr;
	std::unique_ptr<class Fade> m_Fade;
	class DirectXGraphics& m_DirectX;
};
