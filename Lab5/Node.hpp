/*
 * Node.hpp
 *
 *  Created on: Nov 7, 2016
 *      Author: Debra
 */

#ifndef NODE_HPP_
#define NODE_HPP_

#include <iostream>
#include <string>
using namespace std;

class Node {
	friend class Document;
	friend class LLSE;
	Node *next;
	Node *prev;
	int count;
	string word;
public:
	Node(string w);
	Node();
};



#endif /* NODE_HPP_ */
