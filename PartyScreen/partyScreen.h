#ifndef PARTYSCREEN_H
#define PARTYSCREEN_H

#include "../battle/battle.h"
#include "../battle/battleSchematic.h"
#include "../gameSound.h"
#include <iostream>
#include "../initializer.h"
#include <memory>
#include <vector>
using namespace std;


class PartyScreen {
public:

	PartyScreen() {}
	PartyScreen(Initializer & globalData, vector<shared_ptr<Character>> playerParty) {

	   	playerParty.push_back(shared_ptr<Character>(new Character("rabbit",  globalData)));
	   	playerParty.push_back(shared_ptr<Character>(new Character("dragon",  globalData)));

		this->globalData = &globalData;
	   	this->playerParty = playerParty;
	   	this->battleSchematic = BattleSchematic(playerParty);
	   	globalData.gameSound.loadAndPlayMusic("Sounds/Music/preBattle.ogg");
	}

	/*---------------------------------------------------------------------------------------------*/

	void runPartyScreenLoop() {
	    globalData->window.clear(sf::Color(102, 255, 255));
	    drawAllPartyScreenImages();
	    globalData->window.display();
	}

private:

	Initializer*       globalData;
   	BattleSchematic    battleSchematic;
    unique_ptr<Battle> battle;
    sf::Sprite         background;

    vector<shared_ptr<Character>> playerParty;

	string backgroundSelection = "partyScreen";

	/*---------------------------------------------------------------------------------------------*/

	void drawBackground() {
		background.setTexture(globalData->textures.textures[backgroundSelection]);  
		background.setOrigin(0, 0);		
		globalData->window.draw(background);
	}

	/*---------------------------------------------------------------------------------------------*/

	void drawAllPartyScreenImages() {

		bool buttonPressed  =  sf::Joystick::isButtonPressed(0, 1);

		static bool once1 = true;
		static bool once2 = true;
		static bool doBattle = false;

		if(buttonPressed && doBattle == false) {
			doBattle = true;		
			once1 = true;
		}

		if(doBattle) {
			
			if(once1) {
				this->battle = make_unique<Battle>(battleSchematic, *globalData);
				once1 = false;
			}

			battle->runMainCombatLoop();

		}
		else 
			drawBackground();

		if(sf::Joystick::isButtonPressed(0, 2) && once2)
			once1 = true;
			once2 = false;

		if(!sf::Joystick::isButtonPressed(0, 2))
			once2 = true;

	}

	/*---------------------------------------------------------------------------------------------*/

};

#endif // PARTYSCREEN_H