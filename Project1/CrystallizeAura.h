/*-----------------------------------------------

	[CrystallizeAura.h]
	Author : �o���đ�

	[����]
	�N���X�^���C�Y�I�[��

-----------------------------------------------*/
#pragma once
#include <memory>
#include "PlayerPattern.h"

class CrystallizeAura : public PlayerPatternManager
{
public:
	CrystallizeAura();
	~CrystallizeAura();
	void Update(Player* player)override;
	bool GetEnable() { return m_EnableThis; }
private:
	void IsAttackCountLimit(); // �U���񐔂ŗL�����ǂ������ׂ�
	std::unique_ptr<PlayerPattern> m_Pattern[g_StateIndex];
};

class CrystallizeAuraA : public PlayerPattern
{
public:
	virtual ~CrystallizeAuraA(){}
	void Update(class Player* p)override;
};

class CrystallizeAuraB : public PlayerPattern
{
public:
	virtual ~CrystallizeAuraB() {}
	void Update(class Player* p)override;
};

class CrystallizeAuraC : public PlayerPattern
{
public:
	virtual ~CrystallizeAuraC() {}
	void Update(class Player* p)override;
};


