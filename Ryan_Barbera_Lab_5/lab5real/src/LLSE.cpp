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
	wordarr = NULL;
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
	cout << "The first word is:" << first->word << endl;
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
	Node* tmp1 = first;//The node being compared to the new element, when sorted will be smaller and marks the "sorted" part of the list
	Node* tmp2 = first->next;//The new element, marks where new eblements are fend into the sorted part
	while (tmp2 != NULL){
		if (tmp2->count > tmp1->count){
			swap (tmp1, tmp2);//swaps data of tmp1 and tmp2
			while (tmp1->prev != NULL){//After a swap, checks if it is in order in the sorted part of the list,  if a swap doesn't occur, then the loop BREAKS
				if (tmp1->count > tmp1->prev->count){//if a swap is needed
					swap (tmp1, tmp1->prev);
					tmp1 = tmp1->prev;//make tmp1 the node that just got shifted down
				}
				else{//If no swap occured
					break;//Break the loop
				}
			}
			if (tmp1->prev == NULL){
				first = tmp1;
			}
		}
		//Shift node 1 to node 2, and now all nodes to the left are sorted in reference to one another
		//Advance tmp2 forward one and make that sorted in reference to everything else
		tmp1 = tmp2;
		tmp2 = tmp1->next;
	}
	cout << "Insertion Sort: " << endl;
	printLL();

}

// Convert the linked list to an array of nodes and return that array
Node **LLSE::convertToArray() {

	Node ** wordarr = new Node*[size];//wordarr is now the size of the list

	Node* tmp = first;//Start tmp at the first node in the linked list
	for (int i = 0; size > i; i++){
		wordarr[i] = tmp;//tmp is added at the i position of the array
		tmp = tmp->next;//Progress the tmp to the next node
	}
	return &wordarr[0];//Return the created array
}

// For the quicksort - the partition
int LLSE::partition(int beg,int end) {
	//TODO COMMENT
	//Credit to class notes
	int x = beg;
	int y = end;
	Node* tmp;
	Node* pivot = wordarr[x++];// The pivot is the first element after x
	while (x<=y){//
		while (wordarr[x]->count < pivot->count){//Compare the values of the count in the nodes
			x++;//this declares how many elements are less than the pivot
		}
		while (wordarr[y]->count > pivot->count){//Compare the values of the count in the nodes
			y--;//this declares how many elements are more than the pivot
		}
		if(x<=y){//if cross over has occured, puts elements on either side of the pivot
			tmp = wordarr[x];
			wordarr[x++] = wordarr[y];
			wordarr[y--] = tmp;
		}
	}
	//This plaeces the pivot at the position in bettween the x and y indexes foudn
	//The pivot is now in place on the array
	wordarr[beg] = wordarr[y];
	wordarr[y] = pivot;
	return y; //The int index of the pivot is returned by the funciton
}


// your recursive quicksort
void LLSE::quickSort( int beg, int end) {
	int middle = partition(beg, end);
	//This will return the pivot of the quicksort
	if (middle-1 > beg){//Takes the values before the pivot and places them in order
		quickSort(beg,middle-1);
	}
	if(middle+1 < end){//Takes the values after the pivot and places them in order
		quickSort(middle+1, end);
	}
}


void LLSE::makeHeap() {
	wordarr = convertToArray();
	int parent = (size - 2) / 2;//start with rightmost node that has children
	int tmp;
	Node * swapnode;//a temp variable used to swap nodes
	do{
		tmp = (parent + 1) *2;
		if (size > tmp){
			if (tmp == size - 1){//prevent the array from going out of bounds, tells the function it will only have one child
				if (wordarr[tmp]->count > wordarr[parent]->count){//If the child is greater than the parent
					swapnode = wordarr[parent];//swaps the parent with the child
					wordarr[parent] = wordarr[tmp];
					wordarr[tmp] = swapnode;
					percolatedown(tmp, size);//continues to percolate
				}
			}
			else{
				tmp = (wordarr[tmp]->count > wordarr[tmp -1 ]->count) ? tmp : tmp - 1;//Takes the bigger child to compare

				if (wordarr[tmp]->count > wordarr[parent]->count){//If the child is greater than the parent
					swapnode = wordarr[parent];//Swapst he parent with child
					wordarr[parent] = wordarr[tmp];
					wordarr[tmp] = swapnode;
					percolatedown(tmp, size);//continues to percolate
				}
			}
		}
	parent--;//progress the loop
	}while (parent >= 0);
	cout << "Heap Sort: " << endl;

	printarr();
}

void LLSE::percolatedown(int index, int arrsize){
	int tmp = (index + 1) * 2;//It's ugly to write out everytime
	Node * swapnode;
	if (arrsize > tmp){//Loop allows for left children
		if (arrsize == tmp - 1){//Check for right child existing, if this condition is true there is no right child, only left
			if (wordarr[tmp]->count > wordarr[index]->count){//If the child is greater than the parent
					swapnode = wordarr[index];
					wordarr[index] = wordarr[tmp];
					wordarr[tmp] = swapnode;
					percolatedown(tmp, arrsize);
			}
		}
		else{
			tmp = (wordarr[tmp]->count > wordarr[tmp -1]->count) ? tmp : tmp - 1;//Takes the bigger child to compare
			if (wordarr[tmp]->count > wordarr[index]->count){//If the child is greater than the parent
					swapnode = wordarr[index];
					wordarr[index] = wordarr[tmp];
					wordarr[tmp] = swapnode;
					percolatedown(tmp, arrsize);
				}
			}
	}
}

//Sort the heap array using heapsort
void LLSE::heapSort() {
	makeHeap();//Makes a heap
	Node * swapnode;//Swap node needed for swapping elements of the array
	int endpoint = size - 1;//endpoint starts
	while (endpoint >= 0){//Runs through the entire heap, attempting to percolate the element on top, which may or may not occur
		//Whatever the result of percolation, it'll take the top element of the heap and swap it with what is at the endpoint of the list
		percolatedown(0,endpoint);
		swapnode = wordarr[endpoint];
		wordarr[endpoint] = wordarr[0];
		wordarr[0] = swapnode;
		endpoint--;
	}//sorts from low to high, list can be reversed from here if high to low is wanted
	printarr();
}

void LLSE::printarr(){//Simple function to print an array
	cout << "Printing array" << endl;
	for (int i = 0; size > i; i++){
		cout << wordarr[i]->count <<" : "<<wordarr[i]->word << endl;
	}

}

void LLSE::swap(Node* node1, Node* node2){//swaps data of nodes
	int tmpcount = node1->count;
	string tmpword = node1->word;
	node1->count = node2->count;
	node1->word = node2->word;
	node2->count = tmpcount;
	node2->word = tmpword;
	//Nodes are now altered
}


