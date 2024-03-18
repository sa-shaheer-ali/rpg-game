#include "allclasses.h"
#include <iostream>
#include "playercharacter.h"
int main() {

	PlayerCharacter p1(new Cleric());
	for (int i = 0; i < 2; i++)
	{
		std::cout <<p1.getClassName()
			<< "-level" << p1.getcurrentlvl() << std::endl
			<< "-MaxHp:" << p1.getmax() << std::endl
			<< "-Strength:" << p1.getstrength() << std::endl
			<< "-Intellect:" << p1.getintellect() << std::endl
			<< "-EXP" << p1.getcurrentexp() << "/" << p1.getexptonextlvl() << '\n';
		p1.gainEXP(100);

	}
		return 0;
}