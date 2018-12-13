/*
 * MyGame.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: Lenovo
 */

/*
 * MyGame.hpp
 *
 *  Created on: Oct 26, 2016
 *      Author: Lenovo
 */


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>

#include "MyGame.hpp"
#include "NodeTB.hpp"
using namespace std;


      /*constructor, initializes AVL tree from “dict.txt” by calling ReadTreeFromFile
	*/
Game::Game(){
	cout<<"Start making game" <<endl;
	dict = NULL;
	numletters = 0;
	currletters = "";
	currlettersLength = 0;
	totalwords = 0;
	wordlist = NULL;
	numright = 0;
	readTreeFromFile ("dict.txt");//Reads the tree
	}
	/* constructor, initializes AVL tree by calling ReadTreeFromFile with infile
	*/

Game::Game(string infile){
	dict = NULL;
	readTreeFromFile (infile);//Reads the tree
	numletters = 0;
	currletters = "";
	currlettersLength = 0;
	totalwords = 0;
	wordlist = NULL;
	numright = 0;

	}

/* startGame(): this is the user interface part – it asks how many letters the user wants, reads that number in, prints out the set of random letters (including at least one vowel, and then tells the user to start typing in words.  Each word typed in is added to the wordlist (the linked list).  When the user enters -1,(see note at bottom about a timer) the function then calculates the user’s total score by calling a function that first checks to make sure that each word only includes letters in the set of random letters and then checks to see if each word in the list is in the AVL tree.  It then prints out the list of valid words and the user’s score.  This function loops until the user no longer wants to play again.
*/
void Game::startGame(){
	readTreeFromFile ("testdict.txt");
	int x;
	cout <<endl<< "How many letters do you want to use this game?" << endl;
	cin >> x ;
	getLetters(x);
	string i;
	wordlist = new BSTB();
		while (i != "-1"){
			cout << "Please enter a string corresponding to a word from the following letters: " << endl;

			cout << currletters << endl;

			cout << "Or enter -1 to end and score" << endl;
			cin >> i;
			if (i != "-1"){
				if(checkWLetters(i)){//if checkWLetters is allowed
					if (wordlist->root != NULL){//if wordlist exists
						wordlist->insert(i,wordlist->getRoot());
					}
					else{
						wordlist->insert(i);//if wordlist doesn't exist make it
					}
				}
				else{
					cout << "Invalid word input" << endl;
				}
			}
		}
		cout << "All words input, Scoring..." << endl;
		checkWordsForScore(wordlist->getRoot());
		cout << "You scored: "<< numright << " points" << endl;


}

void Game::readTreeFromFile (string dictfile){ /* see below for this method*/
	ifstream infile;
	//TODO create tree with top part of infile
	infile.open("dict.txt");//infile declared as the given .txt
	string k;
	if (infile.good())
	  {//Add first node
		dict = new BSTB();//Initilize dict as BSTB
		//dict = newdict;//Initilize dict as a BSTB
	    string s;//First string in txt file
	    getline(infile, s);
	    dict->insert(s);//Add the first node
	  }
	while (getline(infile,k)){//Loop to get strings line by line from the txt file
		dict->insert(k ,dict->root);
	}
	infile.close();
}
/* getLetters(): this method (called by the startGame method) gets a set of x random letters
and returns it.
	*/
void Game::getLetters(int x){
	//Creates a string of characters for the game based onthe input
	string alphabet[26] = { "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z" };
	string vowels[5] = {"a","e","i","o","u"};
	//TODO Add at least 1 vowel


	currletters += vowels[rand()%5];//Adds at least one vowel to currletters

	for (int i =0; x-1 > i; i++){
		currletters += alphabet[rand()%26];//Alphabet[number from 0 to 25] is assigned to letterArr
	}
	return;
}

/* getWords():this method (called by the startGame method) loops while the user enters potential words.  Each word gets added to the wordlist tree.
*/
void Game::getWords(){
	/*
	string i;
	while (i != "-1"){
		cout << "Please enter a string corresponding to a word from the following letters: " << endl;
		for (int j = 0; currletters.length() > j; j++){
			cout << currletters.at(j) + ", ";
		}
		cout << endl;
		cout << "Please enter a string corresponding to a word from the following letters: " << endl;
		cout << "Or enter -1 to end and score" << endl;
		cin >> i;
		if (i != "-1"){
			if(checkWLetters(i)){//if checkWLetters is allowed
				wordlist->insert(i,wordlist->getRoot());
			}
			else{
				cout << "Invalid word input" << endl;
			}
		}
	}
	cout << "All words input, Scoring..." << endl;
	*/
}

/* checkWLetters(): checks to see if s only contains letters in currletters (the random set of letters) and returns true if s only contains valid letters, false otherwise
*/
bool Game::checkWLetters(string s){
	//TODO do something instead of curr letters deleting it from the array
	//SOLUTION turn currletters into a string, then push the characters to the end
	//And do not seek out the letters at the end of the string
	int end = currletters.length();
	while(s != ""){//Loop goes until the s string is gone
		for (int j = 0; end + 1 > j; j++){//For loop goes for one past the length of the currletters array
			if(j == end){//if the currletter array fails to find a character matching
				return false;//Then the letter was not found in curr letters or it was used too many times
			}
			if(currletters.at(j) == s.at(0)){//if the currletter array has a character the same as the first letter in s
				//TODO May go out of bounds here
				currletters.push_back(currletters.at(j));//Add the tested letter to the end of the string
				currletters.erase(j,1);//Remove the old letter from the string
				end--;//Reduce end by one to make sure it does not reach characters it has already compared
				break;
			}

		}
		s.erase(0,1);//Removes the first letter of the s  string
	}
	return true;
}

/* checkWordsForScore(): gets the count of the number of words typed in that are in the dictionary, and then calculates the total score
*/
void Game::checkWordsForScore(NodeTB *n){//Recursive call through wordlist?
	 // again, nice if you choose recursion
		//go down tree all the way left, then go up
		if (n->getLeft() != NULL){
			checkWordsForScore(n->getLeft());//Go left first
		}
		if(dict->search(dict->getRoot(), n->getData())){
			numright++;
		}//See if word at node is in the dict tree, if it is add a point
		if (n->getRight() != NULL){
			checkWordsForScore(n->getRight());//Then go right
		}
}
