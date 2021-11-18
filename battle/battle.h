// Copyright Jonathan Carlson 2021

#ifndef BATTLE_H
#define BATTLE_H

#include "battleSchematic.h"
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
	Battle(BattleSchematic battleSchematic, Initializer & globalData) : 
		menuWheel(globalData), eventHandler(globalData) {

		this->battleSchematic = battleSchematic;
		this->playerParty = battleSchematic.playerParty;
		this->globalData = &globalData;

		backgroundSelection = battleSchematic.selectRandomBackground();
   	 	generateEnemyGroup(globalData);
   	 	defineScreenPlacementForAllCharacters();
		centerMenuWheelOnCharacter(playerParty[0]);
   	 	gameSound.loadAndPlayRandomBattleSong();

   	 	// displayCharacterScreenSpriteData(enemyGroup[0]);
   	 	// displayMenuWheelSpriteData();
	}

	void runMainCombatSequence();

private:

    Initializer*    globalData;
    EventHandler    eventHandler;
    GameSound       gameSound;  
    MenuWheel       menuWheel;
    BattleSchematic battleSchematic;
    
	vector<shared_ptr<Character>> playerParty;
  	vector<shared_ptr<Character>> enemyGroup;

	short frameNumber = 0;

    sf::Sprite background;
	string backgroundSelection;

	void drawBackground();
	void generateEnemyGroup(Initializer & globalData);
	void defineScreenPlacementForAllCharacters();
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