#include "battle.h"

void BattleAnimation::drawAndAnimateSprite(sf::RenderWindow & window) {

	window.draw(sprite);

	if(clock.getElapsedTime().asSeconds() > spriteSchematicXML.animationSpeeds[0]) {
		setNewRectanglePosition(spriteSchematicXML.idle[currentImageNumber - 1]);
		currentImageNumber++;
		clock.restart();

		if(currentImageNumber >= numberOfImages)
		currentImageNumber = 0;
	}
}

/*------------------------------------------------------------------------------------------------*/

void BattleAnimation::setNewRectanglePosition(pair<short, short> point) {
	rectangle.left = spriteSchematicXML.idle[currentImageNumber].first;
	rectangle.top  = spriteSchematicXML.idle[currentImageNumber].second;
	sprite.setTextureRect(rectangle);
}

/*------------------------------------------------------------------------------------------------*/

// This sets the character's center point on the screen position point

void BattleAnimation::setScreenPosition(sf::Vector2f newPosition) {
	screenPosition.x = newPosition.x - spriteSchematicXML.centerPoint.first;
	screenPosition.y = newPosition.y - spriteSchematicXML.centerPoint.second;
}


/*################################################################################################*/

void BattleAnimation::displayAnimationClock() {
	cout << "Animation clock: " << clock.getElapsedTime().asSeconds() << endl;	
}