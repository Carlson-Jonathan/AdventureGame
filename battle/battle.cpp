#include "battle.h"

// void getAndSetRandomBattleLandscape() {
// 	numberOfLandscapes = textureManager.
// 	Miscellaneous::generateRandomNumber(texture)

// 	battlescape = 	
// }

void Battle::drawBackground() {
	landscape.setTexture(textures->textures["battlescape"][battlescape]);  
	landscape.setOrigin(0, 0);		
	window->draw(landscape);
}


void Battle::setScreenPlacementForCharacters() {

	for(short i = 0; i < playerParty.size(); i++) {
		playerParty[i]->battleAnimation.sprite.setPosition(heroScreenPositions[i]);
	}
	for(short i = 0; i < enemyGroup.size(); i++) { 
		enemyGroup[i]->battleAnimation.sprite.setPosition(enemyScreenPositions[i]);
	}
}

void Battle::generateEnemyGroup() {
	enemyGroup.push_back(make_shared<Enemy>(textures, "dragon"));
	enemyGroup.push_back(make_shared<Enemy>(textures, "cactopus"));
	// enemyGroup.push_back(make_shared<Enemy>(textures, "heroine"));
}

void Battle::generateFullBattlescape() {

	// Displays debug data in the console
	// system("clear");
    // cout << "Frame count: " << frameNumber++ << "\n\n";
	// cout << "Name" << setw(10) << "HP" << setw(10) << "BP" << setw(10) << "EP"
	//      << setw(14) << "Speed" << setw(14) << "Precision" << endl;
	// cout << "--------------------------------------------------------------" << endl;
	
	drawBackground();

	for(shared_ptr<Hero> i : playerParty) {
		// i->display();
		i->battleAnimation.drawAndAnimateSprite(window);
	}

	for(shared_ptr<Enemy> i : enemyGroup) {
		// i->display();
		i->battleAnimation.drawAndAnimateSprite(window);
	}
}

