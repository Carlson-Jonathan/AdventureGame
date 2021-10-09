#ifndef HERO_H
#define HERO_H

#include <iostream>
#include "character.h"
using namespace std;

class Hero : public Character {
public:

	Hero() {
		maxHitPoints = 100,
		hitPoints = 85,
		maxBloodPoints = 90,
		bloodPoints = 78,
		maxEssencePoints = 50,
		essencePoints = 46,
		speed = 80,
		precision = 92;
	}
};

#endif // HERO_H