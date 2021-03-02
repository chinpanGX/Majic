/*-----------------------------------------------

	[Fps.h]
	Author : �o���đ�

	[����]
	FPS�̊Ǘ��F�V���O���g��

------------------------------------------------*/
#pragma once
#include <Windows.h>
#include "Singleton.h"

class Fps : public Singleton<Fps>
{
	friend Singleton<Fps>;
public:
	void Init();			// ������
	void Uninit();			// �I��
	bool Update();			// �X�V
	void Reset();			// ���Z�b�g

	float m_deltaTime;
protected:
	Fps() : m_Framerate(60), m_dwExcLastTime(0), m_dwCurrentTime(0), m_dwOldCurrentTime(0), m_isReset(false), m_deltaTime(0) {}
	virtual ~Fps() {}

private:
	const float m_Framerate;
	DWORD m_dwExcLastTime;
	DWORD m_dwCurrentTime;
	DWORD m_dwOldCurrentTime;
	bool m_isReset;
};

