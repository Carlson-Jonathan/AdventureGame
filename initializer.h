// Copyright Jonathan Carlson 2021

#ifndef INITIALIZER_H
#define INITIALIZER_H

#include <iostream>
#include "xmlParser.h"
#include "textureManager.h"

using namespace std;

class Initializer {
public:

	Initializer() : window(sf::VideoMode(screenWidth, screenHeight), "Jon's New Adventure Game") {
		window.setFramerateLimit(frameRate);
	}

	short screenWidth  = 1333;
	short screenHeight = 750;
	short frameRate    = 60;

	sf::RenderWindow window;
	TextureManager   textures;
	XMLParser        xmlParser;

};

#endif // INITIALIZER_H