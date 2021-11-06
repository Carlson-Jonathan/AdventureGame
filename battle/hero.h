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
	Hero(shared_ptr<TextureManager> textures, string character, shared_ptr<Initializer> globalData) {
		this->maxHitPoints 		= 100;
		this->hitPoints 		= 85;
		this->maxBloodPoints	= 90;
		this->bloodPoints 		= 78;
		this->maxEssencePoints 	= 50;
		this->essencePoints 	= 46;
		this->speed 			= 80;
		this->precision 		= 92;
		auto spriteData = make_shared<SpriteData>(character);
		this->battleAnimation   = BattleAnimation(spriteData, textures, character, globalData);
	}
};

#endif // HERO_H