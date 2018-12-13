/*
 * Proxy.hpp
 *
 *  Created on: Nov 8, 2016
 *      Author: Lenovo
 */

#ifndef PROXY_HPP_
#define PROXY_HPP_
#include "Card.hpp"
class Proxy : public Card{
	//UNUSED to be used to summon monsters on the field
	int atk;
	int def;
	int psi;
	string passiveEffect();

public:
	Proxy();
	void resolvePassiveEffect(string name); //The thing that happens when the card is activated or played
	void setAtk(int x);
	void setDef(int x);
	void setPsi(int x);
};



#endif /* PROXY_HPP_ */
