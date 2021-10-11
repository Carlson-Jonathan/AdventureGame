#ifndef HERO_H
#define HERO_H

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "character.h"
#include "spriteData.h"
using namespace std;

class Hero : public Character {
public:

	// Hero() {}
	Hero() {
		this->maxHitPoints 		= 100;
		this->hitPoints 		= 85;
		this->maxBloodPoints	= 90;
		this->bloodPoints 		= 78;
		this->maxEssencePoints 	= 50;
		this->essencePoints 	= 46;
		this->speed 			= 80;
		this->precision 		= 92;
		cout << "The non-default Hero constructor is being called." << endl;
	}

};

#endif // HERO_H