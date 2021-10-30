#ifndef INITIALIZER_H
#define INITIALIZER_H

#include <iostream>
#include "tinyxml2.h"
#include "xmlParser.h"
#include <memory>
using namespace std;

class Initializer {
public:

	Initializer() {
		xmlParser = make_shared<XMLParser>();
	}

	shared_ptr<XMLParser> xmlParser;


};

#endif // INITIALIZER_H