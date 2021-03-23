/*-----------------------------------------------
	
	[GameScene.h]
	Author : �o���đ�

	[����]
	Title �@: �^�C�g���V�[��
	Game  �@: �Q�[���V�[��
	Result�@: ���U���g�V�[��

-------------------------------------------------*/
#pragma once
#include "Scene.h"

namespace GameScene
{
	// �^�C�g��
	class Title final : public Scene
	{
	public:
		void Init()override;
		void Uninit()override;
		void Update()override;
		void Draw()override;
	};
	// �Q�[��
	class Game final : public Scene
	{
	public:
		void Init()override;
		void Uninit()override;
		void Update()override;
		void Draw()override;
	};
	// ���U���g
	class Result final : public Scene
	{
	public:
		void Init()override;
		void Uninit()override;
		void Update()override;
		void Draw()override;
	};
}