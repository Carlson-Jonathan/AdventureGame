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

/*------------------------------------------------------------------------------------------------*/

void XMLParser::populateAndVerifyCharactersNode() {
	charactersNode = xmlDocument.FirstChildElement("characters");
	if(!charactersNode) {
		cout << "Characters node did not set" << endl;
		throw perror;
	}
}

/*------------------------------------------------------------------------------------------------*/

void XMLParser::populateCharacterGetterMap() {
	insertCharacterNode(characterGetterMap, charactersNode);
}

/*------------------------------------------------------------------------------------------------*/

void XMLParser::insertCharacterNode(map<string, XMLElement*> & map, XMLElement* node) {
	string name;
	for(XMLElement* child = node->FirstChildElement(); 
	    child; 
	    child = child->NextSiblingElement()) {	 
	        name = child->FirstChildElement("name")->GetText();
	        map.insert(pair<string, XMLElement*>(name, child));
	}
}



/**************************************************************************************************/

void XMLParser::printNodeData(XMLElement* node) {
	cout << "Printing..." << endl;	
	for(XMLElement* child = node->FirstChildElement(); 
	    child; 
	    child = child->NextSiblingElement()) {	        
	        cout << "\t" << child->FirstChildElement("name")->GetText() << endl;
	}
}

/*------------------------------------------------------------------------------------------------*/

void XMLParser::printMapData(map<string, XMLElement*> map) {
    cout << "{ Name : Node }" << endl;
    for (auto const & pair : map) {
        cout << "{ " << pair.first << " : " 
             << pair.second->FirstChildElement("name")->GetText() << " }\n";
    }
}