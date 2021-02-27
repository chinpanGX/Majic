/*-------------------------------------------------------------

	[Controller.h]
	Author : o‡ãÄ‘¾

	[à–¾]
	ƒvƒŒƒCƒ„[‚Ì“ü—Íˆ—

--------------------------------------------------------------*/
#pragma once

class PlayerController
{
public:
	PlayerController(class Player* player);
	~PlayerController();
	void Update(class Player* player);
	bool IsSkillSelection(); // ƒXƒLƒ‹‚ğ‘I‘ğ’†‚©‚Ç‚¤‚©
private:
	void Attack(class Player* player);	// UŒ‚		Z
	void Guard(class Player* player);		// ƒK[ƒh	¢
	void Skill_1(class Player* player);	// ƒXƒLƒ‹‚P R1{¢
	void Skill_2(class Player* player);	// ƒXƒLƒ‹‚Q R1{Z
	void Skill_3(class Player* player);	// ƒXƒLƒ‹‚R R1{ 
	void Skill_4(class Player* player);	// ƒXƒLƒ‹‚S R1{~

	template<typename T>
	void SetPattern(class Player* p);
	void ChangePattern(class PlayerPattern* p);

	class PlayerPattern* m_pPattern;
};
