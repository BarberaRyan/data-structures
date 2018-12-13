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
	cout << "hi" << endl;
	Document doc("Monet.txt");
	doc.readFile();
	doc.pickSort(0);
	return 0;
}



