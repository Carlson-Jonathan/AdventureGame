#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <iomanip>
#include <memory>
#include "battleAnimation.h"
#include "spriteData.h"
#include "../textureManager.h"
using namespace std;

class Character {
public:


	Character() {}

	short maxHitPoints,
		  hitPoints,
		  maxBloodPoints,
		  bloodPoints,
		  maxEssencePoints,
		  essencePoints,
		  speed,
		  precision;

	string name;
	
	void display() {
		cout << name << setw(6) << hitPoints << "/" << maxHitPoints << setw(6) << bloodPoints 
		     << "/" << maxBloodPoints << setw(7) << essencePoints << "/" << maxEssencePoints 
		     << setw(8) << speed << setw(10) << precision << endl;
	}
};

#endif // CHARACTER_H