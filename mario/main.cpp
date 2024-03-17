#include "allclasses.h"
#include <iostream>
int main() {

	Cleric cl1;
	for (int i = 0; i < 2; i++)
	{
		std::cout << "Cleric \n"
			<< "-level" << cl1.getcurrentlvl() << std::endl
			<< "-MaxHp:" << cl1.getMaxHp() << std::endl
			<< "-Strength:" << cl1.getstr() << std::endl
			<< "-Intellect:" << cl1.getint() << std::endl
			<< "-EXP" << cl1.getcurrentexp() << "/" << cl1.getexptonextlvl() << '\n';
		cl1.gainEXP(100);

	}
		return 0;
}