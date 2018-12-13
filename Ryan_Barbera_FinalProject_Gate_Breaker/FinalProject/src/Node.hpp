/*
 * Node.hpp
 *
 *  Created on: Nov 30, 2016
 *      Author: Lenovo
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;
#ifndef NODE_HPP_
#define NODE_HPP_
class Node {
	Node *next;
	Node *prev;
	//For TREEES
	Node *left;
	Node *right;
	string name;
	int id;
	friend class Map;
	friend class Card;
	friend class User;
	friend class PlayGame;

public:
	Node();
	//todo Figure out if you are doing a tree for this or a hashmap``~````````


};



#endif /* NODE_HPP_ */
