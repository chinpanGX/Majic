#include "PlayerEditor.h"


PlayerEditor::PlayerEditor() : m_MaxWaitTime(60), m_MaxAp(30), m_Waittime(10), m_ActionPoint(30), m_IsAction(false)
{
	
}

PlayerEditor::~PlayerEditor()
{
}

void PlayerEditor::Update()
{
	m_Waittime--;
	// APが最大値を超えないように最大値で固定
	if (m_ActionPoint > m_MaxAp)
	{
		m_ActionPoint = m_MaxAp;
	}

	// 待ち時間が最大値を超えないように最大値で固定
	if (m_Waittime > m_MaxWaitTime)
	{
		m_Waittime = m_MaxWaitTime;
	}

	// 待ち時間が0になったら行動できる
	if (m_Waittime <= 0)
	{
		m_IsAction = true;
		m_Waittime = 0;
	}
	else
	{
		m_IsAction = false;
	}
}
