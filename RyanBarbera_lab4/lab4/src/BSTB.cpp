/*
 * BSTB.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: Lenovo
 */




#include <iostream>
#include <stdio.h>
#include <fstream>
#include "NodeTB.hpp"
#include "BSTB.hpp"
using namespace std;



BSTB::BSTB(){
	root = NULL;
	count = 0;
	}// constructor – sets root to NULL
BSTB::~BSTB(){
	}// destructor – deletes tree

NodeTB * BSTB::getRoot(){//Gets the root
	return root;
}

bool BSTB::insert(string x){//Used if root is currently non existant
	 root = new NodeTB(x);
	//Count++ produces error
	count++;
	return true;
}

	/* recursively inserts x into the tree with the current root (possibly of a
	subtree) being n */


bool BSTB::insert(string x, NodeTB *n){
	/* Note the overloading of methods – this is nice if you choose to write this method recursively.  If a string is already in the tree, you may want to print out a warning, but otherwise it can just be ignored. */
	/* Note: you can choose to not write this recursively, but it’s just so nice recursively */
	//TODO after an insert, be sure to check if the tree is balanced
	if (n->balanceFactor > 2){
		return false;
	}

	if (n->data > x){// if n is greater than x
		if (n->right != NULL){//If right node is taken
			return insert(x, n->right);//Go down right side
		}
		else{
			n->right = new NodeTB(x);
			n->right->up = n;
			count++;
			adjustBalances(n);//Calls roations when needed
			return true;
		}
	}
	if(n->data < x){
		if (n->left != NULL){//if there is a node on the left side of the tested node
			return insert(x, n->left);//Recall the function starting at the node
			}
		else{
			n->left = new NodeTB(x);
			n->left->up = n;//Abandoned up node, they still exist
			count++;
			adjustBalances(n);
			return true;
		}
	}
	else{//Case of a match
		return false;
	}

}
void BSTB::adjustHeight(NodeTB *n){//Used if a node is added on the lowest part of a tree
	int tmpL = 0;//Left side temp
	int tmpR = 0;//RIght side temp
	if (n == NULL){
		return;
	}

	if (n->left != NULL){
		tmpL = 0;
	}

	if (n->right != NULL){
			tmpR = n->right->height;
		}
	if (tmpL > tmpR?tmpR:tmpL){
		n->height++;
	}


	n->balanceFactor = (tmpL - tmpR);

}

void BSTB::adjustBalances(NodeTB *n){ // Calls rotation when needed
	adjustHeight(n);
	if (n->balanceFactor != 2 && n->balanceFactor != -2){//If balance factor is within 1 to -1 it is balanced
		if (root == n){ //if the root has been reached
			return;//End the function
		}
		else{
			return adjustBalances(n->up);//Otherwise go up one and test that node
		}
	}

	if (n->balanceFactor == 2){//If balance factor is too big negatively it must be rotated with LL or LR
		// "right rotation attempting"
		if (n->left != NULL){//if left node exists
			if (n->left->balanceFactor == -1){//Turn it into a RL rotation if needed
				//cout << "RL rotation" << endl;
				rotateLeft(n->left);
			}
		}
		NodeTB * tmp = rotateRight(n);//Rotate right
		if (tmp-> up != NULL){//if tmp is not the root
			tmp->up->right = tmp;
		}
		adjustBalances(tmp);
	}
	else{//Left rotation
		if (n->right != NULL){//if a right node exists
			if (n->right->balanceFactor == 1){//turn it into a RL rotaiton if needed
				rotateRight(n->right);
			}
		}
		NodeTB * tmp = rotateLeft(n);//Rotate right
		if (tmp-> up != NULL){//if tmp is not the root
			tmp->up->left = tmp;//Up points where it should
		}
		adjustBalances(tmp);
	}
}

NodeTB * BSTB::rotateRight(NodeTB *n){
	/* for left rotation*/
	NodeTB* x = n->left;
	NodeTB* tmp = x->right;
	n->left = tmp->right;
	if (n->left != NULL){//If n left exists
		n->left->up = n;
	}
	//Perform rotation
	x->right = n;
	n->left = tmp;
	if (root->data == n->data){//If n was the root
		root = x;//tmp is now the root
	}
	x->up = n->up;//Redeclare up nodes
	n->up = x;//Redeclare up nodes
	adjustHeight(x);//COrrect heigths
	adjustHeight(n);
	return x; // Return the altered node
}

NodeTB * BSTB::rotateLeft(NodeTB *n){ /* for left rotation */
	NodeTB* x = n->right;
	NodeTB* tmp = x->left;
	n->right = tmp->left;
	/*
	if (n->right != NULL){//If n left exists
		n->right->up = n;
	}
	*/

	//Perform rotation
	x->left = n;
	n->right = tmp;
	if (root->data == n->data){//If n was the root
		root = x;//tmp is now the root
	}
	x->up = n->up;//Redeclare up nodes
	n->up = x;

	adjustHeight(x);//COrrect heigths
	adjustHeight(n);
	return x; // Return the altered node
}


void BSTB::printTreeio(NodeTB *n){ // again, nice if you choose recursion
	//go down tree all the way right, then go up
	if (n->right != NULL){
		printTreeio(n->right);//Call prtntTreeio for right nodes first
	}
	cout << " " << n->data << " -> ";//Print the current node
	if (n->left != NULL){
		printTreeio(n->left);//Now call printTreeio for left node
	}
}

/*
void BSTB::printTreePre(){ // for testing purposes, prints out tree in preorder
}
*/
void BSTB::printTreePre(NodeTB *n){  // for printing recursively
	cout << " " << n->data << " -> ";//Print the current node
	//go down tree all the way right
	if (n->right != NULL){
		printTreeio(n->right);//Call prtntTreeio for right nodes first
	}

	if (n->left != NULL){
		printTreeio(n->left);//Now call printTreeio for left node
	}
}
/*
void BSTB::printTreePost(){  // for testing purposes, prints out tree in postorder
}
*/
void BSTB::printTreePost(NodeTB *n){ // for printing recursively

	if (n->right != NULL){//go down tree all the way right
		printTreeio(n->right);//Call prtntTreeio for right nodes first
	}
	if (n->left != NULL){
		printTreeio(n->left);//Now call printTreeio for left node
	}
	cout << " " << n->data << " -> ";//Print the current node
}
/*
bool BSTB::search(string x){ // searches tree for x – retunns true if found, false otherwise
	return true;
}
*/

bool BSTB::search(NodeTB *n, string x){  //if recursive
	if(n == NULL){//if N is NULL
		return false;
	}
	if(n->data == x){//if N data is the correct answer
		return true;
	}

	if (n->data > x){// if N is more go right
		search(n->right, x);
	}
	else{//Else try left
		search(n->left, x);
	}
	return false;
}

int BSTB::getScore(NodeTB *n, BSTB *dict){ // counts words in dict and returns that
	//Wasn't actually used
	return 0;
}







