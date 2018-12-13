/*
 * PlayGame.hpp
 *
 *  Created on: Nov 8, 2016
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
#include "Map.hpp"
using namespace std;
#ifndef PLAYGAME_HPP_
#define PLAYGAME_HPP_

class PlayGame{
	Player PlayerA;
	Player PlayerB;
	Map Library;
public:
	PlayGame();
	PlayGame(Deck deck);//Inputs a deck into play game to play with
	void statusPrint();//Prints out the currents status of the players
	void deckPrint();//Prints out the hand and descriptions of what all the cards do for the player
	string* convertEffect(Card Card);//COnverts the string labeling a cards effects into something readable
	void resolveEffect(Card effect, Player user, Player target);//Where the effects of a card are resolved
	/*
	void menu();//Where all the technical stuff happens, and where a game can be started
	void startGame();//Starts the game
	*/
};





#endif /* PLAYGAME_HPP_ */
