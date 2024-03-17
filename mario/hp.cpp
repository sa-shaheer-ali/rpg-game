#pragma once
#include <cstdint>
typedef std::uint16_t hptype;

class hp {
public:
	hp():CurrentHP(1),MaxHp(2){}

	hp(hptype CrtHP,hptype maxhp):CurrentHP(CrtHP),MaxHp(maxhp){};
	bool maxhealth(hptype newhealth) {
		if (newhealth<1)
		{
			return false;

		}
		MaxHp = newhealth;
		if (newhealth +CurrentHP>MaxHp)
		{
			MaxHp = newhealth;
			return true;
		}
	}

	void takeDamage(hptype damage) {
		if (damage>CurrentHP)
		{
			CurrentHP = 0;

		}
		CurrentHP -= damage;

	}
	void heal(hptype amount) {
		if (amount + CurrentHP>MaxHp)
		{
			CurrentHP = MaxHp;


		}
		CurrentHP += amount;

	}
	hptype getMaxHp() {
		return MaxHp;
	}

	hptype increaseMaxHp(hptype hpgrow) {
		return MaxHp += hpgrow;

	}
	hptype setMaxHP(hptype HpGrowth) {
		if (CurrentHP+HpGrowth>MaxHp)
		{
			HpGrowth += MaxHp;

		}
		MaxHp += HpGrowth;
		return MaxHp;
	}

	



private:
	hptype ShieldHP;
	hptype CurrentHP;
	hptype MaxHp;

};