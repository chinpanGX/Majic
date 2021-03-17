/*-------------------------------------------------------------

	[Player.h]
	Author : 出合翔太

	[説明]
	Player : プレイヤーの処理をまとめる

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
	// APを増加
	void Ap_Add(__int32 ap) { m_ActionPoint += ap; }
	// APを消費
	void AP_Comsume(__int32 ap) { m_ActionPoint -= ap; }
	
	//　待ち時間の追加
	void WaitTime_Add(__int32 wait) { m_WaitTime += wait; }
	
	const std::shared_ptr<class PlayerController> GetController()const { return m_Controller; }
	
	// 行動の可否
	bool GetIsAction() { return IsAction(); }
	void SetIsAction(bool b) { m_IsAction = b; }
	
	// AP
	const __int32 GetAp() const { return AP(); }
	const void SetAp(__int32 ap) { m_ActionPoint -= ap; }

	// プロパティ
	const int32_t& AP()const { return m_ActionPoint; }
	const bool& IsAction()const { return m_IsAction; }
private:
	std::shared_ptr<class PlayerController> m_Controller; // 入力処理を管理

	bool m_IsAction;				// 行動できるかどうか

	__int32 m_ActionPoint; // Ap
	__int32 m_MaxAp;		// APの最大値

	__int32 m_MaxWaitTime;	// 待ち時間の最大値
};

