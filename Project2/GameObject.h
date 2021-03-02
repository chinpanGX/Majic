/*----------------------------------------------

	[GameObject.h]
	Author : 出合翔太

	[説明]
	GameObject 
		: すべてのゲームオブジェクトに対する基底クラス
			オブジェクトが有効化どうかのフラグ（Destory）を持つ

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
