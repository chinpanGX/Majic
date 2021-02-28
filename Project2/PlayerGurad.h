#pragma once
#include "PlayerPattern.h"
#include <memory>

class PlayerGurad : public PlayerPatternManager
{
public:
	PlayerGurad();
	~PlayerGurad();
	void Update(class Player* p);
private:
	std::unique_ptr<class PlayerGuardPattern> m_Guard;
};

class PlayerGuardPattern : public PlayerPattern
{
public:
	void Update(class Player* p)override;
};
