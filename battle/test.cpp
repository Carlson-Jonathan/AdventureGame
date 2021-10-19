#include <iostream>
#include "spriteData.h"
using namespace std;

int main() {

	SpriteData spriteData("enemies", "dragon");

	cout << spriteData.character << "\n" << spriteData.imageFile << endl;

	return 0;
}