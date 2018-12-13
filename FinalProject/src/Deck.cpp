/*
 * Deck.cpp
 *
 *  Created on: Dec 10, 2016
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


Deck::Deck(){
	name = "deck";
	deckString = "";
	avatar = NULL;
	size = -1;
	first = NULL;
	next = NULL;
}

Deck::Deck(string details){
	name = "deck";//Will be changed so the input changes the name of the deck, I ran short of time
	deckString = details;
	avatar = NULL;
	size = -1;
	first = NULL;
	next = NULL;
}
