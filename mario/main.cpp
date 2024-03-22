
#include <iostream>
#include "playercharacter.h"
int main() {

	PlayerCharacter p1(new Warrior());
	for (int i = 0; i < 2; i++)
	{
		std::cout <<p1.getClassName()<<std::endl
			<< "-level:" << p1.getcurrentlvl() << std::endl
			<< "-MaxHp:" <<  p1.getcurrent()<< std::endl
			<< "-Strength:" << p1.getstrength() << std::endl
			<< "-Intellect:" << p1.getintellect() << std::endl
			<< "-EXP:" << p1.getcurrentexp() << "/" << p1.getexptonextlvl() << '\n'<<
			"Agility"<<p1.getagli() << '\n' <<
			"Armor"<<p1.getarmo() << '\n' <<
			"Resist"<<p1.getelemet() << '\n';
		auto ALLAbilities = p1.getabilities();
		for (auto &abil:ALLAbilities)
		{
			std::cout << " -" << abil.name << '\n';

		}
		p1.gainEXP(100);

	}
		return 0;
}