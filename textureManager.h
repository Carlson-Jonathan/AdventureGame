#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

/**************************************************************************************************
 * About TextureManager
 * SFML textures are very particular about how they are used. Regarding textures, the SFML
 * documentation states,
 * 
 * 		"Using as few textures as possible is a good strategy, and the reason is simple: Changing 
 *		 the current texture is an expensive operation for the graphics card. Drawing many sprites 
 * 		 that use the same texture will yield the best performance.
 * 		 Additionally, using a single texture allows you to group static geometry into a single 
 * 		 entity (you can only use one texture per draw call), which will be much faster to draw 
 * 		 than a set of many entities. Batching static geometry involves other classes and is 	
 * 		 therefore beyond the scope of this tutorial, for further details see the vertex array 
 * 		 tutorial. Try to keep this in mind when you create your animation sheets or your tilesets: 
 * 		 Use as little textures as possible."
 * 
 * Because of this overhead and because developers would likely create the least efficient code, 
 * they seem to have intentially built in a flaw/safe guard against this which results in the 
 * "white square problem" (white square appears in the place of your sprite). See:
 * https://www.sfml-dev.org/tutorials/2.5/graphics-sprite.php#the-white-square-problem.
 * To get around this, I created this TextureManager class which creates and houses all in-scope
 * textures used by the program. The object will have a const pointer in the main.cpp file 
 * (a global pointer) that should be passed as a parameter to any objects/functions that would 
 * create any kind of sprite or animation.
 **************************************************************************************************/

class TextureManager {
public:

	TextureManager() {
		populateTexturesList();
	}

	sf::Texture texture;

	vector<pair<string, string>> fileNames = {
		{"dragon",		"Images/dragon.png"},
		{"cactopus", 	"Images/cactopus.png"}
	};

	map<string, sf::Texture> textures;

	void populateTexturesList() {

		for(int i = 0; i < fileNames.size(); i++) {
			if (!texture.loadFromFile(fileNames[i].second)) 
				cout << "ERROR: Unable to load image " << fileNames[i].second << endl;
			else
				textures.insert({fileNames[i].first, texture});
		}
	}

};

#endif // TEXUTUREMANAGER_H