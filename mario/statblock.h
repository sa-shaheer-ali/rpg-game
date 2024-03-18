#pragma once
#include<cstdint>
typedef std::uint16_t stattype;

class Statblock {
public:
	stattype strength;
	stattype intellect;
	Statblock() {
		strength =(stattype) 1u;
		intellect = (stattype)1u;
	}

	explicit Statblock(stattype str,stattype inte): strength(str),intellect(inte){}
	stattype getstr() {
		return strength;

	}
	stattype getint() {
		return intellect;

	}
	bool increasestat(stattype strgrowth, stattype intgrowth) {
		 strength += strgrowth;
		 intellect += intgrowth;
		 return true;

	}

};