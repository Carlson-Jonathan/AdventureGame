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
		populateAndVerifyRootNode();
		populateCharacterGetterMap();
		verifyAllCharacterNodes();
	}

	XMLElement* getCharacter(string character) {return characterGetterMap[character];}

private:

	XMLDocument xmlDocument;
	XMLElement* rootNode;
	map<string, XMLElement*> characterGetterMap;

	void getAndVerifySpriteDataFromXMLFile(const char* file);
	void populateAndVerifyRootNode();
	void populateCharacterGetterMap();
	void insertCharacterNodeIntoMap(map<string, XMLElement*> & map, XMLElement* node);

	void verifyAllCharacterNodes();
	void verifyXMLNode(XMLElement* node, string childName, bool holdsText);
	void verifyActionPoints(XMLElement* actionNode);
	void verifyCharacterActions(XMLElement* characterNode);
	void verifyAllAxesHaveText(XMLElement* pointNodes);

	void printNodeData(XMLElement* node);
	void printMapData(map<string, XMLElement*> map);
};
#endif // XMLPARSER_H
