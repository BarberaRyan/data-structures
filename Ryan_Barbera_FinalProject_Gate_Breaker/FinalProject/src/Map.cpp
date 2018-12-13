/*
 * Map.cpp
 *
 *  Created on: Dec 4, 2016
 *      Author: Lenovo
 */
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <chrono>
#include "Map.hpp"
#include "Card.hpp"
#include "User.hpp"
#include "Effect.hpp"
#include "Deck.hpp"
using namespace std;

Map::Map(){//Lets you create something to add the the text file, which is then mapped
	userMap();
	cardMap();
}

void Map::cardMap(){
	Card** Nodes = new Card*[199];//Creat a prime number amount of noes, for now 199, this can be changed later
		for (int i = 0; i < 199; i++){
			Nodes[i] = new Card();
		}

	ifstream infile("Cards.txt");     // open file
		if (!infile.is_open()) {
			return;
		}
		string line ="";
		while ((line != "END") || (line == " ")) {          // loop getting single characters
			Card* newCard = new Card();
			Effect* tmpEffect = NULL;
			if (line == ""){//Initilize line if it is the first time
				getline (infile, line);//Gets the first line, every time it is called it advances the line
			}
			cout << line << endl;
			while (line != "END"){//When word is blank, a new card must be made
				newCard->name = line;
				getline (infile, line);
				newCard->type = line;
				getline (infile, line);
				newCard->description = line;
				getline (infile, line);
				newCard->psiCost = atoi(line.c_str());//Converts a string "0" to 0
				getline (infile,line);
				while (line != "END"){
					Effect* newEffect = new Effect(line);
					if (tmpEffect != NULL){
						tmpEffect->next = newEffect;
					}
					else{
						newCard->cardEffects = newEffect;
					}
					tmpEffect = newEffect;
					getline (infile, line);
				}
			}
			newCard->id = atoi(newCard->name.c_str());//Turns strings into ints
			if (Nodes[newCard->id % 199]->name == ""){//IF the node does not containa card
				Nodes[newCard->id % 199] = newCard;
			}

			else{
				Card* tmpCard = Nodes[newCard->id % 199];
				while (tmpCard->next != NULL){
					tmpCard = tmpCard->next;
				}
				tmpCard->next = newCard;//Add the new card at the end of the Linked list at the given node
			}

			if (newCard->name == "PSIBOOST"){//Due to dumb error's I'm using this as a makeshift break condition
				break;
			}
			getline (infile, line);//Gets the first line, every time it is called it advances the line

		}
	cout << "Complete Card map!" << endl;
	infile.close();
	//TODO make map include two 2D array, a CardMap and a UserMap
	Cardmap = &Nodes[0];
}



void Map::userMap(){
	User** Nodes = new User*[199];//Creat a prime number amount of noes, for now 199, this can be changed later
	for (int i = 0; i < 199; i++){
		Nodes[i] = new User();
	}

	ifstream infile("Users.txt");     // open file
		if (!infile.is_open()) {
			return;
		}
		string line = "";
		while (line != "END") {          // loop getting single characters

			User* newUser = new User();
			Deck* tmpDeck = NULL;
			if (line == ""){//Initilize line if it is the first time
				getline (infile, line);//Gets the first line, every time it is called it advances the line
			}
			while (line != "END"){//When word is blank, a new card must be made
				newUser->name = line;
				getline (infile, line);
				newUser->Password = line;
				getline (infile, line);

				//TODO Make a deck, a string to be converted into cards in memory during the game
				while (line != "END"){
					//TODO MAKE DECK HERE
					Deck* newDeck = new Deck(line);
					if (tmpDeck != NULL){
						tmpDeck->next = newDeck;
					}
					else{
						newUser->Decks = newDeck;
					}
					tmpDeck = newDeck;
					getline (infile, line);
				}
			}

			newUser->id = atoi(newUser->name.c_str());//Turns strings into ints
			if (Nodes[newUser->id % 199]->name == ""){
				Nodes[newUser->id % 199] = newUser;
			}
			else{
				User* tmpUser = Nodes[newUser->id % 199];
				while (tmpUser->next != NULL){
					tmpUser = tmpUser->next;
				}
				tmpUser->next = newUser;//Add the new card at the end of the Linked list at the given node
			}
			getline (infile, line);//Gets the first line, every time it is called it advances the line

		}
	cout << "Complete User map!" << endl;
	infile.close();
	Usermap = &Nodes[0];
	return;
}


/*
void Map::add(Node s){//Adds a given node to the map
	s.id = atoi(s.name.c_str());//Turns strings into ints
	if (Nodemap[s.id % 199] == NULL){
		Nodemap[s.id % 199] = s;
	}
	else{
		Node* tmpUser = Nodemap[s.id % 199];
		while (tmpUser->next != NULL){
			tmpUser = tmpUser->next;
		}
		tmpUser->next = s;//Add the new card at the end of the Linked list at the given node
	}
}
*/


User* Map::userSearch(string search){//Looks for a given name in either the usermap or the card map
	User* searchnode = Usermap[(atoi(search.c_str()))%199];
	if (searchnode->name != ""){
		if (searchnode->name == search){
			return searchnode;
		}
		while (searchnode->next != NULL){
			if (searchnode->next->name == search){
				return searchnode;
			}
			else{
				searchnode = searchnode->next;
			}
		}
		return NULL;
	}
	return NULL;
}

Card* Map::cardSearch(string search){//Looks for a given name in either the usermap or the card map
	Card* searchnode = Cardmap[(atoi(search.c_str()))%199];
	if (searchnode->name != ""){
		if (searchnode->name == search){
			return searchnode;
		}
		while (searchnode->next != NULL){
			if (searchnode->next->name == search){
				return searchnode;
			}
			else{
				searchnode = searchnode->next;
			}
		}
		return NULL;
	}
	return NULL;
}

Card Map::cardConvert(Card * card){//Turns a pointer into a card object
	Card tmp = Card();
	tmp.id = card->id;
	tmp.cardEffects = card->cardEffects;
	tmp.description = card->description;
	tmp.name = card->name;
	tmp.psiCost = card->psiCost;
	tmp.type = card->type;
	return tmp;

}



void Map::writeFile(string file){//Lets you create a node to add the the text file, which is then mapped
}
	//Adds it to the end of the text file

