/*----------------------------------------------

	[Fade.h]
	Author : 出合翔太

	[説明]
	fadeクラス : フェード処理の管理

-----------------------------------------------*/
#pragma once
#include "Bg.h"

class Fade : public Bg
{
public:
	enum EState : int
	{
		E_NONE,
		E_IN,
		E_OUT
	};
	EState m_State;
	static class Scene* m_Next;
	Fade();
	~Fade(){}
	void Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
private:
	float m_Alpha;
	float m_Time;
	class Fps& m_Fps;
};

