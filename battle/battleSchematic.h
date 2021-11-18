// Copyright Jonathan Carlson 2021

#ifndef BATTLESCHEMATIC_H
#define BATTLESCHEMATIC_H

#include <iostream>
#include <vector>
using namespace std;

class BattleSchematic {
public:

	BattleSchematic() {}


	vector<string> enemyGroup;
	string battleBackground;
	

private: 
	vector<string> enemyCatagory1 = {
		"dragon",
		"cactopus",
		"spider"
	};

	vector<string> enemyCatagory2 = {
		"heroine",
		"rabbit",
		"sara"
	};

	vector<string> bosses;

	void generateRandomEnemyGroup();


	vector<string> enemyCatagory3;

};
#endif // BATTLESCHEMATIC_H