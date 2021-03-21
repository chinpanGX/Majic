/*-----------------------------------------------

	[Bg.h]
	Author : 出合翔太

	[説明]
	Bgクラス：背景描画する役割のクラスの基底クラス
	namespace Bg
	{
		Title  : タイトル背景
		Result : リザルト背景
	}

------------------------------------------------*/
#pragma once
#include "Actor.h"

class Bg : public Actor
{
public:
	void Init() {};
	void Uninit() {};
	void Update() {};
	void Draw() {};
	D3DXVECTOR2 GetScrren();
private:
	D3DXVECTOR2 m_Scrren; // 画面サイズ
};

namespace GameBg
{
	class Title : public Bg
	{
	public:
		void Init()override;
		void Uninit()override;
		void Update()override;
		void Draw()override;
	};
	class Result : public Bg
	{
	public:
		void Init()override;
		void Uninit()override;
		void Update()override;
		void Draw()override;
	};
}