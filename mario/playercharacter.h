#pragma once
#include "statblock.h"
#include "pointwell.h"
#include "ability.h"
#include <cstdint>
#include <string>
#include <vector>
#define BaseStr 10
#define BaseInt 8
#define BaseAgi 5

typedef std::uint64_t extype;
typedef std::int16_t leveltype;
class PlayerCharacterDelegate: public Statblock{
public:

	static const extype LEVEL2AT = 100u;

	PlayerCharacterDelegate(): Statblock(0u,0u,0u) {
		CurrentLevel = 1u;
		CurrentEXP = 0u;
		EXPToNextLevel = LEVEL2AT;
		HP = (welltype)1u;
		

	}
	void gainEXP(extype EX) {
		CurrentEXP += EX;
		while (check_if_leveled()) {}
	
		
	}
	leveltype getcurrentlvl() {
		return CurrentLevel;
	}
	extype getcurrentexp() {
		return CurrentEXP;
	}
	extype getexptonextlvl() {
		return EXPToNextLevel;

	}
	

	virtual void LevelUP() = 0;
	virtual std::string getClassName() = 0;

	Pointwell HP;
	Pointwell* MP;
	std::vector <Ability> abilities;


protected:
	leveltype CurrentLevel;
	extype CurrentEXP;
	extype EXPToNextLevel;
	bool check_if_leveled() {
		static const leveltype LevelScaler = 2u;
		if (CurrentEXP>=EXPToNextLevel)
		{
			CurrentLevel++;
			LevelUP();
			EXPToNextLevel *= LevelScaler;
			return true;
		}
		return false;
	}
};

#define PCCONSTRUCT  \
HP.setMax(BASEMP);\
HP.increase(BASEMP);\
    increasestat(BaseStr, BaseInt, BaseAgi);

#define LEVELUP  \
     HP.setMax(((BASEMP / 2.f) + MP->getMax()));\
    HP.increase((welltype)(BASEMP / 2.f));\
    increasestat((stattype)((BaseStr + 1u) / 2.f), (stattype)((BaseInt + 1u) / 2.f), (stattype)((BaseAgi + 1u) / 2.f));\
}


class Cleric : public PlayerCharacterDelegate {
public:
    static const welltype BASEMP = (welltype)14;
    static const stattype BASESTR = (stattype)3;
    static const stattype BASEINT = (stattype)5;
    static const stattype BASEAGI = (stattype)1;
	static const welltype BASEMP = (welltype)10u;
	 
	std::string getClassName() override { return std::string("Cleric"); }
	Cleric() : PlayerCharacterDelegate() {
		PCCONSTRUCT
			MP = new Pointwell();
    MP.setMax(BASEMP);
    MP.increase(BASEMP);
	abilities.emplace_back("heal", 2u, 1u, ABILITYTARGET::ALLY, 2u,ABILITYSCALER::INT);
	}
		Pointwell *MP;
private:
	void LevelUP() override {
		LEVELUP
			MP.setMax((welltype)((BASEMP / 2.f) + MP->getMax())); 
			MP.increase((welltype)(BASEMP / 2.f)); 
			if (CurrentLevel==2)
			{

			}
			else {}
	}
};



class PlayerCharacter {
private:
	PlayerCharacterDelegate* pcclass;
public:
	PlayerCharacter() = delete;
	PlayerCharacter(PlayerCharacterDelegate* pc) :pcclass(pc) {}
	~PlayerCharacter() { delete pcclass; pcclass = nullptr; }


	std::string getClassName() { return  pcclass->getClassName(); }
	leveltype getcurrentlvl() { return  pcclass->getcurrentlvl(); }
	extype getcurrentexp() { return pcclass->getcurrentexp(); }
	extype getexptonextlvl() { return pcclass->getexptonextlvl(); }
	welltype getcurrent() { return  pcclass->HP.getcurrent(); }
	welltype getmax() { return pcclass->HP.getMax(); };
	stattype getstrength() { return pcclass->getstr(); }
	stattype getintellect() { return pcclass->getint(); }
	stattype getagli() { return pcclass->getagl(); }
	stattype getarmo() { return pcclass->getarm(); }
	stattype getelemet() { return pcclass->getelem(); }
	std::vector <Ability> getabilities() { return pcclass->abilities; }
	void gainEXP(extype exp) { pcclass->gainEXP(exp); }
	void takeDamage(welltype amt) { pcclass->HP.decrease(amt); }
	//void heal(welltype amt) { pcclass->MP->heal(amt); }


};