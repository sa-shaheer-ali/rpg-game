#pragma once
#include <cstdint>
typedef std::uint64_t extype;
typedef std::int16_t leveltype;
class LevelSystem {
public:

	static const extype LEVEL2At = 2u;
	LevelSystem() {
		CurrentLevel = 1u;
		CurrentEXP = 0u;
		EXPToNextLevel = LEVEL2At;

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
	extype gainEXP(int exp) {
		 CurrentEXP += exp;
		 while (check_if_leveled())
		 {
			 if (CurrentEXP< check_if_leveled())
			 {
				 break;

			 }
		 }
		 return CurrentEXP;
	}
	virtual void LevelUP() = 0;

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