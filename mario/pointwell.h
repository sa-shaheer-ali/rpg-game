#pragma once
#include <cstdint>
typedef std::uint16_t welltype;

class Pointwell {
public:
	Pointwell():Current(1),Max(2){}

	Pointwell(welltype c,welltype m):Current(c),Max(m)
	{
		if (Current>Max)
		{
			Current = Max;

		}
	};
	bool maxhealth(welltype newhealth) {
		if (newhealth<1)
		{
			return false;

		}
		Max = newhealth;
		if (newhealth +Current>Max)
		{
			Max = newhealth;
			return true;
		}
	}

	void decrease(welltype damage) {
		if (damage>Current)
		{
			Current = 0;

		}
		Current -= damage;

	}
	void increase(welltype amount) {
		if (amount + Current>Max)
		{
			Current = Max;


		}
		Current += amount;

	}
	welltype getMax() {
		return Max;
	}

	welltype increaseMax(welltype grow) {
		return Max += grow;

	}
	bool setMax(welltype Growth) {
		if (Growth < 1) {
			return false;
		}

		Max= Growth;
		if (Current >Max){
			Current = Max;
				return true;

		}
	}
	welltype getcurrent() {
		return Current;

	}
	



private:
	welltype Current;
	welltype Max;

};