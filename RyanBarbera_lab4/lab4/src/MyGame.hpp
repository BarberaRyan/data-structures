/*
 * MyGame.hpp
 *
 *  Created on: Oct 26, 2016
 *      Author: Lenovo
 */

#ifndef MYGAME_HPP_
#define MYGAME_HPP_
#include "BSTB.hpp"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

class Game {
	BSTB *dict;  // the AVL tree
	int numletters;  // the number of letters the user wants
	string currletters;  //the random set of letters
	int currlettersLength;
	int totalwords;  // the count of the total number of words generated
	BSTB *wordlist;  //The Binary Search tree for the word list – used because you //want to make sure there are no duplicates in the word list typed in
	int numright;  // the count of the number of words in the dict tree
public:
      /*constructor, initializes AVL tree from “dict.txt” by calling ReadTreeFromFile
	*/
	Game();
	/* constructor, initializes AVL tree by calling ReadTreeFromFile with infile
	*/

	Game(string infile);

/* startGame(): this is the user interface part – it asks how many letters the user wants, reads that number in, prints out the set of random letters (including at least one vowel, and then tells the user to start typing in words.  Each word typed in is added to the wordlist (the linked list).  When the user enters -1,(see note at bottom about a timer) the function then calculates the user’s total score by calling a function that first checks to make sure that each word only includes letters in the set of random letters and then checks to see if each word in the list is in the AVL tree.  It then prints out the list of valid words and the user’s score.  This function loops until the user no longer wants to play again.
*/
	void startGame();

	void readTreeFromFile (string dictfile); /* see below for this method*/

/* getLetters(): this method (called by the startGame method) gets a set of x random letters
and returns it.
	*/
	void getLetters(int x);

/* getWords():this method (called by the startGame method) loops while the user enters potential words.  Each word gets added to the wordlist tree.
*/
	void getWords();

/* checkWLetters(): checks to see if s only contains letters in currletters (the random set of letters) and returns true if s only contains valid letters, false otherwise
*/
	bool checkWLetters(string s);

/* checkWordsForScore(): gets the count of the number of words typed in that are in the dictionary, and then calculates the total score
*/
void checkWordsForScore(NodeTB *n);
};




#endif /* MYGAME_HPP_ */
