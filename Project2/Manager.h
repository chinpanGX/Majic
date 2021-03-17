/*-------------------------------------------------------------

	[Manager.h]
	Author : �o���đ�

	[����]
	Manager : �Q�[���V�[���̊Ǘ�

--------------------------------------------------------------*/
#pragma once
#include "Singleton.h"
#include "DirectX11.h"
#include "Fade.h"

class Manager : public Singleton<Manager>
{
	friend Singleton<Manager>;
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
		if (m_Fade.m_State != Fade::E_NONE)
		{
			return;
		}
		m_Fade.m_State = Fade::E_OUT;
		T* scene = new T;
		m_Fade.m_Next = scene;
	}
protected:
	Manager() : m_Manager(DirectX11::Manager::GetInstance()) {}
	~Manager(){}
private:
	class Scene* m_Scene = nullptr;
	class Fade m_Fade;
	DirectX11::Manager& m_Manager;
};
