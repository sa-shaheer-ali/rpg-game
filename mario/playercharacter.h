#pragma once
#include <cstdint>
#include "statblock.h"
#include "pointwell.h"
#include <memory>
#include <string>
typedef std::uint64_t extype;
typedef std::int16_t leveltype;
class PlayerCharacterDelegate: public Statblock ,public Pointwell{
public:

	static const extype LEVEL2At = 100u;
	PlayerCharacterDelegate(): Statblock(0u,0u) {
		CurrentLevel = 1u;
		CurrentEXP = 0u;
		EXPToNextLevel = LEVEL2At;
		HP = std::make_unique<Pointwell>();

	}
	extype gainEXP(extype EX) {
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
	void gainEXP(extype exp) {
		 CurrentEXP += exp;
		 while (check_if_leveled()){
		 }
		 
		
	}
	virtual void LevelUP() = 0;
	virtual std::string getClassName() = 0;


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
std::unique_ptr <Pointwell>HP;



class Cleric : public PlayerCharacterDelegate {
public:
	static const welltype BASEHP = (welltype)14u;
	static const stattype BaseStr = (stattype)2u;
	static const stattype BaseInt = (stattype)3u;



	Cleric() :PlayerCharacterDelegate() {
		HP->setMax(BASEHP);
		HP->increase(BASEHP);
		increasestat(BaseStr, BaseInt);
	}
	std::string getClassName() override {return std::string("Cleric");}
private:
	//dividing by 2 to update the hp  for next level

	virtual void LevelUP()override {
		HP->setMax((welltype)((BASEHP/2) + HP->getMax()));
		//using base/2 for the same thing
		//adding +1 bcz  if there is an od case it will came back toit orignal number so increaseing by +1 (41:29)
		increasestat((stattype)((BaseStr+1u)/2.f), (stattype)((BaseInt+1u)/2.f));
	}

};
class PlayerCharacter {
private:
	PlayerCharacterDelegate* pcclass;
	public:
	PlayerCharacter() = delete;
	PlayerCharacter(PlayerCharacterDelegate * pc):pcclass(pc){}



	std::string getClassName() { pcclass->getClassName(); }
	leveltype getcurrentlvl() { pcclass->getcurrentlvl(); }
	extype getcurrentexp() { pcclass->getcurrentexp(); }
	extype getexptonextlvl() { pcclass->getexptonextlvl(); }
	welltype getcurrenthp() { pcclass->getcurrent(); }
	welltype getmax() { pcclass->getMax(); };
	stattype getstrength() { pcclass->getstr(); }
	stattype getintellect() { pcclass->getint();}
	void gainEXP(extype exp) { pcclass->gainEXP(exp); }
	void takeDamage(welltype amt) { pcclass->decrease(amt); }
	void heal(welltype amt) { pcclass->increase(amt); }










};