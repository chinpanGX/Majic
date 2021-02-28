/*-----------------------------------------------
	
	[PlayerState.h]
	Author : �o���đ�

------------------------------------------------*/
#pragma once

namespace
{
	const __int32 g_StateIndex = 3; // �X�e�[�g�̔z��̐��E���g���
}

	const unsigned __int32 g_CountUpperLimit = 2; // �X�e�[�g�̃J
class PlayerPatternManager
{
public:
	virtual ~PlayerPatternManager(){}
	virtual void Update(const class Player& p) = 0;
	bool GetEnable() { return m_EnableThis; }
protected:
	unsigned __int32 m_Count;	// ������
	bool m_EnableThis;			// �L�����ǂ���
};

class PlayerPattern
{
public:
	virtual ~PlayerPattern() {}
	virtual void Update(const class Player& p) = 0;
protected:
	unsigned __int32 m_tmpAp; // AP���ꎞ�ۑ�
};

class PlayerPatternNone : public PlayerPattern
{
public:
	virtual ~PlayerPatternNone(){}
	virtual void Update(const class Player& p)override{}
};
