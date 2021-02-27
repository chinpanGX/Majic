/*-------------------------------------------------------------

	[PlayerState.h]
	Author : �o���đ�

	[����]
	�v���C���[�̃X�e�[�g

-------------------------------------------------------------*/
#pragma once
#include "StateMachine.h"
#include "PlayerPattern.h"

class Player;

class NormalAttack : public PlayerPattern
{
public:
	NormalAttack(StateMachine& s);
	~NormalAttack();
	void Update(Player* player)override;
	void SetActive();
	bool GetEnable() { return m_EnableThis; }
private:
	void IsAttackCountLimit(); // �U���񐔂ŗL�����ǂ������ׂ�
	StateMachine& m_StateMachine;
	std::shared_ptr<StateSwitch> m_State[StateIndex]{};	// �o�^����X�e�[�g��[]
	std::string m_Name[StateIndex]; // �o�^��
	unsigned __int32 m_Count;	// ������
	bool m_EnableThis;			// �L�����ǂ���
};

class PlayerGurad : public PlayerPattern
{
public:
	PlayerGurad(StateMachine& s);
	~PlayerGurad();
	void Update(Player* player);
private:
	StateMachine& m_StateMachine;
};

class PlayerWait : public PlayerPattern
{
public:
	PlayerWait(StateMachine& s);
	~PlayerWait();
	void Update(Player* player)override;
	unsigned __int32 GetWaitTime()
	{
		return m_Waittime;
	}
	void SetWaitTime(unsigned __int32 time)
	{
		m_Waittime = time;
	}
private:
	StateMachine& m_StateMachine;
	unsigned __int32 m_Waittime;
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

class PlayerGuardPattern : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};

class PlayerWaitPattern : public StateBase 
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};