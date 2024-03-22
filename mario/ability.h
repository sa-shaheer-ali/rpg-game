#pragma once
#include <string>
struct AbilityEffect {
	unsigned int hp_effect;
};
enum class ABILITYTARGET{SELF,ALLY,ENEMY};
enum class ABILITYSCALER{NONE,STR,AGI,INT};
struct  Ability
{Ability(std::string n,uint32_t cost,uint32_t cd,ABILITYTARGET t,uint32_t hpe,ABILITYSCALER s):name(n),cost(cost),cooldown(cd),target(t),hpEffect(hpe),Scaler (s) {}
	std::string name="unamed";
	uint32_t cost=0;
	uint32_t cooldown=1;
	ABILITYTARGET target=ABILITYTARGET::SELF;
	unsigned int hpEffect = 1;
	ABILITYSCALER Scaler = ABILITYSCALER::NONE;




};