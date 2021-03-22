/*-----------------------------------------------
	
	[GameScene.h]
	Author : 出合翔太

	[説明]
	Title 　: タイトルシーン
	Game  　: ゲームシーン
	Result　: リザルトシーン

-------------------------------------------------*/
#pragma once
#include "Scene.h"
#include "Emitter.h"

namespace GameScene
{
	// タイトル
	class Title : public Scene
	{
	public:
		void Init()override;
		void Uninit()override;
		void Update()override;
		void Draw()override;
	};
	// ゲーム
	class Game : public Scene
	{
	public:
		void Init()override;
		void Uninit()override;
		void Update()override;
		void Draw()override;
	private:
		std::unique_ptr<class Emitter> m_Emitter;
	};
	// リザルト
	class Result : public Scene
	{
	public:
		void Init()override;
		void Uninit()override;
		void Update()override;
		void Draw()override;
	};
}