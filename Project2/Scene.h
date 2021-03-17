/*-----------------------------------------------

	[Scene.h]
	Author : �o���đ�

	[�N���X����]
	Scene : Scene�̊��N���X


------------------------------------------------*/
#pragma once
#include "GameObject.h"
#include <list>
#include <vector>
#include <vector>
#include <typeinfo>
#include <string>

class Scene
{
public:
	enum ELayer : int // �X�V�A�`��̏���
	{
		L_CAMERA,
		L_3D,
		L_2D_BG,
		L_2D_EFFECT,
		L_2D_UI,
		MAX
	};
	Scene() {}
	virtual ~Scene() {}
	virtual void Init() = 0;
	virtual void Uninit()
	{
		for (int i = 0; i < ELayer::MAX; i++)
		{
			for (auto object : m_GameObject[i])
			{
				object->Uninit();
				delete object;
			}
			m_GameObject[i].clear();
		}
	}
	virtual void Update()
	{
		for (int i = 0; i < ELayer::MAX; i++)
		{
			for (auto object : m_GameObject[i])
			{
				object->Update();
			}
		}
		for (int i = 0; i < ELayer::MAX; i++)
		{
			m_GameObject[i].remove_if([](auto object) { return object->Destroy(); }); // �����_��
		}
	}
	virtual void Draw()
	{
		for (int i = 0; i < ELayer::MAX; i++)
		{
			for (auto object : m_GameObject[i])
			{
				object->Draw();
			}
		}
	}

	// �ǉ�
	template <typename T>
	T* AddGameObject(int layer)
	{
		T* gameObject = new T();
		m_GameObject[layer].push_back(gameObject);
		gameObject->Init();
		return gameObject;
	}

	// �Q�b�^�[
	template<typename T>
	T* GetGameObject(int layer)
	{
		for (GameObject* object : m_GameObject[layer])
		{
			if (typeid(*object) == typeid(T))
				return (T*)object;
		}
		return nullptr
;
	}
	template<typename T>
	std::vector<T*>GetGameObjects(int layer)
	{
		std::vector<T*>objects;
		for (GameObject* object : m_GameObject[layer])
		{
			if (typeid(*object) == typeid(T))
				objects.push_back((T*)object);
		}
		return objects;
	}

protected:
	std::list<GameObject*> m_GameObject[Layer::MAX];
};
