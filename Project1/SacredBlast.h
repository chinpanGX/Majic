/*-----------------------------------------------

	[SacredBlast.h]
	Author : �o���đ�

	[����]
	�X�L���F�Z�C�N���b�h�u���X�g�̏���

------------------------------------------------*/
#pragma once
#include "Config.h"

class SacredBlast : public IStateConfig
{
public:
	SacredBlast();
	~SacredBlast();
	void SetActive()override;
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