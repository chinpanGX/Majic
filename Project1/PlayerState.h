/*-------------------------------------------------------------

	[PlayerState.h]
	Author : �o���đ�

	[����]
	�v���C���[�̃X�e�[�g

-------------------------------------------------------------*/
#pragma once
#include <memory>
#include "PlayerPattern.h"


class Player;

class NormalAttack : public PlayerPatternManager
{
public:
	NormalAttack();
	~NormalAttack();
	void Update(Player* p)override;
	bool GetEnable() { return m_EnableThis; }
private:
	void IsAttackCountLimit(); // �U���񐔂ŗL�����ǂ������ׂ�
	std::unique_ptr<PlayerPattern> m_Pattern[g_StateIndex];
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



class PlayerGurad : public PlayerPatternManager
{
public:
	PlayerGurad();
	~PlayerGurad();
	void Update(Player* p);
private:
};

class PlayerGuardPattern : public PlayerPattern
{
public:
	void Update(class Player* p)override;
};
