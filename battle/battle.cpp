#include "battle.h"

void Battle::selectRandomBackground() {
	short randNum = Miscellaneous::generateRandomNumber(availableBackgrounds.size() - 1);	
	this->backgroundSelection = availableBackgrounds[randNum];
}

/*------------------------------------------------------------------------------------------------*/

void Battle::drawBackground() {
	background.setTexture(globalData->textures.textures[backgroundSelection]);  
	background.setOrigin(0, 0);		
	globalData->window.draw(background);
}

/*------------------------------------------------------------------------------------------------*/

void Battle::generateEnemyGroup(Initializer & globalData) {
	enemyGroup.push_back(shared_ptr<Character>(new Character("spider",   globalData)));
	enemyGroup.push_back(shared_ptr<Character>(new Character("cactopus", globalData)));
	enemyGroup.push_back(shared_ptr<Character>(new Character("sara",     globalData)));
}

/*------------------------------------------------------------------------------------------------*/

void Battle::setScreenPlacementForCharacters() {

	vector<sf::Vector2f> heroScreenPositions = {
		{sf::Vector2f(400.f, 300.f)}, // top row
		{sf::Vector2f(350.f, 375.f)}, // middle row
		{sf::Vector2f(300.f, 550.f)}  // bottom row
	};

	vector<sf::Vector2f> enemyScreenPositions = {
		{sf::Vector2f( 825.f, 350.f)}, // top row
		{sf::Vector2f( 900.f, 455.f)}, // middle row
		{sf::Vector2f(1000.f, 600.f)}  // bottom row
	};

	for(short i = 0; i < playerParty.size(); i++) {
		playerParty[i]->battleAnimation.screenPosition = heroScreenPositions[i];
		playerParty[i]->battleAnimation.sprite.setPosition(playerParty[i]->battleAnimation.screenPosition);
	}

	for(short i = 0; i < enemyGroup.size(); i++) { 
		enemyGroup[i]->battleAnimation.screenPosition = enemyScreenPositions[i];
		enemyGroup[i]->battleAnimation.sprite.setPosition(enemyScreenPositions[i]);
	}
}

/*------------------------------------------------------------------------------------------------*/

void Battle::centerMenuWheelOnCharacter(shared_ptr<Character> character) {
	
	pair<short, short> menuWheelCenter = menuWheel.battleAnimation.spriteSchematicXML.centerPoint;
    pair<short, short> characterCenter = character->battleAnimation.spriteSchematicXML.centerPoint;

    menuWheel.battleAnimation.screenPosition = character->battleAnimation.screenPosition;

    menuWheel.battleAnimation.screenPosition.x = 
    	menuWheel.battleAnimation.screenPosition.x - menuWheelCenter.first + characterCenter.first;

    menuWheel.battleAnimation.screenPosition.y = 
    	menuWheel.battleAnimation.screenPosition.y - menuWheelCenter.second + characterCenter.second;

	menuWheel.battleAnimation.sprite.setPosition(menuWheel.battleAnimation.screenPosition);
}

/*------------------------------------------------------------------------------------------------*/

void Battle::generateFullBattlescape() {

	drawBackground();

	for(shared_ptr<Character> i : playerParty) {
		// i->displayCharacterData();
		i->battleAnimation.drawAndAnimateSprite(globalData->window);
		// i->spriteSchematic->displayRawCharacterData();
	}

	for(shared_ptr<Character> i : enemyGroup) {
		// i->displayCharacterData();
		i->battleAnimation.drawAndAnimateSprite(globalData->window);
	}

	if(menuWheel.isVisible) 
		menuWheel.battleAnimation.drawAndAnimateSprite(globalData->window);
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

/*------------------------------------------------------------------------------------------------*/

void Battle::displayCharacterScreenSpriteData(shared_ptr<Character> character) {
	cout << "###### " << character->name << " Screen Position Information ######\n" 
         << "Image width/height: " << character->battleAnimation.spriteSchematicXML.width
         << "x" << character->battleAnimation.spriteSchematicXML.height << "\n"
	     << "Image center point: {" << character->battleAnimation.spriteSchematicXML.centerPoint.first 
	     << ", " <<  character->battleAnimation.spriteSchematicXML.centerPoint.second << "}\n"
	     << "Screen position point: {" << character->battleAnimation.screenPosition.x << ", "
	     << character->battleAnimation.screenPosition.y << "}" << endl;
}

/*------------------------------------------------------------------------------------------------*/

void Battle::displayMenuWheelSpriteData() {
	cout << "###### Menu Wheel Screen Position Information ######\n"
	     << "Image width/height: " << menuWheel.battleAnimation.spriteSchematicXML.width << "x" 
	     << menuWheel.battleAnimation.spriteSchematicXML.height << "\n"
	     << "Image center point: {" << menuWheel.battleAnimation.spriteSchematicXML.centerPoint.first
	     << ", " << menuWheel.battleAnimation.spriteSchematicXML.centerPoint.second << "}\n"
	     << "Screen position point: {" << menuWheel.battleAnimation.screenPosition.x 
	     << ", " << menuWheel.battleAnimation.screenPosition.y << "}" << endl;
}