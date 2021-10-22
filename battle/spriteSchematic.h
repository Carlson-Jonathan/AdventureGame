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
		cout << "The non-default constructor for SpriteSchematic is being called. Character value = " << character << endl;
		setSpriteSchematicWithRawDataFromLibrary(character);
		displayRawCharacterData();
	}

    vector<string> rawData;

    string name;
    string fileName;
          
    short width;
    short height;

    // Arrays of points
    vector<pair<short, short>> idle;
    vector<pair<short, short>> attack;
    vector<pair<short, short>> defend;
    vector<pair<short, short>> damage;
    vector<pair<short, short>> death;

	// void populateObject();
	// void setSpriteSchematicWithRawDataFromLibrary(string keyword);
	// bool detectKeyword(string line, string keyword);
	// void displayRawCharacterData();

	bool detectKeyword(string line, string keyword) {
	    std::size_t found = line.find(' ');

	    if (found != std::string::npos) 
	        return keyword == line.substr(0, found); 

	    return false;
	}

	void setSpriteSchematicWithRawDataFromLibrary(string keyword) {

		ifstream spriteSchematics("battle/spriteSchematicsLibrary.init");
	    if(!spriteSchematics.is_open())
	        cout << "ERROR: Unable to open file 'battle/spriteSchematicsLibrary.init'" << endl;

	    string line;
	    bool keyWordFound = false;
	    short lines = 0;

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

	void displayRawCharacterData() {
	    cout << "RawData.size() = " << rawData.size() << endl;
	    for(string i : rawData) {
	        cout << i << endl;
	    }
	}


};
#endif // SPRITESCHEMATIC_H

