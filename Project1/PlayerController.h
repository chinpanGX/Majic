/*-------------------------------------------------------------

	[Controller.h]
	Author : 出合翔太

	[説明]
	プレイヤーの入力処理

--------------------------------------------------------------*/
#pragma once

class PlayerController
{
public:
	void Update(class Player& player);
	bool IsSkillSelection(); // スキルを選択中かどうか
private:
	void Attack(class Player& player);	// 攻撃		〇
	void Guard(class Player& player);	// ガード	△
	void Skill_1(class Player& player); // スキル１ R1＋△
	void Skill_2(class Player& player); // スキル２ R1＋〇
	void Skill_3(class Player& player); // スキル３ R1＋□
	void Skill_4(class Player& player); // スキル４ R1＋×
};

