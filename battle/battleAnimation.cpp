#include "battle.h"

void BattleAnimation::drawAndAnimateSprite(sf::RenderWindow* window) {
	window->draw(sprite);
	// cout << "Animation clock: " << clock.getElapsedTime().asSeconds() << endl;

	// Idea: Maybe instead of just designing and calling all sprites from a left-to-right sequence,
	// you should create a sequence array containing the coordinates of the rectangle. This will
	// allow you to pull images from any part of the texture page and may help with animation
	// switching for different actions and events.

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