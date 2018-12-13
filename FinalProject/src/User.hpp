/*
 * User.hpp
 *
 *  Created on: Nov 8, 2016
 *      Author: Lenovo
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Deck.hpp"
using namespace std;
#ifndef USER_HPP_
#define USER_HPP_

class User : public Node {
	string Password;
	User* next;
	Deck* Decks;//A set of decks, which are a bunch of stacks
	friend class Map;
	friend class Menu;
public:
      /*constructor, initializes AVL tree from “dict.txt” by calling ReadTreeFromFile
	*/
	User();
	~User();
	Deck* deckSearch();//Searches user for given deck, if they have it return the deck, otherwise return NULL
	void setName(string name);//Lets the user change their name
	void setPassword(string pword);//Lets the user change their password
	void help(); //Displays instructions for the game
	void makeDeck(); //Lets the user make a deck
	void deleteDeck(); //Removes deck from memory
	void renameDeck(string oldDeckName, string newDeckName);//lets the user delete a deck they made
	void printDecks();//Prints all decks for User
	void printDeck(string deckname);//Prints all cards for a given deck
	void playGame();//Starts a game against an opponent
	Deck* deckSearch(string name);//Finds a given deck that the user has
};


#endif /* USER_HPP_ */
