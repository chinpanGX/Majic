/*-----------------------------------------------

	[Application.h]
	Author : �o���đ�

	[����]
	�A�v���P�[�V�����S�̂̊Ǘ��F�V���O���g��

-----------------------------------------------*/
#pragma once
#include <Windows.h>
#include "Singleton.h"

class Application : public Singleton<Application>
{
	friend Singleton<Application>;
public:
	void Init(HINSTANCE h);
	void Run();
	SIZE GetWindowSize()const
	{
		SIZE ret;
		ret.cx = m_Width;
		ret.cy = m_Height;
		return ret;
	}
	HWND Gethwnd()const
	{
		return m_hwnd;
	}
protected:
	Application() : m_Width(1920), m_Height(1080), m_Mode(false) {}
	virtual ~Application() {}
private:
	WNDCLASSEX m_WindowClass;
	HWND m_hwnd;
	bool m_Mode;
	const float m_Width;
	const float m_Height;
	void CreateGameWindow(HWND& hwnd, WNDCLASSEX& window);
};

