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

class PlayerAttackA : public IPlayerStatePattern
{
public:
	void Start()override;
	void Update()override;
	void Update(class Player* pPlayer)override;
	void ChangeEvent()override;
};

class PlayerAttackB : public IPlayerStatePattern
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};

class PlayerAttackC : public IPlayerStatePattern
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};

class PlayerGuard : public IPlayerStatePattern
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};

class PlayerWait : public IPlayerStatePattern 
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};