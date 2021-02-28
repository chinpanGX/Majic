/*-------------------------------------------------------------

	[PlayerState.h]
	Author : 出合翔太

	[説明]
	プレイヤーのステート

-------------------------------------------------------------*/
#pragma once
#include "PlayerPattern.h"

class Player;

class NormalAttack : public PlayerPattern
{
public:
	NormalAttack(StateMachine& s);
	~NormalAttack();
	void Update(Player* player)override;
	void SetActive();
	bool GetEnable() { return m_EnableThis; }
private:
	void IsAttackCountLimit(); // 攻撃回数で有効かどうか調べる
	std::string m_Name[StateIndex]; // 登録名
	unsigned __int32 m_Count;	// 発動回数
	bool m_EnableThis;			// 有効化どうか
};

class PlayerGurad : public PlayerPattern
{
public:
	PlayerGurad();
	~PlayerGurad();
	void Update(Player* player);
private:
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

class PlayerGuardPattern : public PlayerPattern
{
public:
	void Update(class Player* p)override;
};
