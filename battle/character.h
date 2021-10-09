#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <iomanip>
using namespace std;

/*
A character...
Can be a player/Hero or an AI/antagonist
Has a...
	Weapon
		1-handed
		2-handed
	Armor
	Name
	Hit Points
		Current
		Max
	Blood Points
		Current
		Max
	Essense Points
		Current
		Max
Combat Modifying Statistics/Attributes
	Precision
	Evasion
	Speed
Afflictions
	Bleeding
	Slow

Animation
	Stationary
	Attacking
	Defending
	Receiving Damage
	Fleeing
	Casting
	Channeling
	Dodging
	Taunting
Information display for debugging

*/


class Character {
public:

	string name;

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

};

#endif // CHARACTER_H