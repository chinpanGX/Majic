/*-------------------------------------------------------------

	[PlayerState.h]
	Author : �o���đ�

	[����]
	�v���C���[�̃X�e�[�g

-------------------------------------------------------------*/
#pragma once
#include "PlayerPattern.h"

class Player;

class NormalAttack : public PlayerPattern
{
public:
	NormalAttack(StateMachine& s);
	~NormalAttack();
	void Update(Player* player)override;
	void SetActive();
	bool GetEnable() { return m_EnableThis; }
private:
	void IsAttackCountLimit(); // �U���񐔂ŗL�����ǂ������ׂ�
	std::string m_Name[StateIndex]; // �o�^��
	unsigned __int32 m_Count;	// ������
	bool m_EnableThis;			// �L�����ǂ���
};

class PlayerGurad : public PlayerPattern
{
public:
	PlayerGurad();
	~PlayerGurad();
	void Update(Player* player);
private:
};

class PlayerAttackA : public PlayerPattern
{
public:
	void Update(class Player* p)override;
};

class PlayerAttackB : public PlayerPattern
{
public:
	void Update(class Player* p)override;
};

class PlayerAttackC : public PlayerPattern
{
public:
	void Update(class Player* p)override;
};

class PlayerGuardPattern : public PlayerPattern
{
public:
	void Update(class Player* p)override;
};
