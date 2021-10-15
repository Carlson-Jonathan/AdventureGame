/*******************************************************************************
* combat.h
* Author: Jonathan Carlson
* Description:
*    Highest level object of a battle that organizes a battle sequence.
* Copyright Jonathan Carlson 2021
*******************************************************************************/
#ifndef BATTLE_H
#define BATTLE_H
#include <iostream>
#include <memory>
#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "character.h"
#include "hero.h"
#include "../textureManager.h"
#include <map>
using namespace std;

class Battle {
public:
	Battle() {}
	Battle(vector<shared_ptr<Hero>> party, sf::RenderWindow* window, shared_ptr<TextureManager> textures) {
		this->party = party;
		this->window = window;
		this->textures = textures;

   	 	if (!music.openFromFile(musicFile)) 
   	 		cout << "Error opening music file, '" << musicFile << "'" << endl;
   	 	
   	 	music.setLoop(true);
		music.play();

   	 	placeCharactersOnScreen();
	}

	shared_ptr<TextureManager> textures;
    sf::Sprite sprite;
    sf::Music music;    
	sf::RenderWindow* window;

	vector<sf::Vector2f> heroScreenPositions = {
		{sf::Vector2f(400.f, 300.f)}, // top
		{sf::Vector2f(350.f, 375.f)}, // middle
		{sf::Vector2f(300.f, 550.f)}  // bottom
	};

	map<string, sf::Vector2f> opponentScreenPositions = {
		{"top",    sf::Vector2f(1000.f, 300.f)},
		{"middle", sf::Vector2f(1000.f, 375.f)},
		{"bottom", sf::Vector2f(1000.f, 550.f)}
	};


	// map<string, pair<sf::Vector2f, sf::Vector2f>> opponentScreenPositions;

	vector<shared_ptr<Hero>> party;
  	vector<shared_ptr<Hero>> enemyGroup;

	short frameNumber = 0;

	string background = "forrestBackground";
	string musicFile = "Sounds/Music/battle1.ogg";

	void generateEnemyParty();
	void drawBackground();
	void placeCharactersOnScreen();
	void display();

};

// #include "battle.cpp"
#endif // BATTLE_H