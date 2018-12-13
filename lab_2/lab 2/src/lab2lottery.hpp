/*
 * lab2lottery.hpp
 *
 *  Created on: Sep 25, 2016
 *      Author: Lenovo
 */

#ifndef LAB2LOTTERY_HPP_
#define LAB2LOTTERY_HPP_


struct Customer {
	//ID of customer
	int customerId;

	//Number of tickets bought
	int ticketNum;

	//Use ** for 2d array
	int** lotteryNums;

};

struct Store{
	//ID of store
	int storeId;

	//Number customers getting tickets
	int numCust;

	//Points to a list of the Id of the customer
	int* customerList;

	//Number of tickets sold
	int numSold;

	//Number of 1, 2 and 3 winners
	int* numWinners;

	//EXTRA THING: An array of customer objects
	Customer* custArr;
};

struct Owner{
	//Points to list of store ids owned by given owner
	int* store;
	//number of stores owned by owner
	int numStore;
	//total sold at all stores
	int totalSold;
	//array of three ints, first being number of tickets with 1 correct second number with 2, third number with three
	int* totalWinner;

	//EXTRA THING: An array of store objects
	Store* storeArr;

};

//The function declaratoins
Owner *makeOwner();
Store makeStore();
Customer makeCustomer();
void getWinners (int winners[]);
void findWinners(Owner *owner, int *ls);
int checkwin(int *nums, int *winners);


#endif /* LAB2LOTTERY_HPP_ */
