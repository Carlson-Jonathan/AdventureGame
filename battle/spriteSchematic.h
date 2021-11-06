// Copyright Jonathan Carlson 2021

#ifndef SPRITESCHEMATIC_H
#define SPRITESCHEMATIC_H

#include <iostream>
#include <fstream>
#include <vector>
#include "../miscellaneous.h"
using namespace std;

class SpriteSchematic {
public:

	SpriteSchematic() {}
	SpriteSchematic(string character) {
		this->character = character;
		getDataFromLibraryAndSetRawData(character);
		setNameImageWidthHeightFromRawData();
		setSpeedFromRawData();
		formatRawData();
		populateEntireSpriteSchematic();
		// displaySchematicData();
	}

    vector<string> rawData;
    vector<vector<string>> formattedData;

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

	void populateEntireSpriteSchematic();
    void getDataFromLibraryAndSetRawData(string keyword);
	void formatRawData();
	void setNameImageWidthHeightFromRawData();
	void tryToSetNameImageWidthHeightFromRawData();
	void setSpeedFromRawData();
    bool detectKeyword(string line, string keyword);
	vector<pair<short, short>> setSpritePointsInActionArrays(vector<string> words);
	void displayRawCharacterData();
	void displaySchematicData();
};
#endif // SPRITESCHEMATIC_H

