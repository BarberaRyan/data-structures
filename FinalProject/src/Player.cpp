/*
 * Player.cpp
 *
 *  Created on: Dec 11, 2016
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

Player::Player(){
	name = "Player";
	health = 80;
	attack = 0;
	defense = 40;
	psi = 6;
	hand = NULL;
}

Player::Player(Deck Deck){
	name = "Player";
	deck = Deck;
	health = 80;
	attack = 0;
	defense = 40;
	psi = 6;
	hand = NULL;
}

Player::Player(string Monster){
	name = Monster;
	health = 80;
	attack = 0;
	defense = 40;
	psi = 6;
	hand = NULL;

}



