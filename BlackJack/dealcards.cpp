#include <iostream>
#include <string>
#include<vector>
#include "Card.h"
#include "Deck.h"

using namespace std;

//Checks if array has an ace in it
bool hasAce( vector <Card> hAce){
	
	bool aceFlag=false; // No aces yet
	int handCount = hAce.size();
	
	for (int i = 0; i < handCount; i++){ // Checks hand for Ace's
		if(hAce[i].getValue()==1){
			aceFlag = true; // found ace 
			//cout<<"Ace Found"<<endl<<endl;
		}
	}
	return aceFlag;
}
//Counts card score
int countScore(vector<Card> hScore){
	/*return the value of card vector  */
	int score=0;
	int handCount = hScore.size();
	
	for (int i = 0; i < handCount; i++){
		score+=hScore[i].getValue(); // Adds score of hand together
	}
	
	if (hasAce(hScore) && score<12){  // Adds in 10 to the ace score as long as it doesnt bust player 
		score += 10;
	} 
	return score;
	
}



char headerPrint(){
	char userInput;
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout<<"$$$$           BlackJack           $$$$"<<endl;
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout<<"$$$$  Do you want to play? (y/n)  $$$$$"<<endl;
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cin>>userInput;
	
	while((userInput!='y' and userInput!='n') or cin.fail()) {
		// Clear error state
		cin.clear();
		
		
		// Ignore characters in stream until newline
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
      
		
		cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
		cout<<"$$$$         INVALD INPUT         $$$$$"<<endl;
		cout<<"$$$$  Do you want to play? (y/n)  $$$$$"<<endl;
		cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
		cin>>userInput;
	}
	
	return userInput;
}

int buyIn(){
	int value;
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout<<"$$$$ How much are you buying in?  $$$$$"<<endl;
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	
	cin>>value;	
	
	while(value <=0 or cin.fail()){
		cin.clear();
		// Ignore characters in stream until newline
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
      
		cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
		cout<<"$$$$         INVALD INPUT         $$$$$"<<endl;
		cout<<"$$$$ How much are you buying in?  $$$$$"<<endl;
		cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
		cin>>value;
	}
	
	return value;
	
}

int bet(int availMonies){
	int value;
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout<<"$$$$   How much are you betting?  $$$$$"<<endl;
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout<<"You have $"<<availMonies<<endl;
	
	cin>>value;
	
	while(value <0 or cin.fail()){
		cin.clear();
		// Ignore characters in stream until newline
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
      
		
		cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
		cout<<"$$$$         INVALD INPUT         $$$$$"<<endl;
		cout<<"$$$$  How much are you betting?   $$$$$"<<endl;
		cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
		cin>>value;
	}

	while(availMonies<value){
		cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
		cout<<"$$$$       NOT ENOUGH MONEY       $$$$$"<<endl;
		cout<<"$$$$   How much are you betting?  $$$$$"<<endl;
		cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
		cin>>value;
	}
	cout<<endl<<endl<<endl<<endl;
	return value;
	
}


