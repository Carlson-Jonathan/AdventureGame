// Copyright Jonathan Carlson 2021

#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;

class XMLParser {
public:
	
	XMLParser() {
		getAndVerifySpriteDataFromXMLFile("spriteSchematics.xml");
		populateAndVerifyCharactersNode();
		populateCharacterGetterMap();
	}

	XMLElement* getCharacter(string character) {return characterGetterMap[character];}

private:

	XMLDocument xmlDocument;
	XMLElement* charactersNode;
	map<string, XMLElement*> characterGetterMap;

	void getAndVerifySpriteDataFromXMLFile(const char* file);
	void populateAndVerifyCharactersNode();
	void populateCharacterGetterMap();
	void insertCharacterNode(map<string, XMLElement*> & map, XMLElement* node);
	void printNodeData(XMLElement* node);
	void printMapData(map<string, XMLElement*> map);
};
#endif // XMLPARSER_H
