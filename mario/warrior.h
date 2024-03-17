#pragma once

#include "hp.cpp"
#include "statblock.h"
class Warrior :public hp, public Statblock{
public:
	static const hptype HPGROWTH = 19u;
	static const stattype BaseStr = (stattype)4u;
	static const stattype BaseInt = (stattype)1u;



	Warrior() :hp(HPGROWTH,HPGROWTH),Statblock(BaseStr,BaseInt){}
private:

};