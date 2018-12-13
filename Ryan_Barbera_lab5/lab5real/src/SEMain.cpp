/*
 * SEMain.cpp
 *
 *  Created on: Nov 8, 2016
 *      Author: Debra
 */

#include "Document.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	Document doc("Monet.txt");
	doc.readFile();
	//Just change the pick sort to test a different sorting algorith
	//0 for insertion
	//1 for quick
	//2 for heap
	doc.pickSort(1);

	return 0;
}



