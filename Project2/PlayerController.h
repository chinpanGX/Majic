/*-------------------------------------------------------------

	[Controller.h]
	Author : �o���đ�

	[����]
	�v���C���[��

--------------------------------------------------------------*/
#pragma once

class PlayerController
{
public:
	PlayerController();
	~PlayerController();
	void Update(const class Player& player);
	bool IsSkillSelection(); // �X�L����I�𒆂��ǂ���
private:
	void Attack(const class Player& player);	// �U��		�Z
	void Guard(const class Player& player);	// �K�[�h	��
	void Skill_1(const class Player& player);	// �X�L���P R1�{��
	void Skill_2(const class Player& player);	// �X�L���Q R1�{�Z
	void Skill_3(const class Player& player);	// �X�L���R R1�{��
	void Skill_4(const class Player& player);	// �X�L���S R1�{�~
	
	template<typename T>
	void SetPattern(const class Player& p);
	void ChangePattern(class PlayerPatternManager* p);

	class PlayerPatternManager* m_pPattern;
};
