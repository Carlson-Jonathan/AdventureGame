#ifndef SPRITEDATA_H
#define SPRITEDATA_H

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class SpriteData {
public:
	SpriteData() {}
	SpriteData(string category, string character) {
		this->category 	  = category;
		this->character   = character;
		upperLeftX 	  	  = animation[category][character].first.first[0];
		upperLeftY 	 	  = animation[category][character].first.first[1];
		width		 	  = animation[category][character].first.first[2];
		height 	  		  = animation[category][character].first.first[3];
		numberOfImages    = animation[category][character].first.first[4];
		animationSpeed    = animation[category][character].first.second;
		imageFile 	  	  = animation[category][character].second;
	}

	short upperLeftX, 		
		  upperLeftY, 
		  width, 
		  height,
		  numberOfImages;

	float animationSpeed;

	string imageFile,
		   category,
		   character;

	map<string, short> point;
	map<string, pair<pair<vector<short>, float>, string>> enemies {
      // Key/name       X   Y   width  height  #images  FPS     Image File Path 
		{"dragon",   {{{0, 161, 191,   161,    3     }, 0.15f}, "../Images/dragon.png"}},
		{"cactopus", {{{0, 0  , 131,   100,    6     }, 0.75f}, "../Images/cactopus.png"}}
	};

	map<string, pair<pair<vector<short>, float>, string>> heroes {
		{"heroine",  {{{0, 0  ,  54,    72,    5     }, 0.10f}, "../Images/heroine.png"}}
	};

	map<string, map<string, pair<pair<vector<short>, float>, string>>> animation = {
		{"enemies", enemies},
		{"heroes", heroes}
	};

	void display() {
		cout << "Image File   = " << imageFile << "\n"
			 << "Upper Left X = " << upperLeftX << "\n" 
		     << "Upper Left Y = " << upperLeftY << "\n"
		     << "Lower RightX = " << width << "\n"
		     << "Lower RightY = " << height << "\n"
		     << "# of images  = " << numberOfImages << "\n" 
		     << "Cycle speed  = " << animationSpeed << endl;
	}
};

#endif // SPRITEDATA_H