/*
 * Main.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: Lenovo
 */

#include <iostream>
#include "Menu.hpp"
using namespace std;

int main() {
	string input;//Is not secure at all, a real game would bind parameters to prevent injections
	Menu game = Menu();
	cout << "game made!" << endl;
	bool on = true;
	bool login = false;
	while (on){
		cout << "Please login in, or type END to end session"<<endl;
		cout << "Note, default users are Alice, Bob, and James"<<endl;
		cout << "Also note password for all users is password"<<endl;
		cin >> input;
		if (input == "END"){
			cout << "Have a nice day"<<endl;
			on = false;
		}
		else{

			if(game.login(input)){
				cout << "Logged in as: " << input<<endl;
				login = true;
				while (login){
					cout << "Choose a deck to play game with or type END to log out"<<endl;
					cout << "Note, the only deck every user has is deck, so type 'deck' to start game"<<endl;
					cin >> input;
					if (input == "END"){
						game.logout();
						login = false;
					}
					if (game.deckSearch(input)){
						cout << "Valid deck, begining game..."<<endl;
						game.startGame();
					}
					else{
						cout << "Invalid input" << endl;
					}
				}
			}
			else{
				cout << "Login has failed " << input<<endl;

			}

		}
	}
	return 0;
}





