#ifndef BATTLEANIMATION_H
#define BATTLEANIMATION_H

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>
#include "../textureManager.h"
#include "spriteData.h"

using namespace std;


/***************************************************************************************************
 * The purpose of this class is to accept a 'spriteData' object and use the information in that
 * object to construct, place, and animate the sprite. Any spriteData object should be able to be
 * used and this class should be able to decipher what to do with it from the object's data.
 * ************************************************************************************************/
class BattleAnimation {
public:

	BattleAnimation() {}
	BattleAnimation(shared_ptr<SpriteData> spriteData, shared_ptr<TextureManager> textures) {
		this->spriteData = spriteData;
		this->textures = textures;
		rectangle.left   = spriteData->upperLeftX;
		rectangle.top    = spriteData->upperLeftY;
		rectangle.width  = spriteData->width;
		rectangle.height = spriteData->height;
		sprite.setTextureRect(rectangle);
		sprite.setTexture(textures->textures[spriteData->character]);
	}

	shared_ptr<TextureManager> textures;
	sf::IntRect rectangle;
	sf::Sprite sprite;
	sf::Clock clock;
	sf::Vector2f screenPositionX;
	sf::Vector2f screenPositionY;
	shared_ptr<SpriteData> spriteData;

	void drawSprite(sf::RenderWindow* window) {
		window->draw(sprite);
		// cout << "Animation clock: " << clock.getElapsedTime().asSeconds() << endl;

		// If the current image is the last in the sheet, restart with the first, otherwise
		// continue to the next image in the sheet.
		if(clock.getElapsedTime().asSeconds() > spriteData->animationSpeed) {

			rectangle.left += spriteData->width;
			if(rectangle.left >= (spriteData->width * spriteData->numberOfImages))
				rectangle.left = 0;

			sprite.setTextureRect(rectangle);
			clock.restart();
		}

		// cout << "Sprite rectangle position: " << rectangle.left << endl;

		// spriteData->display();
	}
};

#endif // BATTLEANIMATION_H