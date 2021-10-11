#ifndef ANTAGONIST_H
#define ANTAGONIST_H

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "character.h"
using namespace std;

class Antagonist : public Character {
public:

	Antagonist() {}
	Antagonist(sf::RenderWindow* window) {
		maxHitPoints 		= 100,
		hitPoints 			= 85,
		maxBloodPoints 		= 90,
		bloodPoints 		= 78,
		maxEssencePoints 	= 50,
		essencePoints 		= 46,
		speed 				= 80,
		precision 			= 92;
	}


};

#endif // ANTAGONIST_H