int main() {

	Deck d1; // The deck to be drawn from
	vector <Card> playerHand; // Players hand
	vector <Card> dealerHand; // Players hand  

	int playerMoney;
	int playerBet;
	char userChar;
	int winningVal=0;
	int hSize; // Hand size for for loop 


	userChar = headerPrint();
	if (userChar=='y'){
		playerMoney = buyIn();
		d1.newDeck();  //Draws New Deck
	}
	
	
	while(userChar=='y' and playerMoney>0){ //Loop for new deals 
		winningVal=0;

		playerBet = bet(playerMoney);
		
		cout<<endl<<endl<<"Player bet $"<<playerBet<<endl;
		cout<< "Deck size:"<<d1.deckSize()<<endl; // Prints Deck Size 
		playerHand.push_back(d1.dealCard()); // Draws first card 
		playerHand.push_back(d1.dealCard()); // Draws second card
		dealerHand.push_back(d1.dealCard()); // Draws first card 
		dealerHand.push_back(d1.dealCard()); // Draws second card 
		
		cout<<endl<<"PLAYERS HAND"<<endl;
		
		hSize = playerHand.size(); 
		for (int i = 0; i< hSize;i++){ // loop to print entire hand 
			playerHand[i].printCard();
		}
		cout<<endl<<"DEALERS Shown HAND"<<endl;
		dealerHand[0].printCard();
	
		//Checks for Natual back jack
		if(countScore(playerHand)==21 or countScore(dealerHand)==21){
			winningVal=1;
		}else {
			cout<<endl<<"Do you want to Hit? (y/n)"<<endl;
			cin>>userChar;
			
			while((userChar!='y' and userChar !='n') or cin.fail()){
				cin.clear();
				// Ignore characters in stream until newline
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout<<"Invalid Input"<<endl;
				cout<<"Do you want to Hit? (y/n)"<<endl;
				cin>>userChar;
			}
			
			while(winningVal==0 and userChar=='y'){

				playerHand.push_back(d1.dealCard());
				cout<<endl<<"PLAYERS HAND"<<endl;
			
				hSize = playerHand.size(); 
				for (int i = 0; i< hSize;i++){ // loop to print entire hand 
					playerHand[i].printCard();
				}
				
				if (countScore(playerHand)>21){
					winningVal=2;// player Busted 
				} else{
					cout<<endl<<"Do you want to Hit? (y/n)"<<endl;
					cin>>userChar;
					while((userChar!='y' and userChar !='n') or cin.fail()){
					cin.clear();
					// Ignore characters in stream until newline
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout<<"Invalid Input"<<endl;
					cout<<"Do you want to Hit? (y/n)"<<endl;
					}

				}	
			}
		
			while(winningVal!=2){	//Dealer will draw if player hasn't busted
				if (countScore(dealerHand)<17){
					dealerHand.push_back(d1.dealCard());
				}else if (countScore(dealerHand)<22){
					winningVal=3;
					break;
				}else{
					winningVal=2;//Bust
				}
			}
		}
		
		cout<<endl<<endl<<"PLAYERS HAND"<<endl;

		hSize = playerHand.size(); 
		for (int i = 0; i< hSize;i++){ // loop to print entire hand 
			playerHand[i].printCard();
		}
		cout<<endl<<endl<<"DEALERS HAND"<<endl;

		hSize = dealerHand.size(); 
		for (int i = 0; i< hSize;i++){ // loop to print entire hand 
			dealerHand[i].printCard();
		}
		
		
		cout<<endl<<endl;
		switch(winningVal){
			case 1: // Natual Black Jack
				if (countScore(dealerHand)==countScore(playerHand)){
					cout<<"TIE!!! No one Wins!!!"<<endl;
				}else if(countScore(dealerHand)>countScore(playerHand)){
					cout<<"BLACK JACK!!! DEALER WINS!!!"<<endl;
					playerMoney -=playerBet;
				}else{
					cout<<"BLACK JACK!!! PLAYER WINS!!!"<<endl;
					playerMoney +=(playerBet*1.5);
				}
			break;
			
			case 2: // Bust
				if(countScore(playerHand)>21){
					cout<<"PLAYER BUSTS!!! DEALER WINS!!!"<<endl;
					playerMoney -=playerBet;
				}else{
					cout<<"DEALER BUSTS!!! PLAYER WINS!!!"<<endl;
					playerMoney +=playerBet;
				}
			break;
			
			case 3: // No Busts 
				if (countScore(dealerHand)==countScore(playerHand)){
					cout<<"TIE!!! No one Wins!!!"<<endl;
				}else if(countScore(dealerHand)>countScore(playerHand)){
					cout<<"DEALER WINS!!!"<<endl;
					playerMoney -=playerBet;
				}else{
					cout<<"PLAYER WINS!!!"<<endl;
					playerMoney +=playerBet;
				}
			break;
		}
		dealerHand.clear();
		playerHand.clear();
		
		if(d1.deckSize()<20){	
			d1.newDeck();  //Draws New Deck
		}
	userChar = headerPrint();
		
		
	}
		
		
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout<<"$$$$          BYE FELICIA         $$$$$"<<endl;
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	return 0;
	
}