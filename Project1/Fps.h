/*-----------------------------------------------

	[Fps.h]
	Author : 出合翔太

	[説明]
	FPSの管理：シングルトン

------------------------------------------------*/
#pragma once
#include <Windows.h>
#include "Singleton.h"

class Fps : public Singleton<Fps>
{
	friend Singleton<Fps>;
public:
	void Init();			// 初期化
	void Uninit();			// 終了
	bool Update();			// 更新
	void Reset();			// リセット

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

