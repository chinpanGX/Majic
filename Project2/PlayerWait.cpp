
#include "PlayerWait.h"
#include "Player.h"
#include "PlayerEditor.h"

PlayerWait::PlayerWait()
{
	m_Wait = new PlayerWaitPattern;
}

PlayerWait::~PlayerWait()
{
	delete m_Wait;
}

void PlayerWait::Update(const Player& p)
{
	m_Wait->Update(p);
}

void PlayerWaitPattern::Update(const Player& p)
{
	
}
