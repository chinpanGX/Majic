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
	const unsigned __int32 g_CountUpperLimit = 3; // �X�e�[�g�̃J�E���g���
}

class IStateConfig
{
public:
	IStateConfig(){}
	virtual ~IStateConfig(){}
	virtual void SetActive() = 0;
protected:
	std::shared_ptr<StateSwitch> m_State[g_CountUpperLimit];	// �o�^����X�e�[�g��[]
	std::string m_Name[g_CountUpperLimit]; // �o�^��
	unsigned __int32 m_Count;	// ������
	bool m_EnableThis;			// �L�����ǂ���
};