#include "battle.h"

void Battle::drawBackground() {
	sprite.setTexture(textures->textures[background]);  
	sprite.setOrigin(0, 0);		
	window->draw(sprite);
}


void Battle::setScreenPlacementForCharacters() {

	for(short i = 0; i < playerParty.size(); i++) {
		playerParty[i]->battleAnimation.sprite.setPosition(heroScreenPositions[i]);
	}
	for(short i = 0; i < enemyGroup.size(); i++) { 
		enemyGroup[i]->battleAnimation.sprite.setPosition(enemyScreenPositions[i]);
	}
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
		// i->spriteSchematic->displayRawCharacterData();
	}

	for(shared_ptr<Enemy> i : enemyGroup) {
		// i->display();
		i->battleAnimation.drawAndAnimateSprite(window);
	}
}


void Battle::generateEnemyGroup(shared_ptr<Initializer> globalData) {
	enemyGroup.push_back(shared_ptr<Enemy>(new Enemy("dragon", globalData)));
	enemyGroup.push_back(shared_ptr<Enemy>(new Enemy("cactopus", globalData)));
	enemyGroup.push_back(shared_ptr<Enemy>(new Enemy("heroine", globalData)));
}