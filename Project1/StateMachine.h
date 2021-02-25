/*-------------------------------------------------------------
	
	[StateMachine.h]
	Author : �o���đ�

	[�N���X����]
	StateBase	 :	�X�e�[�g�̊��N���X
	StateSwitch:	�X�e�[�g�̕ύX����N���X
	StateMachine :	�X�e�[�g�Ǘ��N���X

--------------------------------------------------------------*/
#pragma once
#include <unordered_map>
#include <string>
#include <memory>
#include <Windows.h>
#include "Pawn.h"

class StateBase
{
public:
	StateBase() : m_IsNext(false) {}
	virtual void Start() = 0;
	virtual void Update(class Pawn* pawn) = 0;
	virtual void ChangeEvent() = 0;	// �X�e�[�g���ς��Ƃ��̏���
	// �v���p�e�B
	bool GetIsNext() const { return m_IsNext; } // Getter
	void SetIsNext(bool f) { m_IsNext = f; }
	unsigned __int32 GetCostAp() { return m_CostAp; }
	void SetCostAp(unsigned __int32 p) { m_CostAp = p; }
protected:
	bool m_IsNext; // �؂�ւ�����
	unsigned __int32 m_CostAp; // AP�̏���R�X�g
};

// �X�e�[�g�̐؂�ւ�
class StateSwitch
{
public:
	StateSwitch() = default;
	StateSwitch(const std::shared_ptr<StateBase> state, const std::string nextRegisterName) : m_State(state), m_NextRegisterName(nextRegisterName) {}
	void Start();
	void Update(class Pawn* pawn);
	bool IsNextState();
	std::shared_ptr<StateBase> GetState()const { return m_State; }

	const std::string m_NextRegisterName;

private:
	std::shared_ptr<StateBase> m_State;

};

// �X�e�[�g�Ǘ�
class StateMachine
{
public:
	StateMachine() : m_NowState() {}
	void Update(class Pawn * pawn);
	void SetStartState(const std::string& registerName);
	void Register(const std::string& name, const std::shared_ptr<StateSwitch> state);
	void Delete(const std::string& registerName);
	void Delete();
private:
	std::unordered_map<std::string, std::shared_ptr<StateSwitch>> m_StateMap;
	std::shared_ptr<StateSwitch> m_NowState;
};

