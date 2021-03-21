/*-------------------------------------------------------------

	[GameManager.h]
	Author : �o���đ�

	[����]
	GameManager : �Q�[���V�[���̊Ǘ�

--------------------------------------------------------------*/
#pragma once
#include "Singleton.h"
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
	void SetScene();
protected:
	GameManager();
	~GameManager(){}
private:
	class Scene* m_Scene = nullptr;
	std::unique_ptr<class Fade> m_Fade;
	class DirectXGraphics& m_DirectX;
};
