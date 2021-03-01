/*-------------------------------------------------------------

	[PlayerNormalAttack.h]
	Author : o‡ãÄ‘¾

--------------------------------------------------------------*/
#pragma once
#include <memory>
#include "PlayerPattern.h"

class NormalAttack : public PlayerPatternManager
{
public:
	NormalAttack();
	~NormalAttack();
	void Update(class Player* p)override;
	bool GetEnable() { return m_EnableThis; }
private:
	void IsAttackCountLimit(class Player* p); // UŒ‚‰ñ”‚Å—LŒø‚©‚Ç‚¤‚©’²‚×‚é
	std::unique_ptr<PlayerPattern> m_Pattern;
};

class PlayerAttackA : public PlayerPattern
{
public:
	PlayerAttackA() : m_AddAp(0) {}
	PlayerAttackA(__int32 ap) : m_AddAp(ap) {}
	~PlayerAttackA(){}
	void Update(class Player* p)override;
private:
	__int32 m_AddAp;
};

class PlayerAttackB : public PlayerPattern
{
public:
	PlayerAttackB() : m_AddAp(0) {}
	PlayerAttackB(__int32 ap) : m_AddAp(ap) {}
	~PlayerAttackB() {}
	void Update(class Player* p)override;
private:
	__int32 m_AddAp;
};

class PlayerAttackC : public PlayerPattern
{
public:
	PlayerAttackC() : m_AddAp(0) {}
	PlayerAttackC(__int32 ap) : m_AddAp(ap){}
	~PlayerAttackC() {}
	void Update(class Player* p)override;
private:
	__int32 m_AddAp;
};
