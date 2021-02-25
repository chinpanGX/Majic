/*-------------------------------------------------------------

	[Controller.h]
	Author : 出合翔太

	[説明]
	プレイヤーの入力処理

--------------------------------------------------------------*/
#pragma once
#include "Player.h"

class PlayerController
{
public:
	PlayerController() {}
	void Update(Player* player);
	bool IsSkillSelection(); // スキルを選択中かどうか
private:
	void Attack(Player* player);	// 攻撃		〇
	void Guard(Player* player);		// ガード	△
	void Skill_1(Player* player);	// スキル１ R1＋△
	void Skill_2(Player* player);	// スキル２ R1＋〇
	void Skill_3(Player* player);	// スキル３ R1＋□
	void Skill_4(Player* player);	// スキル４ R1＋×
};

