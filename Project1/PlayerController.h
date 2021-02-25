/*-------------------------------------------------------------

	[Controller.h]
	Author : �o���đ�

	[����]
	�v���C���[�̓��͏���

--------------------------------------------------------------*/
#pragma once
#include "Player.h"

class PlayerController
{
public:
	PlayerController() {}
	void Update(Player* player);
	bool IsSkillSelection(); // �X�L����I�𒆂��ǂ���
private:
	void Attack(Player* player);	// �U��		�Z
	void Guard(Player* player);		// �K�[�h	��
	void Skill_1(Player* player);	// �X�L���P R1�{��
	void Skill_2(Player* player);	// �X�L���Q R1�{�Z
	void Skill_3(Player* player);	// �X�L���R R1�{��
	void Skill_4(Player* player);	// �X�L���S R1�{�~
};

