// Copyright Jonathan Carlson 2021

#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "initializer.h"
#include <iostream>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
using namespace std;

class EventHandler {
public:

	EventHandler() {}
	EventHandler(sf::RenderWindow & window, unsigned int & screenWidth, unsigned int & screenHeight) {
		this->window = &window;
		this->screenWidth = &screenWidth;
		this->screenHeight = &screenHeight;
	}

	/*------------------------------------------------------------------------------------------------*/

	void listen() {
		while (window->pollEvent(event)) {

			switch(event.type) {
				case sf::Event::Closed:
					closeWindow();
					break;
				case sf::Event::Resized:
					resizeWindow();
					break;
				case sf::Event::MouseButtonPressed:
					mouseButton();
					break;
				case sf::Event::MouseButtonReleased:
					cout << "Released!" << endl;
					break;		
				case sf::Event::MouseWheelMoved:
					// Scroll Up = 1, Scroll Down = -1
					cout << "Mouse wheel Scroll:" << event.mouseWheel.delta << endl;
					break;	
				case sf::Event::MouseMoved:
					// cout << "Mouse position: {" << event.mouseMove.x << ", " << event.mouseMove.y << "}" << endl;
					break;	
				default:
					break;
			}	

			joystick(0);
			joystick(1);		

	    }
	}

private:

	unsigned int* screenWidth;
	unsigned int* screenHeight;

	sf::Event event;
	sf::RenderWindow* window;

	/*------------------------------------------------------------------------------------------------*/

	void closeWindow() {
		window->close();
	}

	/*------------------------------------------------------------------------------------------------*/

	void resizeWindow() {
		screenWidth  = &event.size.width;
	    screenHeight = &event.size.height;
	    sf::FloatRect visibleArea(0, 0, *screenWidth, *screenHeight);
	    window->setView(sf::View(visibleArea));
	}

	/*------------------------------------------------------------------------------------------------*/

	void mouseButton() {
		switch(event.key.code) {
			case sf::Mouse::Left:
				cout << "Mouse LEFT" << endl;
				break;
			case sf::Mouse::Right:
				cout << "Mouse RIGHT" << endl;
				break;
			case sf::Mouse::Middle:
				cout << "Mouse MIDDLE" << endl;
				break;
			case sf::Mouse::XButton1:
				cout << "Mouse XButton1" << endl;
				break;
			case sf::Mouse::XButton2:
				cout << "Mouse XButton2" << endl;
				break;
		}
	}	

	/*------------------------------------------------------------------------------------------------*/

	void joystick(short joystickNum) {
		vector<bool> Joystick_Buttons = {
			sf::Joystick::isButtonPressed(joystickNum, 0),			
			sf::Joystick::isButtonPressed(joystickNum, 1),
			sf::Joystick::isButtonPressed(joystickNum, 2),
			sf::Joystick::isButtonPressed(joystickNum, 3),
			sf::Joystick::isButtonPressed(joystickNum, 4),
			sf::Joystick::isButtonPressed(joystickNum, 5),
			sf::Joystick::isButtonPressed(joystickNum, 6),
			sf::Joystick::isButtonPressed(joystickNum, 7),
			sf::Joystick::isButtonPressed(joystickNum, 8),
			sf::Joystick::isButtonPressed(joystickNum, 9),
			sf::Joystick::isButtonPressed(joystickNum, 10),
			sf::Joystick::isButtonPressed(joystickNum, 11),
			sf::Joystick::isButtonPressed(joystickNum, 12),
			sf::Joystick::isButtonPressed(joystickNum, 13),
			sf::Joystick::isButtonPressed(joystickNum, 14),
			sf::Joystick::isButtonPressed(joystickNum, 15),
			sf::Joystick::isButtonPressed(joystickNum, 16),
			sf::Joystick::isButtonPressed(joystickNum, 17),
			sf::Joystick::isButtonPressed(joystickNum, 18)									
		};

		for(short i = 0; i < Joystick_Buttons.size(); i++) {
			if(Joystick_Buttons[i]) {
				cout << "Joystick " << joystickNum << " Button" << i << endl;
			}
		}

		// cout << "Joystick Axis: {" << sf::Joystick::getAxisPosition(joystickNum, sf::Joystick::X) << ", "
		// 	 << sf::Joystick::getAxisPosition(joystickNum, sf::Joystick::Y) << "}" << endl;

	}

};
#endif // EVENTHANDLER_H