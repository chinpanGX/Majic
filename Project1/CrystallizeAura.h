/*-----------------------------------------------

	[CrystallizeAura.h]
	Author : 出合翔太

	[説明]
	クリスタライズオーラ

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


