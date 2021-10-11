#ifndef BATTLEANIMATION_H
#define BATTLEANIMATION_H

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>
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
	BattleAnimation(shared_ptr<SpriteData> spriteData) {
		this->spriteData = spriteData;

		if(!texture.loadFromFile(spriteData->imageFile)) 
			cout << "Unable to load image file '" << spriteData->imageFile << "'" << endl;

		rectangle.left   = spriteData->upperLeftX;
		rectangle.top    = spriteData->upperLeftY;
		rectangle.width  = spriteData->lowerRightX;
		rectangle.height = spriteData->lowerRightY;

		sprite.setTextureRect(rectangle);
		sprite.setTexture(texture);
	}

	sf::Texture texture;
	sf::IntRect rectangle;
	sf::Sprite sprite;
	sf::Clock clock;
	shared_ptr<SpriteData> spriteData;

	void drawSprite(sf::RenderWindow* window) {
		window->draw(sprite);
		cout << "Animation clock: " << clock.getElapsedTime().asSeconds() << endl;

		// If the current image is the last in the sheet, restart with the first, otherwise
		// continue to the next image in the sheet.
		if(clock.getElapsedTime().asSeconds() > spriteData->animationSpeed) {
			rectangle.left += (spriteData->lowerRightX - spriteData->upperLeftX);
			if(rectangle.left >= ((spriteData->lowerRightX - spriteData->upperLeftX) * 
								   spriteData->numberOfImages ))
				rectangle.left = 0;

			sprite.setTextureRect(rectangle);
			clock.restart();
		}

		cout << "Sprite rectangle position: " << rectangle.left << endl;

		spriteData->displayData();
	}
};

#endif // BATTLEANIMATION_H