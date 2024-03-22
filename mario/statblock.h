#pragma once
#include<cstdint>
typedef std::uint16_t stattype;

class Statblock {
public:
	stattype strength;
	stattype intellect;
	stattype agility;
	stattype armor;
	stattype elmenetres;

	//this is the default constructor:)
	explicit Statblock(stattype str = 1, stattype inte = 1, stattype agil = 1, stattype arm = 0, stattype elem = 0)
		: strength(str), intellect(inte), agility(agil), armor(arm), elmenetres(elem) {}
	stattype getstr() { return strength; }
	stattype getint() { return intellect; }
	stattype getagl() { return agility; }
	stattype getarm(){return armor; }
	stattype getelem(){return elmenetres;}
	void increasestat(stattype strgrowth=0, stattype intgrowth=0,stattype agilgrowth=0,stattype armorgrowth=0,stattype elemgrowth=0) {
		 strength += strgrowth;
		 intellect += intgrowth;
		 agility += agilgrowth;
		 armor += armorgrowth;
		 elmenetres += elemgrowth;

	}

};