/*-----------------------------------------------

	[AstralFlare.h]
	Author : �o���đ�

	[����]
	�A�X�g�����t���A�̏���

------------------------------------------------*/
#pragma once
#include "Config.h"

class AstralFlare : public IPlayerState
{
public:
	AstralFlare(StateMachine& s);
	~AstralFlare();
	void SetActive()override;
private:
	void IsAttackCountLimit(); // �U���񐔂ŗL�����ǂ������ׂ�
	StateMachine& m_StateMachine;
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