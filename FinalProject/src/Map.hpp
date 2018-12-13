/*
 * Map.hpp
 *
 *  Created on: Nov 30, 2016
 *      Author: Lenovo
 */

#ifndef MAP_HPP_
#define MAP_HPP_
#include "Node.hpp"
#include "User.hpp"

class Map {
	User* user;
	string filename;
	User** Usermap;
	Card** Cardmap;


public:
	Map();
	Map(string file);//Lets you create something to add the the text file, which is then mapped
	void add(Node s);//Adds a given node to the map

	void cardMap();

	void userMap();
	User* userSearch(string search);
	Card* cardSearch(string search);

	Node* search(string type, string search);//Looks for a given node in the hashmap

	void writeFile(string file);//Lets you create a node to add the the text file, which is then mapped
	//Adds it to the correct point in the text file

	void printAllNodes();//Prints the names of every nodes in the data map

	Card cardConvert(Card* card);
};






#endif /* MAP_HPP_ */
