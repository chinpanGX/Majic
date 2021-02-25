/*-----------------------------------------------

	[AstralFlare.h]
	Author : �o���đ�

	[����]
	�A�X�g�����t���A�̏���

------------------------------------------------*/
#pragma once
#include "Config.h"

class AstralFlare : public IStateConfig
{
public:
	AstralFlare();
	~AstralFlare();
	void SetActive()override;
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