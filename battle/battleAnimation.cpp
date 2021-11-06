#include "battle.h"

void BattleAnimation::drawAndAnimateSprite(sf::RenderWindow & window) {
	window.draw(sprite);

	if(clock.getElapsedTime().asSeconds() > spriteData->animationSpeed) {

		rectangle.left += spriteData->width;

		if(rectangle.left >= (spriteData->width * spriteData->numberOfImages)) {
			rectangle.left = 0;
		}

		sprite.setTextureRect(rectangle);
		clock.restart();
	}
}

/*------------------------------------------------------------------------------------------------*/

void BattleAnimation::drawAndAnimateSprite2(sf::RenderWindow & window) {
	window.draw(sprite);
	// cout << "Animation clock: " << clock.getElapsedTime().asSeconds() << endl;

	if(clock.getElapsedTime().asSeconds() > spriteData->animationSpeed) {

		rectangle.left += spriteData->width;

		if(rectangle.left >= (spriteData->width * spriteData->numberOfImages)) {
			rectangle.left = 0;
		}

		sprite.setTextureRect(rectangle);
		clock.restart();
	}
	// cout << "Sprite rectangle position: " << rectangle.left << endl;
	// spriteData->display();
}