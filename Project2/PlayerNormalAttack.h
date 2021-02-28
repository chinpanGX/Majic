/*-------------------------------------------------------------

	[PlayerNormalAttack.h]
	Author : o‡ãÄ‘¾

--------------------------------------------------------------*/
#pragma once
#include <memory>
#include "PlayerPattern.h"

class Player;

class NormalAttack : public PlayerPatternManager
{
public:
	NormalAttack();
	~NormalAttack();
	void Update(class Player* p)override;
	bool GetEnable() { return m_EnableThis; }
private:
	void IsAttackCountLimit(); // UŒ‚‰ñ”‚Å—LŒø‚©‚Ç‚¤‚©’²‚×‚é
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
