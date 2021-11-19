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
		this->numberOfEnemies = Miscellaneous::generateRandomNumber(5);
		selectRandomEnemiesAndFillEnemyGroup(numberOfEnemies);
		generateEnemyLineCharacterPositions();
	}

	vector<string> enemyGroup;
	vector<shared_ptr<Character>> playerParty;
	vector<sf::Vector2f> enemyLineCharacterPositions;

	vector<sf::Vector2f> heroScreenPositions = {
		{sf::Vector2f(405.f, 325.f)}, // top row
		{sf::Vector2f(375.f, 475.f)}, // middle row
		{sf::Vector2f(345.f, 625.f)}  // bottom row
	};

	string selectRandomBackground() {
		short randNum = Miscellaneous::generateRandomNumber(availableBackgrounds.size() - 1);	
		return availableBackgrounds[randNum];
	}

	vector<string> availableBattleSongs = {
		"Sounds/Music/battle1.ogg",
		"Sounds/Music/battle2.ogg",
		"Sounds/Music/battle3.ogg"
	};

private:
	
	short numberOfEnemies;

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

	void selectRandomEnemiesAndFillEnemyGroup(short numOfEnemies) {
		for(;numOfEnemies; numOfEnemies--) {
			short randNum = Miscellaneous::generateRandomNumber(availableEnemies.size());	
			enemyGroup.push_back(availableEnemies[randNum - 1]);
		}
	}

	void generateEnemyLineCharacterPositions() {
		
		float firstEnemyYPos = 475.f;
		if(numberOfEnemies == 2)
			firstEnemyYPos = 550.f;

		float xOffset = 30.0f;
		float yOffset = 150.0f;
		float rowSpacing = 150.0f;

		sf::Vector2f firstEnemy  = {958.f, firstEnemyYPos};
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