/*
 * NodeTB.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: Lenovo
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "NodeTB.hpp"
using namespace std;

NodeTB::NodeTB(string k) {
	data = k;
	height = 1;
	balanceFactor = 0;
	next = NULL;
	prev = NULL;
	up = NULL;
	right = NULL;
	left = NULL;

}

NodeTB::~NodeTB() {
	if (next != NULL || prev != NULL) {
		cout << "deleting this DNode may cause a memory leak" << endl;
	}
}

string NodeTB::getData(){
	return data;
}

NodeTB * NodeTB::getRight(){
	return right;
}

NodeTB * NodeTB::getLeft(){
	return left;
}

