// Copyright Jonathan Carlson 2021

#ifndef MAIN_CPP
#define MAIN_CPP

#include "battle/battle.h"			// For generating a battle object
#include "battle/character.h"		// For creating a player character party
#include <iostream>
#include <memory>						// Smart Pointers
#include <SFML/Graphics.hpp>		// Creating an SFML window
// #include <SFML/Network.hpp>	// Future use?
#include <SFML/System.hpp>			
#include <SFML/Window.hpp>			// Creating an SFML window
#include "textureManager.h"		// For creating a global textures object
#include <vector>

using namespace std;

int main() {

	short screenWidth  = 1333,
		   screenHeight = 750,
		   frameRate    = 60,
		   textSize     = 32;

   sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Enter Game Name Here");
	sf::RenderWindow* pWindow = &window;
   // sf::Music music;
	// sf::Text text;
	// sf::Font font; 
	// sf::Clock clock;
	sf::Event event;
	
	pWindow->setFramerateLimit(frameRate);
   auto textures = make_shared<TextureManager>();

   // Fonts and text
	// if (!font.loadFromFile("Fonts/Sweet Maple.otf")) cout << "Font not found" <<	endl; 
	// text.setFont(font); 
	// text.setCharacterSize(textSize); 

	// Music
	// if (!music.openFromFile("song.ogg"))
   //   	return -1; // error
	// music.play();

   // Create your objects
   vector<shared_ptr<Hero>> playerParty;
   playerParty.push_back(make_shared<Hero>(textures, "heroine"));
   // playerParty.push_back(make_shared<Enemy>(textures, "dragon"));
   // playerParty.push_back(make_shared<Enemy>(textures, "cactopus"));

   // This will eventually be generated in some sort of game overworld object.
   Battle battle(playerParty, pWindow, textures);

   // Master window loop. 
   while (pWindow->isOpen()) {

   	// Event Handler (button detectors)
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

		// This will eventually be called by some sort of game overworld object.      
      battle.generateFullBattlescape();

      /********************************************************************************************
      * End of Drawing loop.
      *********************************************************************************************/
      pWindow->display();
   }

    return 0;
}

#endif // MAIN_CPP