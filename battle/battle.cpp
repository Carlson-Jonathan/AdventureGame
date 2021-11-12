#include "battle.h"

void Battle::setScreenPlacementForCharacters() {

	for(short i = 0; i < playerParty.size(); i++) {
		playerParty[i]->battleAnimation.sprite.setPosition(heroScreenPositions[i]);
	}
	for(short i = 0; i < enemyGroup.size(); i++) { 
		enemyGroup[i]->battleAnimation.sprite.setPosition(enemyScreenPositions[i]);
	}
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
}

/*------------------------------------------------------------------------------------------------*/

void Battle::generateEnemyGroup(Initializer & globalData) {
	enemyGroup.push_back(shared_ptr<Enemy>(new Enemy("spider",   globalData)));
	enemyGroup.push_back(shared_ptr<Enemy>(new Enemy("cactopus", globalData)));
	enemyGroup.push_back(shared_ptr<Enemy>(new Enemy("sara",     globalData)));
}

/*------------------------------------------------------------------------------------------------*/

string Battle::selectRandomBackground() {
	
	short randNum = Miscellaneous::generateRandomNumber(13);	

	string backgrounds[] = {
		"meadowBackground",
		"desertBackground",
		"battleback1",
		"battleback2",
		"battleback3",
		"battleback4",
		"battleback5",
		"battleback6",
		"battleback7",
		"battleback8",
		"battleback9",
		"battleback10"
	};

	return backgrounds[randNum - 1];
}

/*------------------------------------------------------------------------------------------------*/

void Battle::drawBackground() {
	sprite.setTexture(globalData->textures.textures[background]);  
	sprite.setOrigin(0, 0);		
	globalData->window.draw(sprite);
}




/*################################################################################################*/

void Battle::displayCharacterDataHeading() {
	system("clear");
    cout << "Frame count: " << frameNumber++ << "\n\n";
	cout << "Name" << setw(10) << "HP" << setw(10) << "BP" << setw(10) << "EP"
	     << setw(14) << "Speed" << setw(14) << "Precision" << endl;
	cout << "--------------------------------------------------------------" << endl;
}