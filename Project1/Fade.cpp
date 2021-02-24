/*-----------------------------------------------

	[Fps.cpp]
	Author : o‡ãÄ‘¾

------------------------------------------------*/
#include "Fade.h"
#include "Fps.h"
#include "Scene.h"
#include "Manager.h"
Scene* Fade::m_Next = nullptr;

Fade::Fade() : m_State(E_NONE), m_Alpha(1.0f), m_Time(0.0f), m_Fps(Fps::GetInstance())
{

}

void Fade::Init()
{
	m_Renderer.Init();
}

void Fade::Uninit()
{
	m_Renderer.Uninit();
}

void Fade::Update()
{
	switch (m_State)
	{
	case E_OUT:
		m_Alpha += m_Fps.m_deltaTime / m_Time;
		if (m_Alpha > 1.0f)
		{
			GameManager::GetInstance().SceneChange(m_Next);
			m_State = E_IN;
			m_Alpha = 1.0f;
		}
		break;
	case E_IN:
		m_Alpha -= m_Fps.m_deltaTime / m_Time;
		if (m_Alpha < 0.0f)
		{
			m_State = E_NONE;
			m_Alpha = 0;
		}
		break;
	}
}

void Fade::Draw()
{
}
