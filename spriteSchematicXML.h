#ifndef SPRITESCHEMATICXML_H
#define SPRITESCHEMATICXML_H

#include<iostream>
#include <fstream>
#include <vector>
#include "tinyxml2.cpp"

using namespace tinyxml2;
using namespace std;

class SpriteSchematicXML {

	SpriteSchematicXML() {}
	SpriteSchematicXML(string character) {
		getAndVerifyDataFromXMLFile();


	}

	XMLDocument xmlDocument;

    string character;
    string name;
    string fileName;
          
    int width;            // What are the chances we ever get 64k monitors?
    int height;
    vector<float> speed;

    // Arrays of points
    vector<pair<short, short>> idle;
    vector<pair<short, short>> attack;
    vector<pair<short, short>> defend;
    vector<pair<short, short>> takeDamage;
    vector<pair<short, short>> death;

    void getAndVerifyDataFromXMLFile();
    void populateSchematic(string character);

};
#endif // SPRITESCHEMATICXML_H

SpriteSchematicXML::getAndVerifyDataFromXMLFile() {
	xmlDocument.LoadFile("spriteSchematics.xml");

}

// Somehow map it so that the character parameter of the constructor leads to the correct XML node.
	// Map each individual element, but this would require me to update this file very time I make
	// a change to the schema.

	// Loop through the data and have it auto-map the elements, setting the key to the element's 
	// name attribute.

 	// foreach i : character (monsters, heros, misc)
	//    for each in i
	//        map insert <string, node> (FirstChild Element("name")->GetText(), node)

	//  cant do the above past monsters/heros/whatever because keys would not be unique.
	//  Instead, just map at that level

	//  Need to create an initializer class and have main create a shared ptr instance to pass down.

void populateSchematic(string character) {

}


int main() {
	// Read the sample.xml file and save as varaible
   
	/***************************************************************************/
   
   	// Example 1: Basic example of getting data
	const char* monster = xmlDocument.FirstChildElement("characters")->
	                	  FirstChildElement("monsters")-> 
	                  	  FirstChildElement("cactopus")->
	                  	  FirstChildElement("name")->
	                  	  GetText();
		                  	  
	cout << "Example 1: Monster's name is " << monster << endl;

	/***************************************************************************/

	// Example 2: Setting and using a node	   
	// Check to make sure each node exists, otherwise you will get a segmentation fault.     

	XMLElement* characters;
	XMLElement* monsters;
	XMLElement* dragon;
	          
	characters 			    = xmlDocument.FirstChildElement("characters");
	if(characters) monsters = characters->FirstChildElement("monsters");
	if(monsters) dragon 	= monsters->FirstChildElement("dragon");

	// Extract data from node if it exists, otherwise, output an error
	if(dragon) {
	    const char * height = dragon->FirstChildElement("imgHeight")->GetText();	
	    cout << "Example 2: The dragon's image height is " << height << endl;
	} else 
	    cout << "Failed to load element! Node not found." << endl;
	
	/***************************************************************************/

	// Example 3: Print out all children (or children's attributes) in a node:
	
        cout << "Example 3: A list of all monsters:" << endl;	
	if(monsters) {				     
	    for(XMLElement* child = monsters->FirstChildElement(); 
	        child != NULL; 
	        child = child->NextSiblingElement()) {	        
	            cout << "\t" << child->FirstChildElement("name")->GetText() << endl;
	    }
	}

	
   
    return 0;
}