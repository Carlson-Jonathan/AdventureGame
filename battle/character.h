// Copyright Jonathan Carlson 2021

#ifndef CHARACTER_H
#define CHARACTER_H

#include "battleAnimation.h"
#include <iostream>
#include <iomanip>
#include <memory>
#include "../textureManager.h"

using namespace std;

class Character {
public:

	Character() {}
	Character(string character, Initializer & globalData) {
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

	short maxHitPoints,
		  hitPoints,
		  maxBloodPoints,
		  bloodPoints,
		  maxEssencePoints,
		  essencePoints,
		  speed,
		  precision;

	string name;
	BattleAnimation battleAnimation;

	void displayCharacterInfo() {
		cout << name << setw(6) << hitPoints << "/" << maxHitPoints << setw(6) << bloodPoints 
		     << "/" << maxBloodPoints << setw(7) << essencePoints << "/" << maxEssencePoints 
		     << setw(8) << speed << setw(10) << precision << endl;
	}
};

#endif // CHARACTER_H