#include <bits/stdc++.h> 
using namespace std;
#include "Card.h"


#ifndef DECK_H
#define DECK_H

class Deck {
	public:
		void newDeck();
		int deckSize();
		Card dealCard();
	private:
		vector<Card> userDeck;
};

#endif