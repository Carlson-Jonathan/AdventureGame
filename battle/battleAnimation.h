// Copyright Jonathan Carlson 2021

#ifndef BATTLEANIMATION_H
#define BATTLEANIMATION_H

#include <fstream>
#include "../initializer.h"
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "spriteData.h"
#include "spriteSchematic.h"
#include "../spriteSchematicXML.h"
#include "../textureManager.h"

using namespace std;

class BattleAnimation {
public:

	BattleAnimation() {}
	BattleAnimation(shared_ptr<SpriteData> spriteData, string character, Initializer & globalData) :
	spriteSchematicXML(character, globalData) {

		this->spriteData = spriteData;

		rectangle.left   = spriteData->upperLeftX;
		rectangle.top    = spriteData->upperLeftY;
		rectangle.width  = spriteData->width;
		rectangle.height = spriteData->height;

		sprite.setTextureRect(rectangle);
		sprite.setTexture(globalData.textures.textures[character]);
		testingXML();
	}

	SpriteSchematicXML spriteSchematicXML;

	sf::IntRect rectangle;
	sf::Sprite sprite;
	sf::Clock clock;
	sf::Vector2f screenPositionX;
	sf::Vector2f screenPositionY;

	shared_ptr<SpriteData> spriteData;
	// shared_ptr<SpriteSchematicXML> spriteSchematicXML;

	void drawAndAnimateSprite(sf::RenderWindow & window);
	void createSpriteFromSchematic();
	void drawAndAnimateSprite2(sf::RenderWindow & window);

	void testingXML();

};

#endif // BATTLEANIMATION_H