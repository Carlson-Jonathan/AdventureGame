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
 *
 * Call a texture with 'texture["category"]["character"]'
 **************************************************************************************************/

class TextureManager {
public:

	TextureManager() {
		populateAllTextureCategories();
		populateMasterTexturesObject();
	}

	sf::Texture texture;

	// Texture file paths. Grouped by category.
	vector< pair<string, string> > heroTextureFilePaths = {
		{"heroine",             "Images/heroine.png"}
	};

	vector< pair<string, string> > enemyTextureFilePaths = {
		{"dragon",				"Images/dragon.png"},
		{"cactopus", 			"Images/cactopus.png"}
	};

	vector< pair<string, string> > battlescapeTextureFilePaths = {
		{"forrestBattlescape", 	"Images/Battlescapes/forrestBattlescape.png"},
		{"desertBattlescape",	"Images/Battlescapes/desertBattlescape.png"},
		{"meadowBattlescape", 	"Images/Battlescapes/meadowBattlescape.png"}
	};

	// Groups of initilized textures. Named by category.
	map<string, sf::Texture> heroTextures;
	map<string, sf::Texture> enemyTextures;
	map<string, sf::Texture> battlescapeTextures;

	// Master Texture Object. A vector of initilized groups.
	map<string, map<string, sf::Texture>> textures;

	void populateTextureCategory(map<string, sf::Texture> & category, vector<pair<string, string>> textureFilePaths) {
		for(int i = 0; i < textureFilePaths.size(); i++) {
			if (!texture.loadFromFile(textureFilePaths[i].second)) 
				cout << "ERROR: Unable to load image '" << textureFilePaths[i].second << "'" << endl;
			else 
				category.insert({textureFilePaths[i].first, texture});
		}
	}

	void populateAllTextureCategories() {
		populateTextureCategory(heroTextures, 		 heroTextureFilePaths);
		populateTextureCategory(enemyTextures, 		 enemyTextureFilePaths);
		populateTextureCategory(battlescapeTextures, battlescapeTextureFilePaths);
	};

	void populateMasterTexturesObject() {
		textures.insert(std::pair<string, map<string, sf::Texture>>("heroTextures", heroTextures));
		textures.insert(std::pair<string, map<string, sf::Texture>>("enemyTextures", enemyTextures));
		textures.insert(std::pair<string, map<string, sf::Texture>>("battlescapeTextures", battlescapeTextures));
	};

	void displayAllInitializedTextures() {
		cout << "###############################"
		     << " List of Initialized Textures: "
		     << "###############################" << endl;
		for(auto i = textures.begin(); i != textures.end(); i++) {
			cout << "Category '" << i->first << "' (" << i->second.size() << " items):" << endl;
			for(auto j : i->second) {
				cout << "\t" << j.first << " (texture)\n";
			}
		}
		cout << "##############################################"
		     << "###############################################" << endl;
	}
};

#endif // TEXUTUREMANAGER_H
