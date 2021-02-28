/*-----------------------------------------------

	[AstralFlare.h]
	Author : �o���đ�

	[����]
	�A�X�g�����t���A�̏���

------------------------------------------------*/
#pragma once
#include "PlayerPattern.h"

class AstralFlare : public PlayerPattern
{
public:
	AstralFlare(StateMachine& s);
	~AstralFlare();
	void Update(Player* player)override;
	bool GetEnable() { return m_EnableThis; }
private:
	void IsAttackCountLimit(); // �U���񐔂ŗL�����ǂ������ׂ�
	StateMachine& m_StateMachine;
	std::shared_ptr<StateSwitch> m_State[StateIndex]{};	// �o�^����X�e�[�g��[]
	std::string m_Name[StateIndex]; // �o�^��
	unsigned __int32 m_Count;	// ������
	bool m_EnableThis;			// �L�����ǂ���
};

class AstralFlareA : public PlayerPattern
{
public:
	virtual ~AstralFlareA(){}
	void Update(class Player* p)override;
};

class AstralFlareB : public PlayerPattern
{
public:
	virtual ~AstralFlareB() {}
	void Update(class Player* p)override;
};

class AstralFlareC : public PlayerPattern
{
public:
	virtual ~AstralFlareC() {}
	void Update(class Player* p)override;
};