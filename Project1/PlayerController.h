/*-------------------------------------------------------------

	[Controller.h]
	Author : �o���đ�

	[����]
	�v���C���[�̓��͏���

--------------------------------------------------------------*/
#pragma once

class PlayerController
{
public:
	PlayerController(class Player* player);
	~PlayerController();
	void Update(class Player* player);
	bool IsSkillSelection(); // �X�L����I�𒆂��ǂ���
private:
	void Attack(class Player* player);	// �U��		�Z
	void Guard(class Player* player);		// �K�[�h	��
	void Skill_1(class Player* player);	// �X�L���P R1�{��
	void Skill_2(class Player* player);	// �X�L���Q R1�{�Z
	void Skill_3(class Player* player);	// �X�L���R R1�{��
	void Skill_4(class Player* player);	// �X�L���S R1�{�~

	template<typename T>
	void SetPattern(class Player* p);
	void ChangePattern(class PlayerPattern* p);

	class PlayerPattern* m_pPattern;
};
