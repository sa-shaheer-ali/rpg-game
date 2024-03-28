#pragma once
#include "types.h"
struct CoreStats {
	stattype Strength;
	stattype Intellect;
	stattype Agility;
	stattype Armor;
	stattype ElementRes;
	CoreStats& operator +=(const CoreStats& rhs) {
		this->Strength += rhs.Strength;
		this->Intellect += rhs.Intellect;
		this->Agility += rhs.Agility;
		this->Armor += rhs.Armor;
		this->ElementRes += rhs.ElementRes;
		return *this;

	};
	CoreStats& operator -=(const CoreStats& rhs) {
		CoreStats tmp = *this;
		this->Strength -= rhs.Strength;
		this->Intellect -= rhs.Intellect;
		this->Agility -= rhs.Agility;
		this->Armor -= rhs.Armor;
		this->ElementRes -= rhs.ElementRes;
		return *this;

		if (this->Strength > tmp.Strength)this->Strength = 0u;
		if (this->Intellect > tmp.Intellect)this->Intellect = 0u;
		if (this->Agility > tmp.Agility)this->Agility = 0u;
		if (this->Armor > tmp.Armor)this->Armor = 0u;
		if (this->ElementRes > tmp.ElementRes)this->ElementRes = 0u;


	}
	CoreStats& opetator(stattype& rhs) {
		this->Strength = rhs;
		this->Intellect = rhs;
		this->Agility = rhs;
		this->Armor = rhs;
		this->ElementRes = rhs;
		return *this;
	}


};