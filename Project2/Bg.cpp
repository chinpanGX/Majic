#include "Bg.h"
#include "Application.h"
#include "ObjectPool.h"

D3DXVECTOR2 Bg::GetScrren()
{
	auto& a = Application::GetInstance();
	m_Scrren.x = (float)a.GetWindowSize().cx;
	m_Scrren.y = (float)a.GetWindowSize().cy;
	return m_Scrren;
}

void GameBg::Title::Init()
{
	m_Renderer.Init(GetTexture(Prefabs::Texture::ID::TATILE_BG), Bg::GetScrren() * 0.5f, Bg::GetScrren(), D3DXVECTOR2(0.0f, 0.0f), D3DXVECTOR2(1.0f, 1.0f));
}

void GameBg::Title::Uninit()
{

}

void GameBg::Title::Update()
{
}

void GameBg::Title::Draw()
{
	m_Renderer.Draw();
}

void GameBg::Result::Init()
{
	m_Renderer.Init(GetTexture(Prefabs::Texture::ID::GAME_BG), Bg::GetScrren() * 0.5f, Bg::GetScrren(), D3DXVECTOR2(0.0f, 0.0f), D3DXVECTOR2(1.0f, 1.0f));
}

void GameBg::Result::Uninit()
{

}

void GameBg::Result::Update()
{
}

void GameBg::Result::Draw()
{
	m_Renderer.Draw();
}
