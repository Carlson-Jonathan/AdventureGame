#ifndef SPRITESCHEMATICXML_H
#define SPRITESCHEMATICXML_H

#include <fstream>
#include "initializer.h"
#include <iostream>
#include "tinyxml2.h"
#include <vector>

using namespace tinyxml2;
using namespace std;

class SpriteSchematicXML {
public:
	SpriteSchematicXML() {}
	SpriteSchematicXML(string character, shared_ptr<Initializer> globalData) {
		this->character = character;
		this->globalData = globalData;
		setCharacterNode();
		populateSchematic();
		printSchematicData();
	}

    string character;
    string name;
    string fileName;
    int width;           
    int height;
    vector<float> speed;

    // Arrays of points
    vector<pair<short, short>> idle;
    vector<pair<short, short>> attack;
    vector<pair<short, short>> defend;
    vector<pair<short, short>> takeDamage;
    vector<pair<short, short>> death;

    shared_ptr<Initializer> globalData;
    XMLElement* characterNode;


    // void populateSchematic();
    // void printSchematicData();
    // void getAxes();

    void setCharacterNode() {
		if(character == "heroine") 
			characterNode = globalData->xmlParser->getHero(character);
		else 
			characterNode = globalData->xmlParser->getMonster(character);
    }

	void populateSchematic() {
		this->name     = characterNode->FirstChildElement("name")->GetText();
		this->fileName = characterNode->FirstChildElement("fileName")->GetText();
		this->width    = stoi(characterNode->FirstChildElement("imgWidth")->GetText());
		this->height   = stoi(characterNode->FirstChildElement("imgHeight")->GetText());
	}

	void printSchematicData() {
		cout << "Name = " << name << endl;
		cout << "FileName = " << fileName << endl;
		cout << "Width = " << width << endl;
		cout << "Height = " << height << "\n\n";

		// XMLElement* xAxes = characterNode->FirstChildElement("idle");
	    // for(XMLElement* child = characterNode->FirstChildElement("idle"); 
	    //     child != NULL; 
	    //     child = child->NextSiblingElement()) {	        
	    //         cout << "\t" << child->FirstChildElement("X1")->GetText() << endl;
	    // }

	}

};
#endif // SPRITESCHEMATICXML_H
