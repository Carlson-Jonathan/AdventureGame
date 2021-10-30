#ifndef SPRITESCHEMATICXML_H
#define SPRITESCHEMATICXML_H

#include <iostream>
#include <fstream>
#include <vector>
#include "tinyxml2.h"

using namespace tinyxml2;
using namespace std;

class SpriteSchematicXML {
public:
	SpriteSchematicXML() {}
	SpriteSchematicXML(string character, shared_ptr<Initializer> globalData) {

		this->characterNode = globalData->xmlParser->getHero(character);
		// getAxes();
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

    XMLElement* characterNode;

    // void populateSchematic();
    // void printSchematicData();
    // void getAxes();


	void populateSchematic() {
		this->name     = characterNode->FirstChildElement("name")->GetText();
		this->fileName = characterNode->FirstChildElement("fileName")->GetText();
		this->width    = stoi(characterNode->FirstChildElement("imgWidth")->GetText());
		this->height   = stoi(characterNode->FirstChildElement("imgHeight")->GetText());


	}

	// void getAxes() {
	//     for(XMLElement* child = characterNode->FirstChildElement("idle")->FirstChildElement(); 
	//         child != NULL; 
	//         child = child->NextSiblingElement()) {	        
	//             cout << "\t" << child->FirstChildElement("name")->GetText() << endl;
	//     }

	// }

	void printSchematicData() {

	}
};
#endif // SPRITESCHEMATICXML_H


// int main() {
// 	// Read the sample.xml file and save as varaible
   
// 	/***************************************************************************/
   
//    	// Example 1: Basic example of getting data
// 	const char* monster = xmlDocument.FirstChildElement("characters")->
// 	                	  FirstChildElement("monsters")-> 
// 	                  	  FirstChildElement("cactopus")->
// 	                  	  FirstChildElement("name")->
// 	                  	  GetText();
		                  	  
// 	cout << "Example 1: Monster's name is " << monster << endl;

// 	/***************************************************************************/

// 	// Example 2: Setting and using a node	   
// 	// Check to make sure each node exists, otherwise you will get a segmentation fault.     

// 	XMLElement* characters;
// 	XMLElement* monsters;
// 	XMLElement* dragon;
	          
// 	characters 			    = xmlDocument.FirstChildElement("characters");
// 	if(characters) monsters = characters->FirstChildElement("monsters");
// 	if(monsters) dragon 	= monsters->FirstChildElement("dragon");

// 	// Extract data from node if it exists, otherwise, output an error
// 	if(dragon) {
// 	    const char * height = dragon->FirstChildElement("imgHeight")->GetText();	
// 	    cout << "Example 2: The dragon's image height is " << height << endl;
// 	} else 
// 	    cout << "Failed to load element! Node not found." << endl;
	
// 	/***************************************************************************/

// 	// Example 3: Print out all children (or children's attributes) in a node:
	
//         cout << "Example 3: A list of all monsters:" << endl;	
// 	if(monsters) {				     
// 	    for(XMLElement* child = monsters->FirstChildElement(); 
// 	        child != NULL; 
// 	        child = child->NextSiblingElement()) {	        
// 	            cout << "\t" << child->FirstChildElement("name")->GetText() << endl;
// 	    }
// 	}

	
   
//     return 0;
// }