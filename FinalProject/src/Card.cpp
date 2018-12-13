/*
 * Card.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: Lenovo
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Card.hpp"
using namespace std;

Card::Card(){
	id = 0;
	name = "";
	type = "";
	psiCost = -1;
	cardEffects = NULL;

	next = NULL;
	prev = NULL;
	left = NULL;
	right = NULL;
}

/*
void Card::setId(int id){
	this->id = id;
}
void Card::setName(string name){
	this->name = name;
}
void Card::setType(string type){
	this->type = type;
}
void Card::setPsiCost(int cost){
	this->psiCost = cost;
}
void Card::resolveActiveEffect(string name){
		//The thing that happens when the card is activated or played
	//Todo Figure out how to work this
}
*/


