/*
 * PlayGame.cpp
 *
 *  Created on: Dec 11, 2016
 *      Author: Lenovo
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Card.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "PlayGame.hpp"
using namespace std;


PlayGame::PlayGame(){
	PlayerA = Player();
	PlayerB = Player("Mook");
	Library = Map();
}

PlayGame::PlayGame(Deck deck){
	srand (time(NULL));
	bool activeGame = true;
	bool playerInput;//Used for the loop where the player can type things in
	Card playerAction;//The player's prepared action
	Card monsterAction;//THe mook's prepared action
	string input;//Gonna be a good bit of typing

	//If action is to be taken, these are set to true
	bool playerWillAct = false;
	bool monsWillAct = false;

	//Set up players
	PlayerA = Player(deck);
	PlayerB = Player("Mook");
	Library = Map();

	//Set up the players hand by parsing their deck
	Card* cardsA = NULL;//Set up the player's hand
	cardsA = new Card[7];
	PlayerA.hand = cardsA;
	int i = 0;
	string tmp;

	//Used to parse a string by spaces
	stringstream ssin(deck.deckString);
	while (ssin.good() && i < 7){//Note, first index is the deck's name
		ssin >> tmp;
		PlayerA.hand[0] = Library.cardConvert(Library.cardSearch(tmp));//Note that otherwise, index 0 would be null
		PlayerA.hand[i] = Library.cardConvert(Library.cardSearch(tmp));
		i++;
	}



	Card* cardsB = NULL;//Set up the Mook's hand
	cardsB = new Card[6];
	PlayerB.hand = cardsB;
	PlayerB.hand[0] =  Library.cardConvert(Library.cardSearch("ATTACK"));
	PlayerB.hand[1] =  Library.cardConvert(Library.cardSearch("MASK"));
	PlayerB.hand[2] =  Library.cardConvert(Library.cardSearch("SCAN"));
	PlayerB.hand[3] =  Library.cardConvert(Library.cardSearch("SHIELD"));
	PlayerB.hand[4] =  Library.cardConvert(Library.cardSearch("OVERFLOW"));
	PlayerB.hand[5] =  Library.cardConvert(Library.cardSearch("PSIBOOST"));



	while (activeGame){
		if ((1 > PlayerA.health) || (1> PlayerB.health)){
			if (1 > PlayerA.health){
				cout << "You have been defeated!" << endl;
			}
			else{
				cout << "You are victorious!"<< endl;
			}
			activeGame = false;
			break;
		}
		statusPrint();
		playerInput = true;
		while (playerInput){
			cout << "Choose your course of action!"<< endl;
			cout << "Type 'HELP' for descriptions of all moves"<<endl;
			cout << "Type 'PASS' to pass your turn"<<endl;
			cout << "Or type the NAME of one of your cards to use it, if you have the PSI" << endl;
			cin >> input;
			if (input == "HELP"){
				deckPrint();
			}
			if (input == "PASS"){
				playerInput = false;
			}
			else{
				int i = 1;
				while (7 > i){
					if (PlayerA.hand[i].name == input){
						if (PlayerA.psi >= PlayerA.hand[i].psiCost){
							playerAction = PlayerA.hand[i];
							playerWillAct = true;
							playerInput = false;
							break;
						}
						else{
							cout << "not enough PSI" << endl;
						}
					}
					i++;
				}
			}
		}//End of player input

		//This is all how the mook decides what to do, it looks at the situation on the field and picks the best move to use
		//It never uses PSIBOOST
		//This will later be it's own function, and all monsters will be able to have different AI
		if (PlayerB.psi >= 5){//If the mook can act
			monsWillAct = true;
			if (PlayerA.attack- 20 > PlayerB.defense){
				//Diferent attacks may get more difficult to predict, it may be needed to have a way to see how much damage will be done
				monsterAction = PlayerB.hand[1];//Reduce player's attack
			}

			else if (PlayerB.attack - 25 > PlayerA.defense){
				monsterAction = PlayerB.hand[0];//An attack
			}
			//If opponent's offense is low, but thier defense high reduce their defense
			else if (PlayerA.defense > 60 && PlayerA.attack > 20){
				monsterAction = PlayerB.hand[2];
			}

			//If opponent defense is already low, and opponent attack is not, do not lower defense move
			else if (20 > PlayerA.defense && PlayerA.attack > 20){
					int x = rand()%2;
					if (x == 0){
						monsterAction = PlayerB.hand[3];//increase defense
					}
					else{
						monsterAction = PlayerB.hand[1];//reduce opponent's attack
					}
				}

			//If opponent's attack and defense are low
			else if (20 > PlayerA.defense && 20 > PlayerA.attack ){
				int x = rand()%2;
				if (x== 0){
					monsterAction = PlayerB.hand[4];//Increase own attack
				}
				else{
					monsterAction = PlayerB.hand[3];
				}
			}

			//Do any move that isn't an attack
			else{
				int x = 1 + rand()%5;
				monsterAction = PlayerB.hand[x];
			}
		}


		if (playerWillAct){//if true, the player will act
			PlayerA.psi -= playerAction.psiCost;
			resolveEffect(playerAction, PlayerA, PlayerB);
			playerWillAct = false;
		}
		if (0 >= PlayerB.health){
			cout << "The player is victorious!" << endl;
			break;
		}
		if(monsWillAct){//If true, the monster will act
			PlayerB.psi -= monsterAction.psiCost;
			resolveEffect(monsterAction, PlayerB, PlayerA);
			monsWillAct = false;
		}
		//Get a point of PSI every round
		PlayerA.psi ++;
		PlayerB.psi ++;

	}
}


void PlayGame::resolveEffect(Card card, Player caster, Player target){//Takes a card, and parses out the effects on it to make something happen
	Effect* tmpEffect = card.cardEffects;
	while (tmpEffect != NULL){//Keep going until the card has no effects remaining
		//Parse the effect string
		string* resolveEffect = NULL;
			resolveEffect = new string[4];
			int i = 0;
			string tmp;

			//Used to parse a string by spaces
			stringstream ssin(tmpEffect->effectStr);
			while (ssin.good() && i < 4){//Note, first index is the deck's name
				ssin >> tmp;
				resolveEffect[i] = tmp;
				i++;
			}

			if (resolveEffect[0] == "NORMAL"){//The category of math to be done, this could allow for a lot of different categories of cards, like poison damage (reoccuring) or piercing (it ignores armor) and so on
				int effect = atoi(resolveEffect[3].c_str());
				if (resolveEffect[3] == "ATTACK"){
					int damage = caster.attack - target.defense;
					if (damage > 0){//Damage must be greater than zero to take effect
						target.health -= damage;//Reduce target's health by damage done
					}
				}


				else{
					if (resolveEffect[2] == "SELF"){//The move affects the self
						if (resolveEffect[1] == "OFFENSE"){
							caster.attack+=effect;
							if (0 > caster.attack){
								caster.attack = 0;
							}
						}
						if (resolveEffect[1] == "DEFENSE"){
							caster.defense+=effect;
							if (0 > caster.defense){
								caster.defense = 0;
							}
						}
						if (resolveEffect[1] == "PSI"){
							caster.psi+=effect;
						}
					}
					if (resolveEffect[2] == "OPPONENT"){//The move affects the self
						if (resolveEffect[1] == "OFFENSE"){
							target.attack+=effect;
						if (0 > caster.attack){
							caster.attack = 0;
						}
							}
						if (resolveEffect[1] == "DEFENSE"){
							target.defense+=effect;
							if (0 > caster.defense){
								caster.defense = 0;
							}
						}
						if (resolveEffect[1] == "PSI"){
							target.psi+=effect;
							}
						}

				}

			}

	}
}

void PlayGame::statusPrint(){//Prints out the current status of the battle
	Player tmpPlayer = PlayerA;
	bool toPrint = true;
	bool first = true;
	while (toPrint){
		cout << "The " << tmpPlayer.name << "is ready to fight!"<< endl << endl;;
		cout << "Health: "<<tmpPlayer.health <<endl;
		cout << "Attack: "<<tmpPlayer.attack <<endl;
		cout << "Defense: "<<tmpPlayer.defense <<endl;
		cout << "PSI: "<<tmpPlayer.psi <<endl << endl << endl;

		if (first){//Used to switch from playerA to playerB
			tmpPlayer = PlayerB;
			first = false;
		}
		else{
			toPrint = false;
		}
	}
}

void PlayGame::deckPrint(){//Prints all of the moves in one's deck
	cout << "You possess the following moves: " << endl << endl;
	int i = 1;//To print from index 1 to 6
	while (7 > i){
		cout << "Move: " << PlayerA.hand[i].name << endl;
		cout <<  PlayerA.hand[i].description << endl << endl;
	}
}


