// Copyright Jonathan Carlson 2021

#ifndef HERO_H
#define HERO_H

#include "character.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;

class Hero : public Character {
public:

	Hero() {}
	Hero(string character, Initializer & globalData) {
		this->name             = character;
		this->maxHitPoints	   = 100;
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

#endif // HERO_H