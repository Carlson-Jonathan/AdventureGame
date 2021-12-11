// Copyright Jonathan Carlson 2021

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

class TextureManager {
public:

	TextureManager() {
		populateTextures();
	}

	map<string, sf::Texture> textures;

private:
	
	sf::Texture texture;
	vector< pair<string, string> > textureFilePaths = {

		// Party Screen Textures
		{"partyScreen",         "Images/PartyScreen/partyScreen.png"},

		// Character textures
		{"dragon",				"Images/Characters/dragon.png"},
		{"cactopus", 			"Images/Characters/cactopus.png"},
		{"heroine",             "Images/Characters/heroine.png"},
		{"rabbit",              "Images/Characters/rabbit.png"},
		{"sara",                "Images/Characters/sara.png"},
		{"spider",              "Images/Characters/spider.png"},

		// Non-Characters
		{"menuWheel",           "Images/Interface/menuWheel.png"},

		// Ella's Backgrounds
		{"meadowBackground", 	"Images/BattleBackgrounds/meadowBackground.png"},
		{"desertBackground", 	"Images/BattleBackgrounds/desertBackground.png"},

		// Battle Backgrounds From Opengameart.org
		{"battleback1", 		"Images/BattleBackgrounds/battleback1.png"},
		{"battleback2", 		"Images/BattleBackgrounds/battleback2.png"},
		{"battleback3", 		"Images/BattleBackgrounds/battleback3.png"},
		{"battleback4", 		"Images/BattleBackgrounds/battleback4.png"},
		{"battleback5", 		"Images/BattleBackgrounds/battleback5.png"},
		{"battleback6", 		"Images/BattleBackgrounds/battleback6.png"},
		{"battleback7", 		"Images/BattleBackgrounds/battleback7.png"},
		{"battleback8", 		"Images/BattleBackgrounds/battleback8.png"},
		{"battleback9", 		"Images/BattleBackgrounds/battleback9.png"},
		{"battleback10", 		"Images/BattleBackgrounds/battleback10.png"}
	};

	void populateTextures() {

		for(int i = 0; i < textureFilePaths.size(); i++) {
			if (!texture.loadFromFile(textureFilePaths[i].second)) 
				cout << "ERROR: Unable to load image '" << textureFilePaths[i].second << "'" << endl;
			else
				textures.insert({textureFilePaths[i].first, texture});
		}
	}

};

#endif // TEXUTUREMANAGER_H