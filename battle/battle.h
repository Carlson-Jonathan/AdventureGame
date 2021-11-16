// Copyright Jonathan Carlson 2021

#ifndef BATTLE_H
#define BATTLE_H

#include "character.h"
#include "enemy.h"
#include "../gameSound.h"
#include "hero.h"
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
	Battle(vector<shared_ptr<Hero>> playerParty, Initializer & globalData) : menuWheel(globalData) {
		this->playerParty = playerParty;
		this->globalData = &globalData;

		selectRandomBackground();
   	 	generateEnemyGroup(globalData);
   	 	setScreenPlacementForCharacters();
		centerMenuWheelOnCharacter(playerParty[0]);
   	 	gameSound.loadAndPlayRandomBattleSong();
	}

	void generateFullBattlescape();


private:

    Initializer* globalData;
    GameSound    gameSound;  

    MenuWheel    menuWheel;
    sf::Vector2f menuWheelPosition;
    
	vector<shared_ptr<Hero>>  playerParty;
  	vector<shared_ptr<Enemy>> enemyGroup;

	short frameNumber    = 0;
	short enemyGroupSize = 3;

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
	void setScreenPlacementForCharacters();
	void centerMenuWheelOnCharacter(shared_ptr<Hero> character);

	void displayCharacterDataHeading();
	void displayCharacterScreenSpriteData(Character character);
	void displayMenuWheelSpriteData();
};

#endif // BATTLE_H