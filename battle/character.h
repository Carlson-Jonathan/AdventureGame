#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <iomanip>
#include <memory>
#include "battleAnimation.h"
#include "spriteData.h"
using namespace std;

class Character {
public:

	string name;

	Character() {
		cout << "The character.h constructor is being called." << endl;
		shared_ptr<SpriteData> spriteData(new SpriteData);
		cout << "Information about sprite data: " << endl;
		spriteData->displayData();
		this->battleAnimation = BattleAnimation(spriteData);
	}

	short maxHitPoints,
		  hitPoints,
		  maxBloodPoints,
		  bloodPoints,
		  maxEssencePoints,
		  essencePoints,
		  speed,
		  precision;

	void display() {
		cout << name << setw(6) << hitPoints << "/" << maxHitPoints << setw(6) << bloodPoints 
		     << "/" << maxBloodPoints << setw(7) << essencePoints << "/" << maxEssencePoints 
		     << setw(8) << speed << setw(10) << precision << endl;
	}

	BattleAnimation battleAnimation;


};

#endif // CHARACTER_H