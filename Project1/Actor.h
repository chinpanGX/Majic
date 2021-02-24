/*-----------------------------------------------
	
	[Actor.h]
	Author : 出合翔太

	[説明]
	Actor : GameObjectクラスを継承
	2D描画に使うRendererクラスを持つ

------------------------------------------------*/
#pragma once
#include "GameObject.h"
#include "Renderer.h"

class Actor : public GameObject
{
public:
	Actor() {}
	virtual ~Actor() {}
	virtual void Init() = 0;
	virtual void Uninit() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	Renderer GetRender()
	{
		return m_Renderer;
	}
protected:
	Renderer m_Renderer;
};

