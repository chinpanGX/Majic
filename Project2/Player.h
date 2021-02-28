/*-------------------------------------------------------------

	[Player.h]
	Author : �o���đ�

	[����]
	Player : �v���C���[�̏������܂Ƃ߂�

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
	std::shared_ptr<class PlayerController> m_Controller; // ���͏������Ǘ�
	std::shared_ptr<class PlayerEditor> m_Editor; //
};

