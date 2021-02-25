/*-------------------------------------------------------------

	[Player.h]
	Author : 出合翔太

	[説明]
	Player : プレイヤーの処理をまとめる

--------------------------------------------------------------*/
#pragma once
#include "Pawn.h"
#include "PlayerController.h"

class Player : public Pawn
{
public:
	void Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
private:
	PlayerController m_Controller;
	unsigned __int32 m_ActionPoint; // Ap->スキルで消費
};

