/*
 * LLSE.hpp
 *
 *  Created on: Nov 8, 2016
 *      Author: Debra
 */

#ifndef LLSE_HPP_
#define LLSE_HPP_


#include "Node.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class LLSE {
	friend class Document;
	Node *first;
	Node *last;
	int size;
	Node **wordarr;//An array of nodes

public:
	LLSE();
	~LLSE();
	void printLL();
	void addFirst(string x);
	void addAtFirst(string x);
	void insertUnique(string w);
	void quickSort(int x, int y);
	int partition(int beg,int end);
	Node **convertToArray();
	void insertionSortLL();
	void makeHeap();
	void heapSort();
	void printarr();
	void swap(Node* tmp1, Node* tmp2);//swaps two given nodes
	void percolatedown(int index, int arrsize);
};

#endif /* LLSE_HPP_ */
