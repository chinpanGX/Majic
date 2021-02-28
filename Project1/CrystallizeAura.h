/*-----------------------------------------------

	[CrystallizeAura.h]
	Author : �o���đ�

	[����]
	�N���X�^���C�Y�I�[��

-----------------------------------------------*/
#pragma once
#include "PlayerPattern.h"

class CrystallizeAura : public PlayerPattern
{
public:
	CrystallizeAura(StateMachine& s);
	~CrystallizeAura();
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


