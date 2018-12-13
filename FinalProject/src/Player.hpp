/*
 * Player.hpp
 *
 *  Created on: Nov 8, 2016
 *      Author: Lenovo
 */
/*
 * Deck.hpp
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
using namespace std;
#ifndef PLAYER_HPP_
#define PLAYER_HPP_


class Player {

	string name;
	Deck deck;
	Card* hand;

	int health;
	int attack;
	int defense;
	int psi;

	friend class PlayGame;
	/*Things in the comments are unneeded at this time
	Card avatar;//Stores all the traits for the game, including life, psi, etc
	Card* field;//All the cards played and in front of the player
	*/
public:
	Player();
	Player(Deck Deck);
	Player(string Monster);

	/*
	Card* convertDeck(Deck deck);//Turns the string of the deck into a bunch of cards


	void drawCard();
	void playCard(string name);//Play a card and resove it's effect
	void removeCard(string name);//Removes a card from the field
	*/
};



#endif /* PLAYER_HPP_ */
