/*----------------------------------------------

	[Apocalypsis.h]
	Author : �o���đ�

	[����]
	�A�|�J���v�X�̏���

-----------------------------------------------*/
#pragma once
#include "Config.h"

class Apocalypsis : public IStateConfig
{
public:
	Apocalypsis();
	~Apocalypsis();
	void SetActive()override;
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