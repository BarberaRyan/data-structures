/*
 * Menu.hpp
 *
 *  Created on: Nov 30, 2016
 *      Author: Lenovo
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Card.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "PlayGame.hpp"
#include "Map.hpp"
using namespace std;
#ifndef MENU_HPP_
#define MENU_HPP_

class Menu{
	User* user;
	Map Library;
	Deck* deck;
	friend class PlayGame;
	friend class Player;
public:
	Menu();//Where all the technical stuff happens, and where a game can be started, and where you can make decks, login, etc
	bool login(string name);//Logs you into the game
	void logout();//Logs out of the game
	void startGame();//Starts the game
	bool deckSearch(string name);//Looks for a deck by a given name
};



#endif /* MENU_HPP_ */
