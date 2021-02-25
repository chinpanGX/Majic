/*-----------------------------------------------

	[SacredBlast.h]
	Author : 出合翔太

	[説明]
	スキル：セイクリッドブラストの処理

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