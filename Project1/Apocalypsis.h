/*----------------------------------------------

	[Apocalypsis.h]
	Author : �o���đ�

	[����]
	�A�|�J���v�X�̏���

-----------------------------------------------*/
#pragma once
#include "StateMachine.h"

class Apocalypsis
{
public:
	Apocalypsis(StateMachine& s);
	~Apocalypsis();
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

class ApocalypsisA : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};

class ApocalypsisB : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};

class ApocalypsisC : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};