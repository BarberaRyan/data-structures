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
using namespace std;
#ifndef DECK_HPP_
#define DECK_HPP_


class Deck {
	string name;
	Deck* next;
	string deckString;
	Card* avatar;//The "user" of the deck, allows for certain cards to be picked
	int size;//Size of the deck
	Card* first;//First card of the deck
	friend class Map;
	friend class User;
	friend class PlayGame;
	//Actions they can take any turn
public:
	Deck();
	Deck(string details);//The whole deck can be made out of a string seperated by |
	void addCard(string cardName);//Adds a card to the deck during deck building
	void removeCard(string cardName);//Removes card from the deck during deck building
	void shuffleDeck();//Shuffles the deck
	Card* convertToCards();//Converts the deck string into cards
	friend class Map;
};


#endif /* DECK_HPP_ */
