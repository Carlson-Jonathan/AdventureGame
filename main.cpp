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
#include <vector>

using namespace std;

int main() {

	Initializer globalData;
	
   // Create Player Party
   vector<shared_ptr<Hero>> playerParty;
   playerParty.push_back(shared_ptr<Hero>(new Hero("heroine", globalData)));
   playerParty.push_back(shared_ptr<Hero>(new Hero("dragon",  globalData)));
   playerParty.push_back(shared_ptr<Hero>(new Hero("rabbit",  globalData)));

   Battle battle(playerParty, globalData);

   // Master window loop. 
   while(globalData.window.isOpen()) {

   	// Event Handler (button detectors)
	   sf::Event event;
      while (globalData.window.pollEvent(event)) {

      	// Close the window by clicking the "X".
   	   if (event.type == sf::Event::Closed)
            globalData.window.close();

      	// Catches window resize events. Adjusts resolution to match window resize.
         if (event.type == sf::Event::Resized) {
          	globalData.screenWidth  = event.size.width;
          	globalData.screenHeight = event.size.height;
           	sf::FloatRect visibleArea(0, 0, globalData.screenWidth, globalData.screenHeight);
           	globalData.window.setView(sf::View(visibleArea));
         }
      }

      // Erase previous screen drawings (eliminates ghosting).
      globalData.window.clear(sf::Color(102, 255, 255));

      /********************************************************************************************
      * All stuff between these lines gets drawn to the screen. ***********************************
      *********************************************************************************************/      

      battle.generateFullBattlescape();

      /********************************************************************************************
      * End of Drawing loop. **********************************************************************
      *********************************************************************************************/
      globalData.window.display();
   }

    return 0;
}

#endif // MAIN_CPP