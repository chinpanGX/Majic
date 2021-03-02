/*-------------------------------------------------------------

	[Controller.h]
	Author : o‡ãÄ‘¾

	[à–¾]
	ƒvƒŒƒCƒ„[‚Ì

--------------------------------------------------------------*/
#pragma once
#include <memory>

class PlayerController
{
public:
	PlayerController();
	~PlayerController();
	void Update(class Player* player);
	bool IsSkillSelection(); // ƒXƒLƒ‹‚ğ‘I‘ğ’†‚©‚Ç‚¤‚©
private:
	void Attack(class Player* player);	// UŒ‚		Z
	void Guard(class Player* player);	// ƒK[ƒh	¢
	void Skill_1(class Player* player);	// ƒXƒLƒ‹‚P R1{¢
	void Skill_2(class Player* player);	// ƒXƒLƒ‹‚Q R1{Z
	void Skill_3(class Player* player);	// ƒXƒLƒ‹‚R R1{ 
	void Skill_4(class Player* player);	// ƒXƒLƒ‹‚S R1{~
	
	template<typename T>
	void SetPattern();
	void ChangePattern(class PlayerPatternManager* p);

	std::unique_ptr<class PlayerPatternManager> m_pPattern;
};
