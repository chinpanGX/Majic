/*-------------------------------------------------------------
	
	[PlayerEditor.h]
	Author : �o���đ�

	[����]
	�v���C���[�̏��̊Ǘ��A�ҏW������

--------------------------------------------------------------*/
#pragma once

class PlayerEditor
{
public:
	PlayerEditor();
	~PlayerEditor();
	void Update();
	
	//�v���p�e�B
	// �s���̉�
	bool GetIsAction() { return m_IsAction; }
	void SetIsAction(bool b) { m_IsAction = b; }
	// AP
	unsigned __int32 GetAp() { return m_ActionPoint; }
	void SetAp(unsigned __int32 ap) { m_ActionPoint = ap; }

private:
	bool m_IsAction;				// �s���ł��邩�ǂ���

	unsigned __int32 m_ActionPoint; // Ap
	unsigned __int32 m_MaxAp;		// AP�̍ő�l
	
	int m_Waittime;	// �s���ł��Ȃ�����
	int m_MaxWaitTime; // �҂����Ԃ̍ő�l
};

