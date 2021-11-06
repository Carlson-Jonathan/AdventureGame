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

// #include "../tinyxml2.h"

using namespace std;

/***************************************************************************************************
 * The purpose of this class is to accept a 'spriteData' object and use the information in that
 * object to construct, place, and animate the sprite. Any spriteData object should be able to be
 * used and this class should be able to decipher what to do with it from the object's data.
 * ************************************************************************************************/
class BattleAnimation {
public:

	BattleAnimation() {}
	BattleAnimation(shared_ptr<SpriteData> spriteData, shared_ptr<TextureManager> textures, 
		            string character, shared_ptr<Initializer> globalData) {

		this->spriteData = spriteData;
		this->textures   = textures;
		rectangle.left   = spriteData->upperLeftX;
		rectangle.top    = spriteData->upperLeftY;
		rectangle.width  = spriteData->width;
		rectangle.height = spriteData->height;
		sprite.setTextureRect(rectangle);
		sprite.setTexture(textures->textures[spriteData->character]);
		spriteSchematicXML = make_shared<SpriteSchematicXML>(character, globalData);
	}

	shared_ptr<TextureManager> textures;
	sf::IntRect rectangle;
	sf::Sprite sprite;
	sf::Clock clock;
	sf::Vector2f screenPositionX;
	sf::Vector2f screenPositionY;
	shared_ptr<SpriteData> spriteData;
	shared_ptr<SpriteSchematicXML> spriteSchematicXML;

	void drawAndAnimateSprite(sf::RenderWindow* window);
	void createSpriteFromSchematic();
	void drawAndAnimateSprite2(sf::RenderWindow* window);
};

#endif // BATTLEANIMATION_H