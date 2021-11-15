// Copyright Jonathan Carlson 2021

#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"
#include <iostream>

using namespace std;

class Enemy : public Character {
public:

	Enemy() {}
	Enemy(string character, Initializer & globalData) {
		this->name             = character;
		this->maxHitPoints 	   = 100;
		this->hitPoints 	   = 85;
		this->maxBloodPoints   = 90;
		this->bloodPoints 	   = 78;
		this->maxEssencePoints = 50;
		this->essencePoints    = 46;
		this->speed 		   = 80;
		this->precision 	   = 92;
		this->battleAnimation  = BattleAnimation(character, globalData);
	}
};

#endif // ENEMY_H