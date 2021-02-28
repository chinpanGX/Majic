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
	class Title : public Scene
	{
	public:
		void Init()override;
		void Uninit()override;
		void Update()override;
		void Draw()override;
	};
	// �Q�[��
	class Game : public Scene
	{
	public:
		void Init()override;
		void Uninit()override;
		void Update()override;
		void Draw()override;
	};
	// ���U���g
	class Result : public Scene
	{
	public:
		void Init()override;
		void Uninit()override;
		void Update()override;
		void Draw()override;
	};
}