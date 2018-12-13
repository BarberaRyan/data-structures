/*
 * Node.cpp
 *
 *  Created on: Nov 7, 2016
 *      Author: Debra
 */

#include "Node.hpp"
#include <iostream>
#include <string>
using namespace std;

Node::Node(string s) {
	count = 1;
	next = NULL;
	prev = NULL;
	word = s;
}
Node::Node() {
	count = 1;
	next = NULL;
	prev = NULL;
	word = "s";
}


