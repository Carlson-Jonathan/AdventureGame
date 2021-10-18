#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

struct Point {

	Point(short X, short Y) {
		this->X = X;
		this->Y = Y;
	}

	short X, Y;
};

#endif // POINT_H