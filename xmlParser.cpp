#include "xmlParser.h"

void XMLParser::getAndVerifySpriteDataFromXMLFile(const char* file) {

	try {
		XMLError eResult = xmlDocument.LoadFile(file);
		string errorFile = file;
		string loadError = "Error loading from XML file '" + errorFile + "'!";

		if(eResult) 
			throw loadError;
	}
	catch (string error) {
		cout << error << endl;
		exit(3);
	}
}

XMLElement* XMLParser::initializeAndVerifyXMLNode(char* element, XMLElement* child, XMLElement* parent) {
	try {

		if(!parent) return xmlDocument.FirstChildElement(element);

		child = parent->FirstChildElement(element);

		if(!child)  {
			string ele = element;
			string error = "Unable to find XML element '" + ele + "'!";
			throw error;
		}
	}
	catch (string error) {
		cout << error << endl;
		exit(3);
	}

	return child;
}

void XMLParser::initializeAllNodes() {

	char node1[] = "characters";
	char node2[] = "monsters";
	char node3[] = "heroes";

	charactersNode = initializeAndVerifyXMLNode(node1, charactersNode, charactersNode);
	monstersNode   = initializeAndVerifyXMLNode(node2, monstersNode, charactersNode);
	heroesNode 	   = initializeAndVerifyXMLNode(node3, heroesNode, charactersNode);
}

void XMLParser::populatePublicNodeMaps(map<string, XMLElement*> & map, XMLElement* node) {
	string name;
	for(XMLElement* child = node->FirstChildElement(); 
	    child; 
	    child = child->NextSiblingElement()) {	 
	        name = child->FirstChildElement("name")->GetText();
	        map.insert(pair<string, XMLElement*>(name, child));
	}
}

void XMLParser::populateAllMaps() {
	populatePublicNodeMaps(monsters, monstersNode);
	populatePublicNodeMaps(heroes, heroesNode);
}

XMLElement* XMLParser::getMonster(string monster) {
	return monsters[monster];
}

XMLElement* XMLParser::getHero(string hero) {
	return heroes[hero];
}

void XMLParser::printNodeData(XMLElement* node) {
	cout << "Printing..." << endl;	
	for(XMLElement* child = node->FirstChildElement(); 
	    child; 
	    child = child->NextSiblingElement()) {	        
	        cout << "\t" << child->FirstChildElement("name")->GetText() << endl;
	}
}

void XMLParser::printMapData(map<string, XMLElement*> map) {
    cout << "{ Name : Node }" << endl;
    for (auto const & pair : map) {
        cout << "{ " << pair.first << " : " 
             << pair.second->FirstChildElement("name")->GetText() << " }\n";
    }
}