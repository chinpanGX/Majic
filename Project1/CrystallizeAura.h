/*-----------------------------------------------

	[CrystallizeAura.h]
	Author : �o���đ�

	[����]
	�N���X�^���C�Y�I�[��

-----------------------------------------------*/
#pragma once
#include "Config.h"

class CrystallizeAura : public IStateConfig
{
public:
	CrystallizeAura();
	~CrystallizeAura();
	void SetActive()override;
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


