#include "battle.h"

void Battle::setScreenPlacementForCharacters() {

	for(short i = 0; i < playerParty.size(); i++) {
		playerParty[i]->battleAnimation.sprite.setPosition(heroScreenPositions[i]);
	}
	for(short i = 0; i < enemyGroup.size(); i++) { 
		enemyGroup[i]->battleAnimation.sprite.setPosition(enemyScreenPositions[i]);
	}

	menuWheel.battleAnimation.sprite.setPosition(menuWheelPosition);
}

/*------------------------------------------------------------------------------------------------*/

void Battle::centerMenuWheelOnCharacter(shared_ptr<Hero> character) {
	pair<short, short> menuWheelCenter = 
    	menuWheel.battleAnimation.spriteSchematicXML.centerPoint;

    cout << "Character width: " << character->battleAnimation.spriteSchematicXML.width << endl;
    cout << "Character height: "<< character->battleAnimation.spriteSchematicXML.height << endl;

    pair<short, short> characterCenter = character->battleAnimation.spriteSchematicXML.centerPoint;

    cout << "Wheel centerpoint : " << menuWheelCenter.first << ", " << menuWheelCenter.second << endl;
	cout << character->name << " center = " << characterCenter.first << ", " << characterCenter.second << endl;

	menuWheelPosition = heroScreenPositions[0];

	cout << "menuWheelPosition = " << menuWheelPosition.x      << ", " << menuWheelPosition.y << endl;
	cout << character->name << " position = " << heroScreenPositions[2].x << ", " << heroScreenPositions[2].y << endl;

    menuWheelPosition.x = menuWheelPosition.x - menuWheelCenter.first + characterCenter.first;
    menuWheelPosition.y = menuWheelPosition.y - menuWheelCenter.second + characterCenter.second;

  	cout << "menuWheelPosition = " << menuWheelPosition.x      << ", " << menuWheelPosition.y << endl;


}

/*------------------------------------------------------------------------------------------------*/

void Battle::generateFullBattlescape() {

	drawBackground();
	for(shared_ptr<Hero> i : playerParty) {
		// i->displayCharacterData();
		i->battleAnimation.drawAndAnimateSprite(globalData->window);
		// i->spriteSchematic->displayRawCharacterData();
	}

	for(shared_ptr<Enemy> i : enemyGroup) {
		// i->displayCharacterData();
		i->battleAnimation.drawAndAnimateSprite(globalData->window);
	}

	menuWheel.battleAnimation.drawAndAnimateSprite(globalData->window);

}

/*------------------------------------------------------------------------------------------------*/

void Battle::generateEnemyGroup(Initializer & globalData) {
	enemyGroup.push_back(shared_ptr<Enemy>(new Enemy("spider",   globalData)));
	enemyGroup.push_back(shared_ptr<Enemy>(new Enemy("cactopus", globalData)));
	enemyGroup.push_back(shared_ptr<Enemy>(new Enemy("sara",     globalData)));
}

/*------------------------------------------------------------------------------------------------*/

string Battle::selectRandomBackground() {
	short randNum = Miscellaneous::generateRandomNumber(backgrounds.size() - 1);	
	return backgrounds[randNum];
}

/*------------------------------------------------------------------------------------------------*/

void Battle::drawBackground() {
	sprite.setTexture(globalData->textures.textures[background]);  
	sprite.setOrigin(0, 0);		
	globalData->window.draw(sprite);
}

/*------------------------------------------------------------------------------------------------*/


/*################################################################################################*/

void Battle::displayCharacterDataHeading() {
	system("clear");
    cout << "Frame count: " << frameNumber++ << "\n\n";
	cout << "Name" << setw(10) << "HP" << setw(10) << "BP" << setw(10) << "EP"
	     << setw(14) << "Speed" << setw(14) << "Precision" << endl;
	cout << "--------------------------------------------------------------" << endl;
}