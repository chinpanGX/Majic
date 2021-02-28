#include "PlayerGurad.h"
#include "Player.h"
#include "PlayerEditor.h"

PlayerGurad::PlayerGurad()
{
	m_Guard = std::make_unique<PlayerGuardPattern>();
}

PlayerGurad::~PlayerGurad()
{
}

void PlayerGurad::Update(Player* p)
{
	m_Guard->Update(p);
}

void PlayerGuardPattern::Update(Player* p)
{
}

