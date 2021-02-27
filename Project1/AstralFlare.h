/*-----------------------------------------------

	[AstralFlare.h]
	Author : �o���đ�

	[����]
	�A�X�g�����t���A�̏���

------------------------------------------------*/
#pragma once
#include "StateMachine.h"
#include "PlayerPattern.h"

class AstralFlare : public PlayerPattern
{
public:
	AstralFlare(StateMachine& s);
	~AstralFlare();
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

class AstralFlareA : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};

class AstralFlareB : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};

class AstralFlareC : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};