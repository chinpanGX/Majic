/*-------------------------------------------------------------

	[PlayerNormalAttack.h]
	Author : �o���đ�

--------------------------------------------------------------*/
#pragma once
#include <memory>
#include "PlayerPattern.h"
#include <vector>

class NormalAttack : public PlayerPatternManager
{
public:
	NormalAttack();
	~NormalAttack();
	void Update(const class Player& p)override;
	bool GetEnable() { return m_EnableThis; }
private:
	void IsAttackCountLimit(); // �U���񐔂ŗL�����ǂ������ׂ�
	std::vector<PlayerPattern*> m_Pattern;
};

class PlayerAttackA : public PlayerPattern
{
public:
	void Update(const class Player& p)override;
};

class PlayerAttackB : public PlayerPattern
{
public:
	void Update(const class Player& p)override;
};

class PlayerAttackC : public PlayerPattern
{
public:
	void Update(const class Player& p)override;
};
