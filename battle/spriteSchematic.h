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
		getDataFromLibraryAndSetRawData(character);
		setNameImageWidthHeightFromRawData();
		setSpeedFromRawData();
		formatRawData();
		populateEntireSpriteSchematic();
		displaySchematicData();
	}

    vector<string> rawData;
    vector<vector<string>> formattedData;

    string name;
    string fileName;
          
    short width;
    short height;
    vector<float> speed;

    // Arrays of points
    vector<pair<short, short>> idle;
    vector<pair<short, short>> attack;
    vector<pair<short, short>> defend;
    vector<pair<short, short>> takeDamage;
    vector<pair<short, short>> death;

	bool detectKeyword(string line, string keyword) {
	    std::size_t found = line.find(' ');

	    if (found != std::string::npos) 
	        return keyword == line.substr(0, found); 

	    return false;
	}

	void getDataFromLibraryAndSetRawData(string keyword) {

	    string line;
	    bool keyWordFound = false;
	    short lines = 0;

		ifstream spriteSchematics("battle/spriteSchematicsLibrary.init");
	    if(!spriteSchematics.is_open())
	        cout << "ERROR: Unable to open file 'battle/spriteSchematicsLibrary.init'" << endl;

	    while (getline(spriteSchematics, line)) {
	        if(line == "" && keyWordFound)
	            break;

	        if(!keyWordFound)
	            keyWordFound = detectKeyword(line, keyword);
	        
	        if(keyWordFound)
	            rawData.push_back(line); 
	        
	        lines++;
	    }
	    spriteSchematics.close();
	}

	void setNameImageWidthHeightFromRawData() {
        stringstream word(rawData[0]);
        string width, height;
        word >> name >> fileName >> width >> height;
        this->width = stoi(width);
        this->height = stoi(height);
    }

    void setSpeedFromRawData() {
    	for(int i = 1; i < rawData.size(); i++) {
    		string sp, null;
    		stringstream word(rawData[i]);
    		word >> null >> sp;
    		float number = Miscellaneous::convertStringToFloat(sp);
    		speed.push_back(number);
    	}
    }

    void formatRawData() {
        for(int i = 1; i < rawData.size(); i++) {
            string line = Miscellaneous::shrinkWhiteSpacing(rawData[i]);
            vector<string> words = Miscellaneous::parseString(line);
            formattedData.push_back(words);
        }
    }    

    vector<pair<short, short>> setSpritePointsInActionArrays(vector<string> words) {
	    vector<pair<short, short>> spritePoints;
	    for(short i = 3; i < words.size(); i += 2) {
	        short coordinateX = stoi(words[i - 1]);
	        short coordinateY = stoi(words[i]);
	        spritePoints.push_back(pair<short, short>(coordinateX, coordinateY));
	    }
	    return spritePoints;
	}	

    void populateEntireSpriteSchematic() {
        idle       = setSpritePointsInActionArrays(formattedData[0]);
        attack     = setSpritePointsInActionArrays(formattedData[1]);
        defend     = setSpritePointsInActionArrays(formattedData[2]);        
        takeDamage = setSpritePointsInActionArrays(formattedData[3]);
        death      = setSpritePointsInActionArrays(formattedData[4]);        
    }

	void displayRawCharacterData() {
	    cout << "RawData.size() = " << rawData.size() << endl;
	    for(string i : rawData) {
	        cout << i << endl;
	    }
	}

    void displaySchematicData() {
    	cout << "################### Sprite Schematic Data: ###################\n";
        cout << "Name:\t\t" << name << endl;
        cout << "FileName:\t" << fileName << endl;
        cout << "Width:\t\t" << width << endl;
        cout << "Height:\t\t" << height << endl;
        cout << "speed:\t\t";
        for(auto i : speed) cout << i << ", ";
        cout << "\nidle:\t\t";
        for(auto i : idle) {cout << "{" << i.first << ", " << i.second << "}, ";}
        cout << "\nattack:\t\t";
        for(auto i : attack) {cout << "{" << i.first << ", " << i.second << "}, ";}
        cout << "\ndefend:\t\t";
        for(auto i : defend) {cout << "{" << i.first << ", " << i.second << "}, ";}
        cout << "\ndamage:\t\t";
        for(auto i : takeDamage) {cout << "{" << i.first << ", " << i.second << "}, ";}
        cout << "\ndeath:\t\t";
        for(auto i : death) {cout << "{" << i.first << ", " << i.second << "}, ";}
        cout << endl;
    }    	
};
#endif // SPRITESCHEMATIC_H

