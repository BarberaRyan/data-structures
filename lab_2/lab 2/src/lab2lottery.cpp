/*
 * lab2lottery.cpp
 *
 *  Created on: Sep 25, 2016
 *      Author: Lenovo
 */
#include "lab2lottery.hpp"
#include <iostream>
#include<stdlib.h>
#include <time.h>

using namespace std;



Owner *makeOwner(){
	Owner* tempOwner = new Owner();
	srand(time(NULL));
	//Generates random number 1 to 10
	tempOwner->numStore = 1 + rand()%(10);
	//Initialize total sold here, run the loop, then assign it to the Owner object
	tempOwner->totalSold = 0;

	//Initialize total winner array to {0, 0, 0}
	int totalWinner[3] = {0, 0, 0};
	tempOwner->totalWinner = totalWinner;

	//Create an array of stores of the storeID
	Store* storeArr = new Store[tempOwner->numStore];

	//Create an array of store IDs
	int* storeIdArr = new int[tempOwner->numStore];


	//Calls makeStore as many times as needed
	for (int i = 0; tempOwner->numStore + 1 > i; i++){
		storeArr[i] = makeStore();
		tempOwner->totalSold += storeArr[i].numSold;
		storeIdArr[i] = storeArr[i].storeId;
	}

	tempOwner->storeArr = storeArr;
	tempOwner->store = storeIdArr;


return tempOwner;
}

Store makeStore(){
	//Create a store object on the stack to be edited
	Store tempStore;

	//Assign storeId and number of customers
	tempStore.storeId = 1 + rand()%(100);
	tempStore.numCust = 1 + rand()%(10);

	//Create array of customer objects
	Customer* custArr = new Customer[tempStore.numCust];

	//Create an array of customer IDs to be returned
	int* custIdArr = new int[tempStore.numCust];


	//Initially set numSold to 0, then alter it in the for loop
	tempStore.numSold = 0;

	//Calls makeStore as many times as needed
	for (int i = 0; tempStore.numCust + 1 > i; i++){
		custArr[i] = makeCustomer();
		tempStore.numSold += custArr[i].ticketNum;
		custIdArr[i] = custArr[i].customerId;
	}

	tempStore.customerList = custIdArr;

return tempStore;
}

Customer makeCustomer(){
	Customer tempCust;
	tempCust.customerId = 1 + rand()%1000;
	tempCust.ticketNum = 1 + rand()%20;

	//Create temporary 2d Array for use to be the 2d array for the customer
	int **lotNumTemp = NULL;
	lotNumTemp = new int*[tempCust.ticketNum];
	for (int i = 0; tempCust.ticketNum + 1 > i; i++){
			lotNumTemp[i] = new int[3];
		}

	//Assign values, do while loop checks if the assigned lotto number is the same as a previous digit, and generates the new number if a repeat is generated
	for (int i = 0; tempCust.ticketNum + 1 > i; i++){
		lotNumTemp[i][0] = rand()%10;
		do{
		lotNumTemp[i][1] = rand()%10;
		}while (lotNumTemp[i][1] == lotNumTemp[i][0]);

		do{
		lotNumTemp[i][2] = rand()%10;
		}while (lotNumTemp[i][2] == lotNumTemp[i][0] || lotNumTemp[i][2] == lotNumTemp[i][1]);

	}

	tempCust.lotteryNums = lotNumTemp;

	return tempCust;
}

void getWinners(int winners[]){
	//assigns the three winners to the winners array
	winners[0] = rand()%10;
		do{
		winners[1] = rand()%10;
		}while (winners[1] == winners[0]);

		do{
		winners[2] = rand()%10;
		}while (winners[2] == winners[0] || winners[2] == winners[1]);

return;
}


void findWinners(Owner *owner, int *ls){
	//first print store
	//Then customer and ID
	//Then any winning tickets, if the ticket returns a score of greater than zero
	cout << "Total lottery tickets sold: " << owner->totalSold << endl;
	cout << "Winning numbers: " << ls << endl;


	//Runs through for every store that the owner has
	for (int i = 0; owner->numStore > i; i++){
		cout << "Store: " << owner->store[i] << endl;
		Store tempStore = owner->storeArr[i];

		//Runs through for every customer that bought tickets at the given store
		for (int j = 0; tempStore.numCust > j; j++){
			cout << "\t" << "Customer: " << tempStore.customerList[j] << endl;
			Customer tempCust = tempStore.custArr[j];

			//Runs through every ticket that given customer has bought
			//If there is a match, print the ticket, it's value, and how many matched
			for (int k = 0; tempCust.ticketNum > k; k++){

				//if there is a match checkwin returns a value greater than 0 and a value is printed
				//Also edits value of total winner array for owner object
				cout << " working " <<endl;
				if (checkwin(tempCust.lotteryNums[k], ls) > 0){
					cout << " working " <<endl;
					cout << "\t" << "\t" << "Ticket: " << "\t" << tempCust.ticketNum << " matched     "<< checkwin(tempCust.lotteryNums[k], ls) << endl;
					owner->totalWinner[checkwin(tempCust.lotteryNums[k], ls)]++;
				}


			}
		//Print info at end for a given store
			cout << "\t" << "Total count for store " << owner->store[i] <<" : " << tempStore.numWinners[0] << " " << tempStore.numWinners[1] << " " << tempStore.numWinners[2] << endl;
		}
	}

return;
}

int checkwin(int *nums, int *winners){
	//score is the number of matches, the more matches the higher it will be, up to 3
	//ORDER DOESN'T MATTER, FIX IT

	int score = 0;
	for (int i = 0; 3 > i; i++){
		for (int j = 0; 3 > j; j++){
			if (nums[i] == winners[j]){
			score++;
			}
		}
	}
return score;
}
