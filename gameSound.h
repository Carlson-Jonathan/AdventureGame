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
		battlePlayList.push_back("Sounds/Music/battle1.ogg");
		battlePlayList.push_back("Sounds/Music/battle2.ogg");
		battlePlayList.push_back("Sounds/Music/battle3.ogg");
		SFMLmusic.setLoop(true);
	}

	sf::Music SFMLmusic;
	vector<string> battlePlayList;

	void loadAndPlayRandomBattleSong() {
		short trackNumber = Miscellaneous::generateRandomNumber(3);
		if (!SFMLmusic.openFromFile(battlePlayList[trackNumber - 1])) {
			cout << "ERROR: Unable to load file '" << battlePlayList[trackNumber - 1] << "'" << endl;
			return;
		}
		cout << "Playing song '" << battlePlayList[trackNumber - 1] << "'" << endl;
		SFMLmusic.play();
	}

};

#endif // GAMESOUND_H