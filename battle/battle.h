// Copyright Jonathan Carlson 2021

#ifndef BATTLE_H
#define BATTLE_H

#include "character.h"
#include "../eventHandler.h"
#include "../gameSound.h"
#include "../initializer.h"
#include <iostream>
#include <memory>
#include "menuWheel.h"
#include "../miscellaneous.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../textureManager.h"
#include <vector>

using namespace std;

class Battle {
public:
	Battle() {}
	Battle(vector<shared_ptr<Character>> playerParty, Initializer & globalData) : 
		menuWheel(globalData), eventHandler(globalData) {

		this->playerParty = playerParty;
		this->globalData = &globalData;

		selectRandomBackground();
   	 	generateEnemyGroup(globalData);
   	 	setScreenPlacementForAllCharacters();
		centerMenuWheelOnCharacter(playerParty[0]);
   	 	gameSound.loadAndPlayRandomBattleSong();
	}

	void runMainCombatSequence();

private:

    Initializer* globalData;
    EventHandler eventHandler;
    GameSound    gameSound;  
    MenuWheel    menuWheel;
    
	vector<shared_ptr<Character>> playerParty;
  	vector<shared_ptr<Character>> enemyGroup;

	short frameNumber    = 0;
	short enemyGroupSize = 3;

	sf::Event event;

    sf::Sprite background;
	string backgroundSelection;
	vector<string> availableBackgrounds = {
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


	void selectRandomBackground();
	void drawBackground();
	void generateEnemyGroup(Initializer & globalData);
	void setScreenPlacementForAllCharacters();
	void setCharacterScreenPosition(shared_ptr<Character> character, sf::Vector2f position);
	void centerMenuWheelOnCharacter(shared_ptr<Character> character);
	void drawAllBattleSpritesAndAnimations();

	void closeWindow();
	void resizeWindow();

	void displayCharacterDataHeading();
	void displayCharacterScreenSpriteData(shared_ptr<Character> character);
	void displayMenuWheelSpriteData();
};

#endif // BATTLE_H