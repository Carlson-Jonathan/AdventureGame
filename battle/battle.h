// Copyright Jonathan Carlson 2021

#ifndef BATTLE_H
#define BATTLE_H

#include "character.h"
#include "enemy.h"
#include "../gameSound.h"
#include "hero.h"
#include "../initializer.h"
#include <iostream>
// #include <map>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../textureManager.h"
#include <vector>

using namespace std;

class Battle {
public:
	Battle() {}
	Battle(vector<shared_ptr<Hero>> playerParty, Initializer & globalData) {
		this->playerParty = playerParty;
		this->globalData = &globalData;

   	 	generateEnemyGroup(globalData);
   	 	setScreenPlacementForCharacters();
   	 	gameSound.loadAndPlayRandomBattleSong();
	}

	void generateFullBattlescape();

private:

    GameSound gameSound;  

    Initializer*       globalData;
	TextureManager*    textures;
	sf::RenderWindow*  window;
    sf::Sprite sprite;

	vector<sf::Vector2f> heroScreenPositions = {
		{sf::Vector2f(400.f, 300.f)}, // top
		{sf::Vector2f(350.f, 375.f)}, // middle
		{sf::Vector2f(300.f, 550.f)}  // bottom
	};

	vector<sf::Vector2f> enemyScreenPositions = {
		{sf::Vector2f(800.f, 250.f)}, // top
		{sf::Vector2f(900.f, 455.f)}, // middle
		{sf::Vector2f(1000.f, 600.f)} // bottom
	};

	vector<shared_ptr<Hero>> playerParty;
  	vector<shared_ptr<Enemy>> enemyGroup;

	short frameNumber    = 0;
	short enemyGroupSize = 3;

	string background = "forrestBackground";
	string musicFile  = "Sounds/Music/battle1.ogg";

	void generateEnemyGroup(Initializer & globalData);
	void drawBackground();
	void setScreenPlacementForCharacters();

};

#endif // BATTLE_H