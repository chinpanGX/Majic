/*-------------------------------------------------------------

	[StateMachine.cpp]
	Author : 出合翔太

	[説明]
	StateSwtich		: ステート変更
	StateMachine	: ステートの管理→登録、削除

--------------------------------------------------------------*/
#include "StateMachine.h"
#include <iostream>

#pragma region StateSwitch_Func
// Updateの前に呼ぶ
void StateSwitch::Start()
{
	m_State->Start();
}

void StateSwitch::Update(Pawn* pawn)
{
	m_State->Update(pawn);
}

// 次のステートにいけるかチェック
bool StateSwitch::IsNextState()
{

	if (m_State->GetIsNext() == true)
	{
		m_State->ChangeEvent();
		return true;
	}
	return false;
}
#pragma endregion StateSwitchの関数定義

#pragma region StateMachine_Func
// 更新
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

// 最初のステートを設定
void StateMachine::SetStartState(const std::string& registerName)
{
	auto it = m_StateMap.find(registerName);
	if (it == m_StateMap.end())
	{
		return;
	}
	std::cout << "StateMachine : " << it->first << "をスタートに設定" << std::endl;
	m_NowState = it->second;
	m_NowState->Start();
}

// ステートの登録
void StateMachine::Register(const std::string& name, const std::shared_ptr<StateSwitch> state)
{
	m_StateMap.insert(std::make_pair(name, state));
	std::cout << "StateMachine : " << name << "を登録" << std::endl;
}

// 指定したステートの削除
void StateMachine::Delete(const std::string& registerName)
{
	auto it = m_StateMap.find(registerName);
	if (it == m_StateMap.end())
	{
		return;
	}
	std::cout << "StateMachine : " << it->first << "を削除する" << std::endl;
	m_StateMap.erase(it);
}

// すべて削除
void StateMachine::Delete()
{
	std::cout << "StateMachine : " << "すべて削除する" << std::endl;
	m_StateMap.clear();
}
#pragma endregion StateMachineの関数