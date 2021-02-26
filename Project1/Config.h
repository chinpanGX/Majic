/*----------------------------------------------
	
	[Config.h]
	Author : �o���đ�

	[����]
	�O���[�o���ϐ��̊Ǘ�

-----------------------------------------------*/
#pragma once
#include "StateMachine.h"

namespace
{
	const unsigned __int32 g_CountUpperLimit = 2; // �X�e�[�g�̃J�E���g���
}

class IPlayerState
{
public:
	IPlayerState(){}
	virtual ~IPlayerState(){}
	virtual void SetActive() = 0;
	bool GetEnable() { return m_EnableThis; }
protected:
	std::shared_ptr<StateSwitch> m_State[g_CountUpperLimit];	// �o�^����X�e�[�g��[]
	std::string m_Name[g_CountUpperLimit]; // �o�^��
	unsigned __int32 m_Count;	// ������
	bool m_EnableThis;			// �L�����ǂ���
};