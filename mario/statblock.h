#pragma once
#include <cstdint>
#include "buff.h"
#include <vector>
#include "types.h"
class StatBlock {
	stattype BaseStrength;
	stattype BaseIntellect;
	stattype BaseAgility;
	stattype BaseArmor;
	stattype BaseElementRes;

	stattype TotalStrengthFromStrength=0;
	stattype TotalIntellectFromBaseIntellect=0;
	stattype TotalAgilityFromBaseAgility=0;
	stattype TotalArmorFromBaseArmor=0;
	stattype TotalResFromBaseElementRes=0;

public:
	explicit StatBlock(stattype s = 1, stattype i = 1, stattype a = 1, stattype arm = 0, stattype elres = 0) {
		BaseStrength = s;
		BaseIntellect = i;
		BaseAgility = a;
		BaseArmor = arm;
		BaseElementRes = elres;
	}
	stattype getStrength() { return BaseStrength; }
	stattype getIntellect() { return BaseIntellect; }
	stattype getAgility() { return BaseAgility; }
	stattype getArmor() { return BaseArmor; }
	stattype getElementRes() { return BaseElementRes; }
	
	stattype getTotalStrength() { return TotalStrengthFromStrength; }
	stattype getTotalIntellect() { return TotalIntellectFromBaseIntellect; }
	stattype getTotalAgility() { return TotalAgilityFromBaseAgility; }
	stattype getTotalArmor() { return TotalArmorFromBaseArmor; }
	stattype getTotalElementRes() { return TotalResFromBaseElementRes; }

protected:
	void addNewBuff(Buff b) {
		for (auto& buff : Buffs) {
			if (b.Name==buff.Name)
			{
				buff.Duration = b.Duration;
				return;


			}
			Buffs.push_back(b);
			recalculate_buffs();
		}
	}
	std::vector<Buff>Buffs;

	
	void increaseStats(stattype s = 0, stattype i = 0, stattype a = 0, stattype arm = 0, stattype elres = 0) {
		BaseStrength += s;
		BaseIntellect += i;
		BaseAgility += a;
		BaseArmor += arm;
		BaseElementRes += elres;
	}
private:
	void recalculate_buffs() {
		stattype totalstrenfthfrombuffs     = 0;
		stattype totalintellectfrombuffs    = 0;
		stattype totalagilityfrombuffs     = 0;
		stattype totalarmorfrombuffs       = 0;
		stattype totalelementresfrombuffs	 = 0;

		for (auto const& b : Buffs) {
			if (b.isDebuff)
			{
				totalstrenfthfrombuffs -= 0;
				totalintellectfrombuffs -= 0;
				 totalagilityfrombuffs -= 0;
				 totalarmorfrombuffs -= 0;
				 totalelementresfrombuffs -= 0;

			}
		}
		TotalStrengthFromStrength= totalstrenfthfrombuffs;
		TotalIntellectFromBaseIntellect = totalintellectfrombuffs;
		TotalAgilityFromBaseAgility = totalagilityfrombuffs;
		TotalArmorFromBaseArmor = totalarmorfrombuffs;
		TotalResFromBaseElementRes = totalelementresfrombuffs;
		if (TotalStrengthFromStrength < 0)TotalStrengthFromStrength = 0;
		if (TotalIntellectFromBaseIntellect < 0)TotalIntellectFromBaseIntellect = 0;
		if (TotalAgilityFromBaseAgility < 0)TotalAgilityFromBaseAgility = 0;
		if (TotalArmorFromBaseArmor < 0)TotalArmorFromBaseArmor = 0;
		if (TotalResFromBaseElementRes < 0)TotalResFromBaseElementRes = 0;


	}
};