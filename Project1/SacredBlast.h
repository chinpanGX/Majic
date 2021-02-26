/*-----------------------------------------------

	[SacredBlast.h]
	Author : �o���đ�

	[����]
	�X�L���F�Z�C�N���b�h�u���X�g�̏���

------------------------------------------------*/
#pragma once
#include "StateMachine.h"

class SacredBlast
{
public:
	SacredBlast(StateMachine& s);
	~SacredBlast();
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

class SacredBlastA : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};

class SacredBlastB : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};

class SacredBlastC : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};