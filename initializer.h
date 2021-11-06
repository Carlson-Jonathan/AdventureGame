#ifndef INITIALIZER_H
#define INITIALIZER_H

#include <iostream>
#include "tinyxml2.h"
#include "xmlParser.h"
#include <memory>
#include "textureManager.h"

using namespace std;

class Initializer {
public:

	Initializer() : window(sf::VideoMode(1333, 750), "SFML Examples") {}

	sf::RenderWindow window;
	TextureManager textures;
	XMLParser xmlParser;

};

#endif // INITIALIZER_H