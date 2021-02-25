/*-------------------------------------------------------------

	[StateMachine.cpp]
	Author : �o���đ�

	[����]
	StateSwtich		: �X�e�[�g�ύX
	StateMachine	: �X�e�[�g�̊Ǘ����o�^�A�폜

--------------------------------------------------------------*/
#include "StateMachine.h"
#include <iostream>

#pragma region StateSwitch_Func
// Update�̑O�ɌĂ�
void StateSwitch::Start()
{
	m_State->Start();
}

void StateSwitch::Update(Pawn* pawn)
{
	m_State->Update(pawn);
}

// ���̃X�e�[�g�ɂ����邩�`�F�b�N
bool StateSwitch::IsNextState()
{

	if (m_State->GetIsNext() == true)
	{
		m_State->ChangeEvent();
		return true;
	}
	return false;
}
#pragma endregion StateSwitch�̊֐���`

#pragma region StateMachine_Func
// �X�V
void StateMachine::Update(Pawn* pawn)
{
	m_NowState->Update(pawn);
	if (m_NowState->IsNextState())
	{
		auto it = m_StateMap.find(m_NowState->m_NextRegisterName);
		if (it == m_StateMap.end())
		{
			return;
		}
		m_NowState = it->second;
		m_NowState->Start();
	}
}

// �ŏ��̃X�e�[�g��ݒ�
void StateMachine::SetStartState(const std::string& registerName)
{
	auto it = m_StateMap.find(registerName);
	if (it == m_StateMap.end())
	{
		return;
	}
	std::cout << "StateMachine : " << it->first << "���X�^�[�g�ɐݒ�" << std::endl;
	m_NowState = it->second;
	m_NowState->Start();
}

// �X�e�[�g�̓o�^
void StateMachine::Register(const std::string& name, const std::shared_ptr<StateSwitch> state)
{
	m_StateMap.insert(std::make_pair(name, state));
	std::cout << "StateMachine : " << name << "��o�^" << std::endl;
}

// �w�肵���X�e�[�g�̍폜
void StateMachine::Delete(const std::string& registerName)
{
	auto it = m_StateMap.find(registerName);
	if (it == m_StateMap.end())
	{
		return;
	}
	std::cout << "StateMachine : " << it->first << "���폜����" << std::endl;
	m_StateMap.erase(it);
}

// ���ׂč폜
void StateMachine::Delete()
{
	std::cout << "StateMachine : " << "���ׂč폜����" << std::endl;
	m_StateMap.clear();
}
#pragma endregion StateMachine�̊֐