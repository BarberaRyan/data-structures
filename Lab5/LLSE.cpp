/*
 * LLSE.cpp
 *
 *  Created on: Nov 8, 2016
 *      Author: Debra
 */

#include "Node.hpp"
#include "LLSE.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

LLSE::LLSE() {
	first = NULL;
	last = NULL;
	size = 0;
}
LLSE::~LLSE() {
	Node *tmp = first;
	for(int i = 0; i < size; i++) {
		tmp = first->next;
		delete first;
		first = tmp;
	}
}

void LLSE::printLL() {
	Node *tmp = first;
	while (tmp != NULL) {
		cout << tmp->count <<":"<<tmp->word << endl;
		tmp = tmp->next;
	}
}

void LLSE::addFirst(string w) {
	first = new Node(w);
	last = first;
	size = 1;
}



void LLSE::insertUnique(string w) {
	Node *tmp = first;
	if (tmp == NULL) {
		addFirst(w);
	}
	else {
		while (tmp != NULL && tmp->word < w)  {
			tmp = tmp->next;
		}
		if ((tmp!= NULL) && (tmp->word == w)) {
			tmp->count++;
		}
		else {
			Node *tmp2 = new Node(w);
			if (tmp != NULL) {
				if (tmp->prev != NULL) {
					tmp->prev->next = tmp2;
					tmp2->prev = tmp->prev;
				}
				else {
					first = tmp2;
				}
				tmp2->next = tmp;
				tmp->prev = tmp2;
			}
			else {
				last->next = tmp2;
				tmp2->prev = last;
				last = tmp2;
			}
			size++;

		}
	}
}

// Write an insertion Sort on the linked list (not an array, 
// a linked list!
void LLSE::insertionSortLL() {
}

// Convert the linked list to an array of nodes and return that array
Node *LLSE::convertToArray() {
}

// For the quicksort - the partition
int LLSE::partition(int beg,int end) {
}


// your recursive quicksort
void LLSE::quickSort( int beg, int end) {
}

//Take the linked list and create a binary heap
Node *LLSE::makeHeap() {
}

//Sort the heap array using heapsort
void LLSE::heapSort() {
}

