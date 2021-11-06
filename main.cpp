// Copyright Jonathan Carlson 2021

#ifndef MAIN_CPP
#define MAIN_CPP

#include "battle/battle.h"
#include "battle/character.h"
#include "initializer.h"
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "textureManager.h"
#include <vector>

using namespace std;

int main() {

	auto globalData = make_shared<Initializer>();

	short screenWidth  = 1333,
		   screenHeight = 750,
		   frameRate    = 60,
		   textSize     = 32;

	sf::RenderWindow* pWindow = &globalData->window;
   sf::Music music;
	sf::Text text;
	sf::Font font; 
	sf::Clock clock;
	
	pWindow->setFramerateLimit(frameRate);

   // Fonts and text
	if (!font.loadFromFile("Fonts/Sweet Maple.otf")) cout << "Font not found" <<	endl; 
	text.setFont(font); 
	text.setCharacterSize(textSize); 

	// Music
	// if (!music.openFromFile("song.ogg"))
   //   	return -1; // error
	// music.play();

   // Create your objects
   vector<shared_ptr<Hero>> playerParty;

   playerParty.push_back(shared_ptr<Hero>(new Hero("heroine", globalData)));
   playerParty.push_back(shared_ptr<Hero>(new Hero("dragon", globalData)));
   playerParty.push_back(shared_ptr<Hero>(new Hero("cactopus", globalData)));

   Battle battle(playerParty, pWindow, globalData);

   // Master window loop. 
   while (pWindow->isOpen()) {

   	// Event Handler (button detectors)
	   sf::Event event;
      while (pWindow->pollEvent(event)) {

      	// Close the window by clicking the "X".
   	   if (event.type == sf::Event::Closed)
            pWindow->close();

      	// Catches window resize events. Adjusts resolution to match window resize.
         if (event.type == sf::Event::Resized) {
          	screenWidth  = event.size.width;
          	screenHeight = event.size.height;
           	sf::FloatRect visibleArea(0, 0, screenWidth, screenHeight);
           	pWindow->setView(sf::View(visibleArea));
         }
      }

      // Erase previous screen drawings (eliminates ghosting).
      pWindow->clear(sf::Color(102, 255, 255));

      /********************************************************************************************
      * All stuff between these lines gets drawn to the screen.
      *********************************************************************************************/      

      // window.draw(sprite);
      battle.generateFullBattlescape();

      /********************************************************************************************
      * End of Drawing loop.
      *********************************************************************************************/
      pWindow->display();
   }

    return 0;
}

#endif // MAIN_CPP