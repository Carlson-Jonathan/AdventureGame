// Copyright Jonathan Carlson 2021
#ifndef BATTLE_H
#define BATTLE_H

#include "character.h"
#include "enemy.h"
#include "../gameSound.h"
#include "hero.h"
#include "../initializer.h"
#include <iostream>
#include <map>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../textureManager.h"
#include <vector>

using namespace std;

class Battle {
public:
	Battle() {}
	Battle(vector<shared_ptr<Hero>> playerParty, sf::RenderWindow* window, 
		   shared_ptr<TextureManager> textures, shared_ptr<Initializer> globalData) {
		this->playerParty = playerParty;
		this->window = window;
		this->textures = textures;

   	 	generateEnemyGroup(globalData);
   	 	setScreenPlacementForCharacters();
   	 	gameSound.loadAndPlayRandomBattleSong();
   	 	// this->globalData = globalData;
	}

    GameSound gameSound;  

	shared_ptr<TextureManager> textures;
	// shared_ptr<Initializer> globalData;
    sf::Sprite sprite;
	sf::RenderWindow* window;

	vector<sf::Vector2f> heroScreenPositions = {
		{sf::Vector2f(400.f, 300.f)}, // top
		{sf::Vector2f(350.f, 375.f)}, // middle
		{sf::Vector2f(300.f, 550.f)}  // bottom
	};

	vector<sf::Vector2f> enemyScreenPositions = {
		{sf::Vector2f(800.f, 250.f)}, // top
		{sf::Vector2f(900.f, 455.f)}, // middle
		{sf::Vector2f(1000.f, 600.f)}  // bottom
	};


	// map<string, pair<sf::Vector2f, sf::Vector2f>> opponentScreenPositions;

	vector<shared_ptr<Hero>> playerParty;
  	vector<shared_ptr<Enemy>> enemyGroup;

	short frameNumber = 0;
	short enemyGroupSize = 3;

	string background = "forrestBackground";
	string musicFile = "Sounds/Music/battle1.ogg";

	void generateEnemyGroup(shared_ptr<Initializer> globalData);
	void drawBackground();
	void setScreenPlacementForCharacters();
	void generateFullBattlescape();

};

#endif // BATTLE_H