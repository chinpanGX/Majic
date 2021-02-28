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
	void Update(const class Player& player);
	bool IsSkillSelection(); // ƒXƒLƒ‹‚ğ‘I‘ğ’†‚©‚Ç‚¤‚©
private:
	void Attack(const class Player& player);	// UŒ‚		Z
	void Guard(const class Player& player);	// ƒK[ƒh	¢
	void Skill_1(const class Player& player);	// ƒXƒLƒ‹‚P R1{¢
	void Skill_2(const class Player& player);	// ƒXƒLƒ‹‚Q R1{Z
	void Skill_3(const class Player& player);	// ƒXƒLƒ‹‚R R1{ 
	void Skill_4(const class Player& player);	// ƒXƒLƒ‹‚S R1{~
	
	template<typename T>
	void SetPattern(const class Player& p);
	void ChangePattern(class PlayerPatternManager* p);

	std::unique_ptr<PlayerPatternManager> m_pPattern;
};
