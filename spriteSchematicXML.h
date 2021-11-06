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
	SpriteSchematicXML(string character, Initializer & globalData) {
		this->character = character;
		this->globalData = &globalData;
		setCharacterNode();
		populateEntireSchematic();
		printSchematicData();
	}

    string character;
    string name;
    string fileName;
    int width;           
    int height;
    vector<float> actionSpeeds;

    // Arrays of points
    vector<pair<short, short>> idle;
    vector<pair<short, short>> attack;
    vector<pair<short, short>> defend;
    vector<pair<short, short>> takeDamage;
    vector<pair<short, short>> death;

    Initializer* globalData;
    XMLElement* characterNode;
    XMLElement* action;
    XMLElement* X_Axes;
    XMLElement* Y_Axes;

    void setCharacterNode() {
		if(character == "heroine") 
			characterNode = globalData->xmlParser.getHero(character);
		else 
			characterNode = globalData->xmlParser.getMonster(character);
    }

	void populateEntireSchematic() {
		this->name     = characterNode->FirstChildElement("name")->GetText();
		this->fileName = characterNode->FirstChildElement("fileName")->GetText();
		this->width    = stoi(characterNode->FirstChildElement("imgWidth")->GetText());
		this->height   = stoi(characterNode->FirstChildElement("imgHeight")->GetText());
		populatePointsInAllActions();
	}

	void populateActionPoints(char* actionName, vector<pair<short, short>>* pointArray) {
		XMLElement* Xnode = characterNode->FirstChildElement(actionName)->FirstChildElement("X_axes")->FirstChildElement();
		XMLElement* Ynode = characterNode->FirstChildElement(actionName)->FirstChildElement("Y_axes")->FirstChildElement();

	    for(;Xnode; Xnode = Xnode->NextSiblingElement(), Ynode = Ynode->NextSiblingElement()) {	  
	        pointArray->push_back({{short(stoi(Xnode->GetText()))}, {short(stoi(Ynode->GetText()))}});
		}
	}	

	void populatePointsInAllActions() {
		char idl[] = "idle";
		char att[] = "attack";
		char def[] = "defend";
		char dmg[] = "damage";
		char dth[] = "death";

		if(name != "heroine") {
			populateActionPoints(idl, &idle);
			populateActionPoints(att, &attack);
			populateActionPoints(def, &defend);
			populateActionPoints(dmg, &takeDamage);
			populateActionPoints(dth, &death);
		}
	}

	void printActionPoints(vector<pair<short, short>> points) {
		for(auto i : points) {
			cout << "{" << i.first << ", " << i.second << "}, ";
		}
	}

	void printSchematicData() {
		cout << "Name = " << name << endl;
		cout << "FileName = " << fileName << endl;
		cout << "Width = " << width << endl;
		cout << "Height = " << height << endl;

		cout << "idle points: ";
		printActionPoints(idle);

		cout << "\nattack points: ";
		printActionPoints(attack);

		cout << "\ndefend points: ";
		printActionPoints(defend);

		cout << "\ntakeDamage points: ";
		printActionPoints(takeDamage);

		cout << "\ndeath points: ";
		printActionPoints(death);
		cout << endl;

	}
};
#endif // SPRITESCHEMATICXML_H
