/*
 * Menu.cpp
 *
 *  Created on: Dec 4, 2016
 *      Author: Lenovo
 */
#include "Menu.hpp"
#include "Map.hpp"
#include "User.hpp"

Menu::Menu(){//Where all the technical stuff happens, and where a game can be started, and where you can make decks, login, etc
	user = NULL;
	Library = Map();
	deck = NULL;
}

bool Menu::login(string name){//Logs you into the game or sets up a user return true if login was sucessful and false if it faile
	user = Library.userSearch(name);
	if (user == NULL){
		return false;
	}
	else{
		string input;
		cout << "Type in password" << endl;
		cin  >> input;
		if (input == user->Password){
			cout << "Password correct" << endl;
			return true;
		}
		else{
			user = NULL;
			cout << "Incorrect password" << endl;
			return false;
		}
	}

	return true;
}

void Menu::logout(){
	deck = NULL;
	user = NULL;
}

bool Menu::deckSearch(string name){
	deck = user->deckSearch(name);
	if (deck != NULL){
		return true;
	}
	else{
		return false;
	}

}

void Menu::startGame(){//Starts the game
	PlayGame(deck);
}

