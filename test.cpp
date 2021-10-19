#include <iostream>
#include <SFML/Graphics.hpp>
#include "textureManager.h"
#include "battle/spriteData.h"
using namespace std;

int main() {


	SpriteData spriteData("enemies", "dragon");
	spriteData.display();


	return 0;
}