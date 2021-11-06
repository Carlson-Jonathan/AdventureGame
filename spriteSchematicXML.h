// Copyright Jonathan Carlson 2021

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

	void printSchematicData();

private:

    Initializer* globalData;
    XMLElement* characterNode;
    XMLElement* action;
    XMLElement* X_Axes;
    XMLElement* Y_Axes;

    void setCharacterNode();
	void populateEntireSchematic();
	void populateActionPoints(char* actionName, vector<pair<short, short>>* pointArray);
	void populatePointsInAllActions();
	void printActionPoints(vector<pair<short, short>> points);
};

#endif // SPRITESCHEMATICXML_H
