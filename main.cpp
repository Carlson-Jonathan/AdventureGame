// Copyright Jonathan Carlson 2021

#ifndef MAIN_CPP
#define MAIN_CPP

#include "battle/battle.h"
#include "battle/character.h"
#include "initializer.h"
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <vector>

using namespace std;

int main() {

	Initializer globalData;
	
   // Create Player Party
   vector<shared_ptr<Character>> playerParty;
   playerParty.push_back(shared_ptr<Character>(new Character("heroine", globalData)));
   playerParty.push_back(shared_ptr<Character>(new Character("dragon",  globalData)));
   playerParty.push_back(shared_ptr<Character>(new Character("rabbit",  globalData)));

   BattleSchematic battleSchematic(playerParty);

   Battle battle(battleSchematic, globalData);

	/**************************************  Main Game Loop ****************************************/
   while(globalData.window.isOpen()) {



   	battle.runMainCombatLoop();

   }
   /***********************************************************************************************/

   return 0;
}

#endif // MAIN_CPP