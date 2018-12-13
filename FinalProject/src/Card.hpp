/*
 * Card.hpp
 *
 *  Created on: Nov 8, 2016
 *      Author: Lenovo
 */
#include "Effect.hpp"
#include "Node.hpp"
#ifndef CARD_HPP_
#define CARD_HPP_
using namespace std;

class Card : public Node {
	//TODO will use a factory design method to create the cards
	//Card is comprised of threesubclasses or three types of cards
	//Actions which you play and perform a one time ability
	//Proxies, which you play on the field, and have persistent effects OR can be activated and made to do something
	//And Avatar's an extension of proxies that act as the face of the deck like a class in hearthstone

	string type;
	string description;
	int psiCost;
	Effect* cardEffects;
	Card* next;//Needed to create the stack of cards for a deck
	friend class Map;
	friend class PlayGame;

public:
	Card();
	/*
	void setId(int id);
	void setName(string name);
	void setType(string type);
	void setPsiCost(int cost);
	void resolveActiveEffect(string name); //The thing that happens when the card is activated or played
*/
};



#endif /* CARD_HPP_ */
