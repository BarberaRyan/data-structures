/*
 * NodeTB.hpp
 *
 *  Created on: Oct 26, 2016
 *      Author: Lenovo
 */


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

#ifndef NODETB_HPP_
#define NODETB_HPP_

class NodeTB {
	friend class MyGame;
	friend class BSTB;

	string data;//Node stores a string in memory

	int balanceFactor;//Determines how balanced the given node is
	int height;
	NodeTB *next;
	NodeTB *prev;
	NodeTB *up;//Points to parent node

	NodeTB *left;
	NodeTB*right;


public:
	NodeTB(string x);
	~NodeTB();
	string getData();
	NodeTB * getLeft();
	NodeTB * getRight();


};



#endif /* NODETB_HPP_ */
