#ifndef GAMESOUND_H
#define GAMESOUND_H

#include <iostream>
#include <SFML/Audio.hpp>
#include "miscellaneous.h"
#include <vector>
using namespace std;

class GameSound {
public:

	GameSound() {
		SFMLmusic.setLoop(true);
	}

	void loadAndPlayBattleMusic(string song) {
		if(!SFMLmusic.openFromFile(song)) {
			cout << "ERROR: Unable to load file '" << song << "'" << endl;
			return;
		}
		SFMLmusic.play();
	}

private: 

	sf::Music SFMLmusic;

};

#endif // GAMESOUND_H