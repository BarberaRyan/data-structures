/*
 * Avatar.hpp
 *
 *  Created on: Nov 8, 2016
 *      Author: Lenovo
 */

#ifndef AVATAR_HPP_
#define AVATAR_HPP_
#include "Proxy.hpp"
class Avatar : public Proxy{
	//UNUSED to be cards that reperesnt your character in battle
	int health;
public:
	Avatar();
	void setHealth(int health);
};




#endif /* AVATAR_HPP_ */
