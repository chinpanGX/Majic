
#pragma once
#include "PlayerPattern.h"
#include <memory>

class PlayerWait : public PlayerPatternManager
{
public:
	PlayerWait();
	~PlayerWait();
	void Update(class Player* p)override;
private:
	class PlayerWaitPattern* m_Wait;
};

class PlayerWaitPattern : public PlayerPattern
{
public:
	void Update(class Player* p)override;
};
