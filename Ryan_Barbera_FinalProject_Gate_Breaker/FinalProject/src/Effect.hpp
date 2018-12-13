/*
 * Effect.hpp
 *
 *  Created on: Dec 4, 2016
 *      Author: Lenovo
 */
#include "Node.hpp"
using namespace std;

#ifndef EFFECT_HPP_
#define EFFECT_HPP_

class Effect : public Node {
	string effectStr;
	friend class Map;
	friend class PlayGame;
public:
	Effect(string input);
};



#endif /* EFFECT_HPP_ */
