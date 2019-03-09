
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

 
#include "Deck.h"
#include "Card.h"

using namespace std;

	//Clears and makes a deck not suffled 
void Deck::newDeck(){
	string cNames[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen","King"};
	string cSuit[] = {"Hearts", "Dimonds", "Spades", "Clubs"};
	Card cTemp;
	
	this->userDeck.clear(); //Clears Deck 
	
	for(int i=0; i<4;i++){
		for(int j=0; j<13; j++){
			cTemp.setSuit(cSuit[i]); 	//Sets Suit
			cTemp.setName(cNames[j]); 	//Sets Name
			if (j>=10){
				cTemp.setValue(10);  //Sets value for jack queen and kinds with 10
			}else{
				cTemp.setValue(j+1); // sets all other cards values 
			}
			this->userDeck.push_back(cTemp); // adds card to end of vector 
		}
	}
	
}
	//Returns deck size 
int Deck::deckSize(){
	return this->userDeck.size();
}

Card Deck::dealCard(){
	Card cTemp;
	int rVal;
	
	srand(time(NULL));	
	rVal= rand() % this->userDeck.size(); 	// creates a random value 0 to deck size 
	
	cTemp=this->userDeck[rVal];				// copys card from deck
	this->userDeck.erase(userDeck.begin()+rVal); 	//remove cards from deck 
	
	return cTemp;
}