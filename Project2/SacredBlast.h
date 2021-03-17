/*-----------------------------------------------

	[SacredBlast.h]
	Author : �o���đ�

	[����]
	�X�L���F�Z�C�N���b�h�u���X�g�̏���

------------------------------------------------*/
#pragma once
#include <memory>
#include "PlayerPattern.h"
#include <vector>

class SacredBlast : public PlayerPatternManager

{
public:
	SacredBlast();
	~SacredBlast();
	void Update(class Player* player)override;
	bool GetEnable() { return m_EnableThis; }
private:
	void IsAttackCountLimit(); // �U���񐔂ŗL�����ǂ������ׂ�
	std::vector<PlayerPattern*> m_Pattern;
};

class SacredBlastA : public PlayerPattern
{
public:
	virtual ~SacredBlastA(){}
	void Update(class Player* p)override;
private:
	const int32_t m_CostAp = 5;
};

class SacredBlastB : public PlayerPattern
{
public:
	virtual ~SacredBlastB() {}
	void Update(class Player* p)override;
private:
	const int32_t m_CostAp = 5;
};

class SacredBlastC : public PlayerPattern
{
public:
	virtual ~SacredBlastC() {}
	void Update(class Player* p)override;
private:
	const int32_t m_CostAp = 5;
};