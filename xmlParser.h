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
		initializeAllNodes();
		populateAllMaps();
	}

	XMLElement* getMonster(string monster);
	XMLElement* getHero(string hero);

private:

	XMLDocument xmlDocument;
	XMLElement* charactersNode;
	XMLElement* monstersNode;
	XMLElement* heroesNode;
	map<string, XMLElement*> monsters;
	map<string, XMLElement*> heroes;

	void getAndVerifySpriteDataFromXMLFile(const char* file);
	XMLElement* initializeAndVerifyXMLNode(char* element, XMLElement* child, XMLElement* parent);
	void initializeAllNodes();
	void populateNodeMap(map<string, XMLElement*> & map, XMLElement* node);
	void populateAllMaps();
	void printNodeData(XMLElement* node);
	void printMapData(map<string, XMLElement*> map);
};
#endif // XMLPARSER_H
