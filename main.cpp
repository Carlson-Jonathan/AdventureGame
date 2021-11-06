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
	sf::RenderWindow* window = &globalData->window;
	
   // Create your objects
   vector<shared_ptr<Hero>> playerParty;

   playerParty.push_back(shared_ptr<Hero>(new Hero("heroine", globalData)));
   playerParty.push_back(shared_ptr<Hero>(new Hero("dragon", globalData)));
   playerParty.push_back(shared_ptr<Hero>(new Hero("cactopus", globalData)));

   Battle battle(playerParty, window, globalData);

   // Master window loop. 
   while (window->isOpen()) {

   	// Event Handler (button detectors)
	   sf::Event event;
      while (window->pollEvent(event)) {

      	// Close the window by clicking the "X".
   	   if (event.type == sf::Event::Closed)
            window->close();

      	// Catches window resize events. Adjusts resolution to match window resize.
         if (event.type == sf::Event::Resized) {
          	globalData->screenWidth  = event.size.width;
          	globalData->screenHeight = event.size.height;
           	sf::FloatRect visibleArea(0, 0, globalData->screenWidth, globalData->screenHeight);
           	window->setView(sf::View(visibleArea));
         }
      }

      // Erase previous screen drawings (eliminates ghosting).
      window->clear(sf::Color(102, 255, 255));

      /********************************************************************************************
      * All stuff between these lines gets drawn to the screen. ***********************************
      *********************************************************************************************/      

      battle.generateFullBattlescape();

      /********************************************************************************************
      * End of Drawing loop. **********************************************************************
      *********************************************************************************************/
      window->display();
   }

    return 0;
}

#endif // MAIN_CPP