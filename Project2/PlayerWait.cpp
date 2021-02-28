
#include "PlayerWait.h"
#include "Player.h"
#include "PlayerEditor.h"

PlayerWait::PlayerWait()
{
	m_Wait = std::make_unique<PlayerWaitPattern>();
}

PlayerWait::~PlayerWait()
{
	
}

void PlayerWait::Update(const Player& p)
{
	m_Wait->Update(p);
}

void PlayerWaitPattern::Update(const Player& p)
{
	
}
