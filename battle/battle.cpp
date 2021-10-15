#include "battle.h"

void Battle::drawBackground() {
	sprite.setTexture(textures->textures[background]);  
	sprite.setOrigin(0, 0);		
	window->draw(sprite);
}

void Battle::placeCharactersOnScreen() {
	for(short i = 0; i < party.size(); i++)
		party[i]->battleAnimation.sprite.setPosition(heroScreenPositions[i]);
}

void Battle::display() {

	// Displays debug data in the console
	// system("clear");
    // cout << "Frame count: " << frameNumber++ << "\n\n";
	// cout << "Name" << setw(10) << "HP" << setw(10) << "BP" << setw(10) << "EP"
	//      << setw(14) << "Speed" << setw(14) << "Precision" << endl;
	// cout << "--------------------------------------------------------------" << endl;
	
	drawBackground();
	for(shared_ptr<Hero> i : party) {
		// i->display();
		i->battleAnimation.drawAndAnimateSprite(window);
	}
}