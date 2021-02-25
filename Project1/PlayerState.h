/*-------------------------------------------------------------

	[PlayerState.h]
	Author : 出合翔太

	[説明]
	プレイヤーのステート

-------------------------------------------------------------*/
#pragma once
#include "StateMachine.h"

class PlayerAttackA : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};

class PlayerAttackB : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};

class PlayerAttackC : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};

class PlayerGuard : public StateBase
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};

class PlayerWait : public StateBase 
{
public:
	void Start()override;
	void Update()override;
	void ChangeEvent()override;
};