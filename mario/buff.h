#pragma once
#include <string>
#include "statblock.h"
#include "types.h"

struct  Buff {
	Buff(const char* n, uint16_t dur=2u, stattype str=0, stattype intel=0, stattype agl=0,
		stattype arm=0, stattype elem=0,bool isdebuff=false) :Name(n), Duration(dur), BaseStrength(str),
		BaseIntellect(intel), BaseAgility(agl), BaseArmor(arm), BaseElementRes(elem),isDebuff(isdebuff){}


	std::string Name;
	uint16_t Duration;

	stattype BaseStrength;
	stattype BaseIntellect;
	stattype BaseAgility;
	stattype BaseArmor;
	stattype BaseElementRes;
	bool isDebuff;

};
