/*-----------------------------------------------

	[CrystallizeAura.h]
	Author : �o���đ�

	[����]
	�N���X�^���C�Y�I�[��

-----------------------------------------------*/
#pragma once
#include <memory>
#include "PlayerPattern.h"
#include <vector>

class CrystallizeAura : public PlayerPatternManager
{
public:
	CrystallizeAura();
	~CrystallizeAura();
	void Update(class Player* p)override;
	bool GetEnable() { return m_EnableThis; }
private:
	void IsAttackCountLimit(); // �U���񐔂ŗL�����ǂ������ׂ�
	std::vector<PlayerPattern*> m_Pattern;
};

class CrystallizeAuraA : public PlayerPattern
{
public:
	virtual ~CrystallizeAuraA(){}
	void Update(class Player* p)override;
private:
	const int32_t m_CostAp = 5;
};

class CrystallizeAuraB : public PlayerPattern
{
public:
	virtual ~CrystallizeAuraB() {}
	void Update(class Player* p)override;
private:
	const int32_t m_CostAp = 5;
};

class CrystallizeAuraC : public PlayerPattern
{
public:
	virtual ~CrystallizeAuraC() {}
	void Update(class Player* p)override;
private:
	const int32_t m_CostAp = 5;
};

