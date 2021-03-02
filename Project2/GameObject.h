/*----------------------------------------------

	[GameObject.h]
	Author : �o���đ�

	[����]
	GameObject 
		: ���ׂẴQ�[���I�u�W�F�N�g�ɑ΂�����N���X
			�I�u�W�F�N�g���L�����ǂ����̃t���O�iDestory�j������

-----------------------------------------------*/
#pragma once
#include <list>
#include "Transform.h"

class GameObject
{
public:
	GameObject() {};
	virtual ~GameObject() {};
	virtual void Init() = 0;
	virtual void Uninit() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0 ;

	void SetDestroy() { m_Destroy = true; }
	bool Destroy()
	{
		if (m_Destroy == true)
		{
			Uninit();
			delete this;
			return true;
		}
		else
		{
			return false;
		}
	}
	Transform GetTransform()
	{
		return m_Transform;
	}
protected:
	Transform m_Transform;
	bool m_Destroy = false;
};
