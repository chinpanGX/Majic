/*-------------------------------------------------------------

	[PlayerState.h]
	Author : 出合翔太

	[説明]
	プレイヤーのステート

-------------------------------------------------------------*/
#pragma once
#include <memory>
#include "PlayerPattern.h"


class Player;

class NormalAttack : public PlayerPatternManager
{
public:
	NormalAttack();
	~NormalAttack();
	void Update(Player* p)override;
	bool GetEnable() { return m_EnableThis; }
private:
	void IsAttackCountLimit(); // 攻撃回数で有効かどうか調べる
	std::unique_ptr<PlayerPattern> m_Pattern[g_StateIndex];
};

class PlayerAttackA : public PlayerPattern
{
public:
	void Update(class Player* p)override;
};

class PlayerAttackB : public PlayerPattern
{
public:
	void Update(class Player* p)override;
};

class PlayerAttackC : public PlayerPattern
{
public:
	void Update(class Player* p)override;
};



class PlayerGurad : public PlayerPatternManager
{
public:
	PlayerGurad();
	~PlayerGurad();
	void Update(Player* p);
private:
};

class PlayerGuardPattern : public PlayerPattern
{
public:
	void Update(class Player* p)override;
};
