/*-------------------------------------------------------------

	[Player.h]
	Author : 出合翔太

	[説明]
	Player : プレイヤーの処理をまとめる

--------------------------------------------------------------*/
#pragma once
#include "Pawn.h"

class Player : public Pawn
{
public:
	Player(){}
	~Player(){}
	void Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
	
	std::shared_ptr<class PlayerController> GetController()const
	{
		return m_Controller;
	}
	std::shared_ptr<class PlayerEditor> GetEditer()const
	{
		return m_Editor;
	}
	
private:
	std::shared_ptr<class PlayerController> m_Controller; // 入力処理を管理
	std::shared_ptr<class PlayerEditor> m_Editor; //
};

