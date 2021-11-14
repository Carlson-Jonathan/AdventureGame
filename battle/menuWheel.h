#ifndef MENUWHEEL_H
#define MENUWHEEL_H

#include <iostream>
#include "battleAnimation.h"
using namespace std;

class MenuWheel {
public:

	MenuWheel(Initializer & globalData) {}

	short currentRotation;
	short selection;
	pair<short, short> centerPoint;

	BattleAnimation battleAnimation();


	void rotateClockwise();
	void rotateCounterClockwise();


};
#endif // MENUWHEEL_H