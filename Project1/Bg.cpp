#include "Bg.h"
#include "Application.h"

D3DXVECTOR2 Bg::GetScrren()
{
	auto& a = Application::GetInstance();
	m_Scrren.x = (float)a.GetWindowSize().cx;
	m_Scrren.y = (float)a.GetWindowSize().cy;
	return m_Scrren;
}

void GameBg::Title::Init()
{
}

void GameBg::Title::Uninit()
{
}

void GameBg::Title::Update()
{
}

void GameBg::Title::Draw()
{
}

void GameBg::Result::Init()
{
}

void GameBg::Result::Uninit()
{
}

void GameBg::Result::Update()
{
}

void GameBg::Result::Draw()
{
}
