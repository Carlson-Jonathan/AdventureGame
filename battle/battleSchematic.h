// Copyright Jonathan Carlson 2021

#ifndef BATTLESCHEMATIC_H
#define BATTLESCHEMATIC_H

#include "character.h"
#include <iostream>
#include <memory>
#include "../miscellaneous.h"
#include <vector>
using namespace std;

class BattleSchematic {
public:

	BattleSchematic() {}
	BattleSchematic(vector<shared_ptr<Character>> playerParty) {
		this->playerParty = playerParty;

		selectRandomEnemiesAndFillEnemyGroup(Miscellaneous::generateRandomNumber(5));
		generateEnemyLineCharacterPositions();
	}

	vector<string> enemyGroup;
	vector<shared_ptr<Character>> playerParty;
	vector<string> bosses;


	vector<string> availableEnemies = {
		"sara",
		"rabbit",
		"heroine",
		"dragon",
		"spider",
		"cactopus"
	};

	vector<string> availableBackgrounds = {
		"meadowBackground",
		"desertBackground",
		"battleback1",
		"battleback2",
		"battleback3",
		"battleback4",
		"battleback5",
		"battleback6",
		"battleback7",
		"battleback8",
		"battleback9",
		"battleback10"
	};

	vector<sf::Vector2f> enemyLineCharacterPositions;

	vector<sf::Vector2f> heroScreenPositions = {
		{sf::Vector2f(400.f, 325.f)}, // top row
		{sf::Vector2f(375.f, 475.f)}, // middle row
		{sf::Vector2f(350.f, 625.f)}  // bottom row
	};

	vector<sf::Vector2f> enemyScreenPositions = {
		{sf::Vector2f(933.f, 325.f)}, // top row
		{sf::Vector2f(958.f, 475.f)}, // middle row
		{sf::Vector2f(986.f, 625.f)}  // bottom row
	};

	string selectRandomBackground() {
		short randNum = Miscellaneous::generateRandomNumber(availableBackgrounds.size() - 1);	
		return availableBackgrounds[randNum];
	}

	void selectRandomEnemiesAndFillEnemyGroup(short numOfEnemies) {
		for(;numOfEnemies; numOfEnemies--) {
			short randNum = Miscellaneous::generateRandomNumber(availableEnemies.size());	
			enemyGroup.push_back(availableEnemies[randNum - 1]);
		}
	}

	void generateEnemyLineCharacterPositions() {
		short xOffset = 25.0f;
		short yOffset = 150.0f;
		short rowSpacing = 150.0f;

		sf::Vector2f firstEnemy  = {958.f, 475.f};
		sf::Vector2f secondEnemy = {firstEnemy.x - xOffset, firstEnemy.y - yOffset};
		sf::Vector2f thirdEnemy  = {firstEnemy.x + xOffset, firstEnemy.y + yOffset};  
		sf::Vector2f fourthEnemy = {firstEnemy.x + rowSpacing,      
									firstEnemy.y - (yOffset / 2)};
		sf::Vector2f fifthEnemy  = {thirdEnemy.x + rowSpacing,
									firstEnemy.y + (yOffset / 2)};
		
		enemyLineCharacterPositions.push_back(firstEnemy);
		enemyLineCharacterPositions.push_back(secondEnemy);
		enemyLineCharacterPositions.push_back(thirdEnemy);
		enemyLineCharacterPositions.push_back(fourthEnemy);
		enemyLineCharacterPositions.push_back(fifthEnemy);
	}

};
#endif // BATTLESCHEMATIC_H