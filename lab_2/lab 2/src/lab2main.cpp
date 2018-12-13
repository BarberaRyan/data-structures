#include <time.h>
#include <stdlib.h>
#include "lab2lottery.hpp"
#include <iostream>
#include<stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;


int main() {
	std::setvbuf(stdout, NULL, _IONBF, 0);
	srand(time(NULL));
	Owner *me= makeOwner();
	int winners[3] = {0,0,0};
	getWinners (winners);
	for (int i = 0; i < 3; i++) {
		cout << winners[i] << endl;
	}
	findWinners(me, winners);
	cout << "won with 1 number: "<< me->totalWinner[0] << endl;
	cout << "won with 2 numbers: " << me->totalWinner[1] << endl;
	cout << "won with 3 numbers: " << me->totalWinner[2] << endl;
	//cout << x << endl;
	return 0;
} //main
