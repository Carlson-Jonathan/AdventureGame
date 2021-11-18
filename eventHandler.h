// Copyright Jonathan Carlson 2021

#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "initializer.h"
#include <iostream>
using namespace std;

class EventHandler {
public:

	EventHandler() {}
	EventHandler(Initializer & globalData) {
		this->globalData = &globalData;
	}

	/*------------------------------------------------------------------------------------------------*/

	void listen() {
		while (globalData->window.pollEvent(event)) {

			switch(event.type) {
				case sf::Event::Closed:
					closeWindow();
					break;
				case sf::Event::Resized:
					resizeWindow();
					break;
				default:
					break;
			}	

	    }
	}

private:

	sf::Event event;
	Initializer* globalData;

	/*------------------------------------------------------------------------------------------------*/

	void closeWindow() {
		globalData->window.close();
	}

	/*------------------------------------------------------------------------------------------------*/

	void resizeWindow() {
		globalData->screenWidth  = event.size.width;
	    globalData->screenHeight = event.size.height;
	    sf::FloatRect visibleArea(0, 0, globalData->screenWidth, globalData->screenHeight);
	    globalData->window.setView(sf::View(visibleArea));
	}

};
#endif // EVENTHANDLER_H