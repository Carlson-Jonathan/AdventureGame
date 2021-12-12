#include "battle.h"

void Battle::drawBackground() {
	background.setTexture(globalData->textures.textures[backgroundSelection]);  
	background.setOrigin(0, 0);		
	globalData->window.draw(background);
}

/*------------------------------------------------------------------------------------------------*/

void Battle::generateEnemyGroup(Initializer & globalData) {
	for(auto i : battleSchematic.enemyGroup) {
		this->enemyGroup.push_back(shared_ptr<Character>(new Character(i, globalData)));
	}
}

/*------------------------------------------------------------------------------------------------*/

void Battle::defineScreenPlacementForAllCharacters() {

	for(short i = 0; i < playerParty.size(); i++) {
		setCharacterScreenPosition(playerParty[i], battleSchematic.heroScreenPositions[i]);
	}

	for(short i = 0; i < enemyGroup.size(); i++) {
		setCharacterScreenPosition(enemyGroup[i], battleSchematic.enemyLineCharacterPositions[i]);
	}
}

/*------------------------------------------------------------------------------------------------*/

	void Battle::setCharacterScreenPosition(shared_ptr<Character> character, sf::Vector2f position) {
		character->battleAnimation.setScreenPosition(position);
		character->battleAnimation.sprite.setPosition(character->battleAnimation.screenPosition);
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

void Battle::drawAllBattleSpritesAndAnimations() {

	drawBackground();

	for(shared_ptr<Character> i : playerParty) {
		i->battleAnimation.drawAndAnimateSprite(globalData->window);
	}

	for(shared_ptr<Character> i : enemyGroup) {
		i->battleAnimation.drawAndAnimateSprite(globalData->window);
	}

	if(menuWheel.isVisible) 
		menuWheel.battleAnimation.drawAndAnimateSprite(globalData->window);
}

/*------------------------------------------------------------------------------------------------*/

void Battle::runMainCombatLoop() {
    globalData->window.clear(sf::Color(102, 255, 255));
    drawAllBattleSpritesAndAnimations();
    globalData->window.display();
}

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