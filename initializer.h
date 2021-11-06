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

	Initializer() {
		xmlParser = make_shared<XMLParser>();
		textures  = make_shared<TextureManager>();
	}


	shared_ptr<XMLParser> xmlParser;
	shared_ptr<TextureManager> textures;

};

#endif // INITIALIZER_H