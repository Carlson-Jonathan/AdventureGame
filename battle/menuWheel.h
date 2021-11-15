#ifndef MENUWHEEL_H
#define MENUWHEEL_H

#include <iostream>
#include "battleAnimation.h"
using namespace std;

class MenuWheel {
public:

	MenuWheel() {}
	MenuWheel(Initializer & globalData) {
		setRectangle(globalData);
		setOthers();
	}

	short currentRotation;
	short selection;

	BattleAnimation battleAnimation;

	void rotateClockwise();
	void rotateCounterClockwise();

	void setRectangle(Initializer & globalData) {
		battleAnimation.rectangle.left = 0;
		battleAnimation.rectangle.top = 0;
		battleAnimation.rectangle.width = 141;
		battleAnimation.spriteSchematicXML.width = 141;
		battleAnimation.rectangle.height = 142;
		battleAnimation.spriteSchematicXML.height = 142;
		battleAnimation.sprite.setTextureRect(battleAnimation.rectangle);
		battleAnimation.sprite.setTexture(globalData.textures.textures["menuWheel"]);
	}

	void setOthers() {
		battleAnimation.spriteSchematicXML.idle = {{0, 0}, {141, 0}};
		battleAnimation.spriteSchematicXML.animationSpeeds.push_back(0.5f);
		battleAnimation.spriteSchematicXML.centerPoint = {
			battleAnimation.spriteSchematicXML.width / 2,
			battleAnimation.spriteSchematicXML.height / 2
		};
		battleAnimation.numberOfImages = 2;
	}

};
#endif // MENUWHEEL_H