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

   	 	if (!music.openFromFile(musicFile)) {
   	 		cout << "Error opening music file, '" << musicFile << "'" << endl;
   	 	}

   	 	placeCharactersOnScreen();
   	 	music.setLoop(true);
		// music.play();
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
		{"top",    sf::Vector2f(1000.f, 400.f)},
		{"middle", sf::Vector2f(1000.f, 250.f)},
		{"bottom", sf::Vector2f(1000.f, 200.f)}
	};


	// map<string, pair<sf::Vector2f, sf::Vector2f>> opponentScreenPositions;

	vector<shared_ptr<Hero>> party;
  	vector<shared_ptr<Hero>> enemyGroup;

	short frameNumber = 0;

	string background = "forrestBackground";
	string musicFile = "Sounds/Music/battle1.ogg";

	void generateEnemyParty();

	void drawBackground() {
    	sprite.setTexture(textures->textures[background]);  
    	sprite.setOrigin(0, 0);		
		window->draw(sprite);
	}

	void placeCharactersOnScreen() {
		for(short i = 0; i < party.size(); i++)
			party[i]->battleAnimation.sprite.setPosition(heroScreenPositions[i]);
	}

	void display() {

		// Displays debug data in the console
		// system("clear");
        // cout << "Frame count: " << frameNumber++ << "\n\n";
		// cout << "Name" << setw(10) << "HP" << setw(10) << "BP" << setw(10) << "EP"
		//      << setw(14) << "Speed" << setw(14) << "Precision" << endl;
		// cout << "--------------------------------------------------------------" << endl;
		
		drawBackground();
		for(shared_ptr<Hero> i : party) {
			// i->display();
			i->battleAnimation.drawSprite(window);
		}
	}

private:

};

#endif // BATTLE_H