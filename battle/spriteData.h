#ifndef SPRITEDATA_H
#define SPRITEDATA_H

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class SpriteData {
public:
	SpriteData() {}
	SpriteData(string character) {
		this->character   = character;
		upperLeftX 	  	  = monsters[character].first.first[0];
		upperLeftY 	 	  = monsters[character].first.first[1];
		width		 	  = monsters[character].first.first[2];
		height 	  		  = monsters[character].first.first[3];
		numberOfImages    = monsters[character].first.first[4];
		animationSpeed    = monsters[character].first.second;
		imageFile 	  	  = monsters[character].second;
	}

	short upperLeftX, 		// The rectangle is used to slice out the image from the texture.
		  upperLeftY, 
		  width, 
		  height,
		  numberOfImages;

	float animationSpeed;
	string imageFile,
		   character;

	void display() {
		cout << "Image File   = " << imageFile << "\n"
			 << "Upper Left X = " << upperLeftX << "\n" 
		     << "Upper Left Y = " << upperLeftY << "\n"
		     << "Lower RightX = " << width << "\n"
		     << "Lower RightY = " << height << "\n"
		     << "# of images  = " << numberOfImages << "\n" 
		     << "Cycle speed  = " << animationSpeed << endl;
	}

	map<string, pair<pair<vector<short>, float>, string>> monsters {

      // Key/name       X   Y   width  height  #images  FPS     Image File Path 
		{"dragon",   {{{0, 161, 191,   161,    3     }, 0.15f}, "../Images/dragon.png"}},
		{"cactopus", {{{0, 0  , 131,   100,    6     }, 0.75f}, "../Images/cactopus.png"}},
		{"heroine",  {{{0, 0  ,  54,    72,    5     }, 0.10f}, "../Images/heroine.png"}}
	};


};

#endif // SPRITEDATA_H