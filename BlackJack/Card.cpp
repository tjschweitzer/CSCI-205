#include <bits/stdc++.h> 
#include "Card.h"


	// Sets card name "Ace - King"
void Card::setName(string cardName){
	this->name=cardName;
	
}
	// Sets Suit "Dimonds - Spades"
void Card::setSuit(string cardSuit){
	this->suit=cardSuit;
	
}
	// Sets value of card 1-10
void Card::setValue(int cardValue){
	this->value = cardValue;
	
}
	//Returns card name
string Card::getName(){
	return this->name;
	
}
	//Returns card suit
string Card::getSuit(){
	return this->suit;
	
}
	//Returns card Value
int Card::getValue(){
	return this->value;
}
	//{rints name and suit
void Card::printCard(){
	cout<< this->name << " of " << this->suit << endl;
}
	//initalizes card with no name suit of value
Card::Card(){
	this->name="None";
	this->suit="No Suit";
	this->value=0;
}
	// Sets card with name value and suit 
Card::Card(string cardName, string cardSuit, int cardValue){
	this->name=cardName;
	this->suit=cardSuit;
	this->value=cardValue;
}