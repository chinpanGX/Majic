/*-------------------------------------------------------------
	
	[PlayerEditor.h]
	Author : 出合翔太

	[説明]
	プレイヤーの情報の管理、編集をする

--------------------------------------------------------------*/
#pragma once

class PlayerEditor
{
public:
	PlayerEditor();
	~PlayerEditor();
	void Update();
	
	//プロパティ
	// 行動の可否
	bool GetIsAction() { return m_IsAction; }
	void SetIsAction(bool b) { m_IsAction = b; }
	// AP
	unsigned __int32 GetAp() { return m_ActionPoint; }
	void SetAp(unsigned __int32 ap) { m_ActionPoint = ap; }

private:
	bool m_IsAction;				// 行動できるかどうか

	unsigned __int32 m_ActionPoint; // Ap
	unsigned __int32 m_MaxAp;		// APの最大値
	
	int m_Waittime;	// 行動できない時間
	int m_MaxWaitTime; // 待ち時間の最大値
};

