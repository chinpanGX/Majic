/*-----------------------------------------------

	[Bg.h]
	Author : �o���đ�

	[����]
	Bg�N���X�F�w�i�`�悷������̃N���X�̊��N���X
	namespace Bg
	{
		Title  : �^�C�g���w�i
		Result : ���U���g�w�i
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
	D3DXVECTOR2 m_Scrren; // ��ʃT�C�Y
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