/*
 * User.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: Lenovo
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "User.hpp"
using namespace std;

User::User(){
	id = 0;
	name = "";
	Decks = NULL;
	next = NULL;
	prev = NULL;
	left = NULL;
	right = NULL;
}
Deck* User::deckSearch(string name){
	if (Decks->name == name){
		return Decks;
	}
	if (Decks->next != NULL){
		Deck* tmpDeck= Decks->next;
		while (tmpDeck != NULL){
			if (tmpDeck->name == name){
				return tmpDeck;
			}
			else{
				tmpDeck = tmpDeck->next;
			}
		}
	}
	return NULL;
}

