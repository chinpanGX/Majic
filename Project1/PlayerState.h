/*-------------------------------------------------------------

	[PlayerState.h]
	Author : �o���đ�

	[����]
	�v���C���[�̃X�e�[�g

-------------------------------------------------------------*/
#pragma once
#include "Config.h"

class NormalAttack : public IPlayerState
{
public:
	NormalAttack(StateMachine& s);
	~NormalAttack();
	void SetActive()override;
private:
	void IsAttackCountLimit(); // �U���񐔂ŗL�����ǂ������ׂ�
	StateMachine& m_StateMachine;
};

class PlayerAttackA : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};

class PlayerAttackB : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};

class PlayerAttackC : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};

class PlayerGuard : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};

class PlayerWait : public StateBase 
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};