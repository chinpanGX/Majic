/*-------------------------------------------------------------

	[Manager.h]
	Author : �o���đ�

	[����]
	Manager : �Q�[���V�[���̊Ǘ�

--------------------------------------------------------------*/
#pragma once
#include "Singleton.h"
#include "Resource.h"
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
		if (m_Fade->m_State != Fade::E_NONE)
		{
			return;
		}
		m_Fade->m_State = Fade::E_OUT;
		T* scene = new T;
		m_Fade->m_Next = scene;
	}
protected:
	Manager() : m_Manager(Resource::GetInstance()) {}
	~Manager(){}
private:
	class Scene* m_Scene = nullptr;
	std::unique_ptr<Fade> m_Fade;
	Resource& m_Manager;
};
