// Copyright Jonathan Carlson 2021
#ifndef BATTLE_H
#define BATTLE_H

#include "character.h"
#include "enemy.h"
#include "hero.h"
#include <iostream>
#include <map>
#include <memory>
#include "../miscellaneous.h"
#include "../gameSound.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../textureManager.h"
#include <vector>

using namespace std;

class Battle {
public:
	Battle() {}
	Battle(vector<shared_ptr<Hero>> playerParty, sf::RenderWindow* window, 
		   shared_ptr<TextureManager> textures) {
		this->playerParty = playerParty;
		this->window = window;
		this->textures = textures;

   	 	generateEnemyGroup();
   	 	setScreenPlacementForCharacters();
   	 	gameSound.loadAndPlayRandomBattleSong();
	}

    GameSound gameSound;  
	string battlescape = "meadowBattlescape";

	shared_ptr<TextureManager> textures;
    sf::Sprite landscape;
	sf::RenderWindow* window;

	vector<sf::Vector2f> heroScreenPositions = {
		{sf::Vector2f(400.f, 300.f)}, // top
		{sf::Vector2f(350.f, 375.f)}, // middle
		{sf::Vector2f(300.f, 550.f)}  // bottom
	};

	vector<sf::Vector2f> enemyScreenPositions = {
		{sf::Vector2f(800.f, 250.f)},  // top
		{sf::Vector2f(900.f, 455.f)},  // middle
		{sf::Vector2f(1000.f, 600.f)}  // bottom
	};

	vector<shared_ptr<Hero>> playerParty;
  	vector<shared_ptr<Enemy>> enemyGroup;

	short frameNumber = 0;


	void generateEnemyGroup();
	void drawBackground();
	void setScreenPlacementForCharacters();
	void generateFullBattlescape();
};

#endif // BATTLE_H