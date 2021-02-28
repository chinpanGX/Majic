/*----------------------------------------------

	[Apocalypsis.h]
	Author : �o���đ�

	[����]
	�A�|�J���v�X�̏���

-----------------------------------------------*/
#pragma once
#include <memory>
#include "PlayerPattern.h"

class Apocalypsis : public PlayerPatternManager
{
public:
	Apocalypsis();
	~Apocalypsis();
	void Update(Player* p)override;
	bool GetEnable() { return m_EnableThis; }
private:
	void IsAttackCountLimit(); // �U���񐔂ŗL�����ǂ������ׂ�
	std::unique_ptr<PlayerPattern> m_Pattern[g_StateIndex];
};

class ApocalypsisA : public PlayerPattern
{
public:
	virtual ~ApocalypsisA(){}
	void Update(class Player* p)override;
};

class ApocalypsisB : public PlayerPattern
{
public:
	virtual ~ApocalypsisB() {}
	void Update(class Player* p)override;
};

class ApocalypsisC : public PlayerPattern
{
public:
	virtual ~ApocalypsisC() {}
	void Update(class Player* p)override;
};