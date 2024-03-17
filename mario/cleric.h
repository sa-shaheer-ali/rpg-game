#pragma once

#include "hp.cpp"
#include "statblock.h"
#include "leveluptypes.h"
class Cleric :public hp, public Statblock,public LevelSystem {
public:
	static const hptype BASEHP = (hptype)14u;
	static const stattype BaseStr = (stattype)2u;
	static const stattype BaseInt = (stattype)3u;

	static const hptype HPGROWTH = 7u;
	static const stattype STRGROWTH = 1u;
	static const stattype INTGROWTH = 2u;



	Cleric() :hp(BASEHP, BASEHP), Statblock(BaseStr, BaseInt) {}
private:
	virtual void LevelUP()override {
		setMaxHP(HPGROWTH + getMaxHp());
		increasestat(STRGROWTH, INTGROWTH);
	}

};