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

void PlayerGurad::Update(const Player& p)
{
	m_Guard->Update(p);
}

void PlayerGuardPattern::Update(const Player& p)
{
}

