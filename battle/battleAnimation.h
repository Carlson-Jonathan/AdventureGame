// Copyright Jonathan Carlson 2021

#ifndef BATTLEANIMATION_H
#define BATTLEANIMATION_H

#include <fstream>
#include "../initializer.h"
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "spriteSchematic.h"
#include "../spriteSchematicXML.h"
#include "../textureManager.h"

using namespace std;

class BattleAnimation {
public:

	BattleAnimation() {}
	BattleAnimation(string character, Initializer & globalData) :
	spriteSchematicXML(character, globalData) {

		rectangle.left   = spriteSchematicXML.idle[0].first;
		rectangle.top    = spriteSchematicXML.idle[0].second;
		rectangle.width  = spriteSchematicXML.width;
		rectangle.height = spriteSchematicXML.height;

		sprite.setTextureRect(rectangle);
		sprite.setTexture(globalData.textures.textures[character]);
	}

	SpriteSchematicXML spriteSchematicXML;

	sf::IntRect rectangle;
	sf::Sprite sprite;
	sf::Clock clock;
	sf::Vector2f screenPositionX;
	sf::Vector2f screenPositionY;

	short numberOfImages = spriteSchematicXML.idle.size();
	short currentImageNumber = 1;

	void drawAndAnimateSprite(sf::RenderWindow & window);
	void setNewRectanglePosition(pair<short, short> point);
	void displayAnimationClock();
};

#endif // BATTLEANIMATION_H