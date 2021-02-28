/*-----------------------------------------------

	[AstralFlare.h]
	Author : �o���đ�

	[����]
	�A�X�g�����t���A�̏���

------------------------------------------------*/
#pragma once
#include <memory>
#include "PlayerPattern.h"

class AstralFlare : public PlayerPatternManager
{
public:
	AstralFlare();
	~AstralFlare();
	void Update(Player* p)override;
	bool GetEnable() { return m_EnableThis; }
private:
	void IsAttackCountLimit(); // �U���񐔂ŗL�����ǂ������ׂ�
	std::unique_ptr<PlayerPattern> m_Pattern[g_StateIndex];
};

class AstralFlareA : public PlayerPattern
{
public:
	virtual ~AstralFlareA(){}
	void Update(class Player* p)override;
private:
	const unsigned __int32 m_CostAp = 5;
};

class AstralFlareB : public PlayerPattern
{
public:
	virtual ~AstralFlareB() {}
	void Update(class Player* p)override;
private:
	const unsigned __int32 m_CostAp = 5;
};

class AstralFlareC : public PlayerPattern
{
public:
	virtual ~AstralFlareC() {}
	void Update(class Player* p)override;
private:
	const unsigned __int32 m_CostAp = 5;
};