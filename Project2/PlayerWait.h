
#pragma once
#include "PlayerPattern.h"
#include <memory>

class PlayerWait : public PlayerPatternManager
{
public:
	PlayerWait();
	~PlayerWait();
	void Update(const class Player& p)override;
private:
	std::unique_ptr<class PlayerWaitPattern> m_Wait;
};

class PlayerWaitPattern : public PlayerPattern
{
public:
	void Update(const class Player& p)override;
};
