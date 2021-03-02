
#include "PlayerWait.h"
#include "Player.h"


PlayerWait::PlayerWait()
{
	m_Wait = new PlayerWaitPattern;
}

PlayerWait::~PlayerWait()
{
	delete m_Wait;
}

void PlayerWait::Update(Player* p)
{
	m_Wait->Update(p);
}

void PlayerWaitPattern::Update(Player* p)
{
	
}
