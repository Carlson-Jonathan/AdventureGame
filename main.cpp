// Copyright Jonathan Carlson 2021

#ifndef MAIN_CPP
#define MAIN_CPP

#include "battle/battle.h"
#include "battle/character.h"
#include "initializer.h"
#include <iostream>
#include <memory>
#include "PartyScreen/partyScreen.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <vector>

using namespace std;

int main() {

	cout << "Check x" << endl;
	Initializer globalData;
	cout << "Check y" << endl;	
   cout << "check x" << endl;
	
   // Create Player Party
   vector<shared_ptr<Character>> playerParty;
   playerParty.push_back(shared_ptr<Character>(new Character("heroine", globalData)));
   playerParty.push_back(shared_ptr<Character>(new Character("dragon",  globalData)));
   playerParty.push_back(shared_ptr<Character>(new Character("rabbit",  globalData)));

	PartyScreen partyScreen(globalData, playerParty);
   // BattleSchematic battleSchematic(playerParty);

   // Battle battle(battleSchematic, globalData);

	/**************************************  Main Game Loop ****************************************/
   while(globalData.window.isOpen()) {

   	partyScreen.runPartyScreenLoop();
   	// battle.runMainCombatLoop();

   }
   /***********************************************************************************************/

   return 0;
}

#endif // MAIN_CPP