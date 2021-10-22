#ifndef HERO_H
#define HERO_H

#include "character.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "spriteData.h"

using namespace std;

class Hero : public Character {
public:

	Hero() {}
	Hero(shared_ptr<TextureManager> textures, string character) {
		this->maxHitPoints 		= 100;
		this->hitPoints 		= 85;
		this->maxBloodPoints	= 90;
		this->bloodPoints 		= 78;
		this->maxEssencePoints 	= 50;
		this->essencePoints 	= 46;
		this->speed 			= 80;
		this->precision 		= 92;
		shared_ptr<SpriteData> spriteData(new SpriteData(character));
		auto spriteSchematic = make_shared<SpriteSchematic>(character);
		this->battleAnimation   = BattleAnimation(spriteData, textures);
	}
};

#endif // HERO_H