/*
 * main.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: Lenovo
 */
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "MyGame.hpp"
using namespace std;

int main() {
	srand (time(NULL));

	Game MyGame;
	MyGame.startGame();
	return 0;
}



