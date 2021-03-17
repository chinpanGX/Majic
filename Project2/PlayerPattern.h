/*-----------------------------------------------
	
	[PlayerState.h]
	Author : �o���đ�

------------------------------------------------*/
#pragma once

namespace
{
	const __int32 g_StateIndex = 3; // �X�e�[�g�̔z��̐��E���g���
	const int32_t g_CountUpperLimit = 3; // �X�e�[�g�̃J
}

class PlayerPatternManager
{
public:
	virtual ~PlayerPatternManager(){}
	virtual void Update(class Player* p) = 0;
	bool GetEnable() { return m_EnableThis; }
protected:
	int32_t m_Count;	// ������
	bool m_EnableThis;			// �L�����ǂ���
};

class PlayerPattern
{
public:
	virtual ~PlayerPattern() {}
	virtual void Update(class Player* p) = 0;
protected:
};

class PlayerPatternNone : public PlayerPattern
{
public:
	virtual ~PlayerPatternNone(){}
	virtual void Update(class Player* p)override{}
};
