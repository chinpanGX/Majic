/*-----------------------------------------------

	[CrystallizeAura.h]
	Author : �o���đ�

	[����]
	�N���X�^���C�Y�I�[��

-----------------------------------------------*/
#pragma once
#include "Config.h"

class CrystallizeAura : public IPlayerState
{
public:
	CrystallizeAura(StateMachine& s);
	~CrystallizeAura();
	void SetActive()override;
private:
	void IsAttackCountLimit(); // �U���񐔂ŗL�����ǂ������ׂ�
	StateMachine& m_StateMachine;
};

class CrystallizeAuraA : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};

class CrystallizeAuraB : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};

class CrystallizeAuraC : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};


