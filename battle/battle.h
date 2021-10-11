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
using namespace std;

class Battle {

/*
A battle has:
	Participants
		Hero party
		Enemy party
	A background
	Animations
		Environment
		Random stuff in background/foreground
	Music
	A combat loop function
	Combat rounds
*/

public:
	Battle() {}

	Battle(vector<shared_ptr<Character>> party, sf::RenderWindow* window) {
		
		this->party = party;
		this->window = window;

	  	if(!texture.loadFromFile(background)) {
   			cout << "Error loading background" << endl;
   	 	}

   	 	if (!music.openFromFile(musicFile)) {
   	 		cout << "Error opening music file, '" << musicFile << "'" << endl;
   	 	}

   	 	music.setLoop(true);
		// music.play();
	}

	sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2u size = texture.getSize();
    sf::Music music;    
	sf::RenderWindow* window;

	vector<shared_ptr<Character>> party, 
								  enemyGroup;

	short frameNumber = 0;

	string background = "Images/BackgroundPineforest.png";
	string musicFile = "Sounds/Music/battle1.ogg";

	void generateEnemyParty();

	void drawBackground() {
    	if(!texture.loadFromFile("Images/BackgroundPineforest.png")) {
   			cout << "Error loading background" << endl;
   	 	}
    	sprite.setTexture(texture);  
    	sprite.setOrigin(0, 0);		
		window->draw(sprite);
	}

	void display() {

		// Displays debug data in the console
		// system("clear");
  //       cout << "Frame count: " << frameNumber++ << "\n\n";
		// cout << "Name" << setw(10) << "HP" << setw(10) << "BP" << setw(10) << "EP"
		//      << setw(14) << "Speed" << setw(14) << "Precision" << endl;
		// cout << "--------------------------------------------------------------" << endl;
		
		drawBackground();
		for(shared_ptr<Character> i : party) {
			i->display();
			i->battleAnimation.drawSprite(window);
		}
	}

private:

};

#endif // BATTLE_H