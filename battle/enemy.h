#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "character.h"
using namespace std;

class Enemy : public Character {
public:

	Enemy() {}
	Enemy(shared_ptr<TextureManager> textures, string character) {
		this->maxHitPoints 		= 100;
		this->hitPoints 		= 85;
		this->maxBloodPoints	= 90;
		this->bloodPoints 		= 78;
		this->maxEssencePoints 	= 50;
		this->essencePoints 	= 46;
		this->speed 			= 80;
		this->precision 		= 92;
		shared_ptr<SpriteData> spriteData(new SpriteData(character));
		this->battleAnimation   = BattleAnimation(spriteData, textures);
	}
};

#endif // ENEMY_H