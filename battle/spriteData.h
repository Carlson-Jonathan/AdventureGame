#ifndef SPRITEDATA_H
#define SPRITEDATA_H

#include <iostream>
using namespace std;

class SpriteData {
public:
	SpriteData() {
		cout << "The DEFAULT SpriteData constructor is being called." << endl;
	}

	SpriteData(short upperLeftX, short upperLeftY, short lowerRightX, short lowerRightY,
		       short spritePositionX, short spritePositionY, short numberOfImages,
		       float animationSpeed, string imageFile) {
		this->upperLeftX = upperLeftX;
		this->upperLeftY = upperLeftY;
		this->lowerRightX = lowerRightX;
		this->lowerRightY = lowerRightY;
		this->spritePositionX = spritePositionX;
		this->spritePositionY = spritePositionY;
		this->numberOfImages = numberOfImages;
		this->animationSpeed = animationSpeed;
		this->imageFile = imageFile;
		cout << "The non-default SpriteData constructor is being called." << endl;
	}

	short upperLeftX = 0, 		// The rectangle is used to slice out the image from the texture.
		  upperLeftY = 161, 
		  lowerRightX = 191, 
		  lowerRightY = 161,
		  spritePositionX = 150,	// This sets where the sprite will sit on the window (top left corner)
		  spritePositionY = 100,
		  numberOfImages = 3;

	float animationSpeed = 0.2f;
	string imageFile = "Images/dragon.png";

	void displayData() {
		cout << "Image File   = " << imageFile << "\n"
			 << "Upper Left X = " << upperLeftX << "\n" 
		     << "Upper Left Y = " << upperLeftY << "\n"
		     << "Lower RightX = " << lowerRightX << "\n"
		     << "Lower RightY = " << lowerRightY << "\n"
		     << "# of images  = " << numberOfImages << endl; 
	}

};

#endif // SPRITEDATA_H