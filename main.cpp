// Copyright Jonathan Carlson 2021

#ifndef MAIN_CPP
#define MAIN_CPP

#include "battle/battle.h"
#include "battle/character.h"
#include <iostream>
#include <memory>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <vector>

using namespace std;

int main() {

	short screenWidth  = 1333,
		   screenHeight = 750,
		   frameRate    = 60,
		   textSize     = 32,
		   partySize    = 1;

   sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SFML Examples");
   sf::Music music;
	sf::Text text;
	sf::Font font; 
	sf::Clock clock;
	
	// Creating a pointer of the window so I can pass it around as a parameter.
	sf::RenderWindow* pWindow;
	pWindow = &window;

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
   vector<shared_ptr<Character>> party;
   for(short i = 0; i < partySize; i++) {
   	cout << "Party member " << i << " being created.";
   	party.push_back(shared_ptr<Hero>(new Hero));
   	party[i]->name = "Member " + to_string(i + 1);
   }

   Battle battle(party, pWindow);



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

      battle.display();

      /********************************************************************************************
      * End of Drawing loop.
      *********************************************************************************************/
      pWindow->display();
   }

    return 0;
}

#endif // MAIN_CPP