/*-------------------------------------------------------------

	[Player.h]
	Author : �o���đ�

	[����]
	Player : �v���C���[�̏������܂Ƃ߂�

--------------------------------------------------------------*/
#pragma once
#include "Pawn.h"
#include <memory>

class Player : public Pawn
{
public:
	Player();
	~Player(){}
	void Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
	// AP�𑝉�
	void Ap_Add(__int32 ap) { m_ActionPoint += ap; }
	// AP������
	void AP_Comsume(__int32 ap) { m_ActionPoint -= ap; }
	
	//�@�҂����Ԃ̒ǉ�
	void WaitTime_Add(__int32 wait) { m_WaitTime += wait; }
	
	const std::shared_ptr<class PlayerController> GetController()const { return m_Controller; }
	
	// �s���̉�
	bool GetIsAction() { return IsAction(); }
	void SetIsAction(bool b) { m_IsAction = b; }
	
	// AP
	const __int32 GetAp() const { return AP(); }
	const void SetAp(__int32 ap) { m_ActionPoint -= ap; }

	// �v���p�e�B
	const unsigned __int32& AP()const { return m_ActionPoint; }
	const bool& IsAction()const { return m_IsAction; }
private:
	std::shared_ptr<class PlayerController> m_Controller; // ���͏������Ǘ�

	bool m_IsAction;				// �s���ł��邩�ǂ���

	__int32 m_ActionPoint; // Ap
	__int32 m_MaxAp;		// AP�̍ő�l

	__int32 m_MaxWaitTime;	// �҂����Ԃ̍ő�l
};

