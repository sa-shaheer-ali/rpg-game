#pragma once
#include<cstdint>
typedef std::uint16_t stattype;

class Statblock {
public:
	stattype strength;
	stattype intellect;
	Statblock() {
		strength =(stattype) 1u;
		intellect = (stattype)2u;
	}

	explicit Statblock(stattype str,stattype inte): strength(str),intellect(inte){}
	stattype getstr() {
		return strength;

	}
	stattype getint() {
		return intellect;

	}
	stattype increasestat(stattype strgrowth, stattype intgrowth) {
		return strength += strgrowth;
		return intellect += intgrowth;

	}

};