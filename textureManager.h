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
		{"dragon",				"Images/dragon.png"},
		{"cactopus", 			"Images/cactopus.png"},
		{"heroine",             "Images/heroine.png"},
		{"forrestBackground", 	"Images/forrestBackground.png"}
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