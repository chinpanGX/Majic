/*----------------------------------------------

	[Apocalypsis.h]
	Author : �o���đ�

	[����]
	�A�|�J���v�X�̏���

-----------------------------------------------*/
#pragma once
#include "Config.h"

class Apocalypsis : public IPlayerState
{
public:
	Apocalypsis(StateMachine& s);
	~Apocalypsis();
	void SetActive()override;
private:
	void IsAttackCountLimit(); // �U���񐔂ŗL�����ǂ������ׂ�
	StateMachine& m_StateMachine;
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