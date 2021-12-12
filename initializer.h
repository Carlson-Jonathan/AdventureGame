// Copyright Jonathan Carlson 2021

#ifndef INITIALIZER_H
#define INITIALIZER_H

#include <iostream>
#include "eventHandler.h"
#include "gameSound.h"
#include "xmlParser.h"
#include "textureManager.h"

using namespace std;

class Initializer {
public:

	Initializer() : window(sf::VideoMode(screenWidth, screenHeight), "Jon's New Adventure Game"), 
		eventHandler(window, screenWidth, screenHeight) {
		window.setFramerateLimit(frameRate);
		srand (time(NULL));
	}

	unsigned int screenWidth  = 1333;
	unsigned int screenHeight = 750;
	short frameRate           = 60;

	sf::RenderWindow window;
	EventHandler     eventHandler;
	GameSound        gameSound;
	TextureManager   textures;
	XMLParser        xmlParser;
};

#endif // INITIALIZER_H