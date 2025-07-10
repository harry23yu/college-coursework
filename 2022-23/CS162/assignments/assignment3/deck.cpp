/******************************************************
** Program: deck.cpp
** Author: Harry Yu
** Date: 11/6/2022
** Description: The Deck class initializes 52 cards at the beginning of the game, then 
shuffles the deck. It also keeps track of how many cards are left in the deck. When a card 
is removed from the deck, it is always the top card.
** Input: None
** Output: None
******************************************************/

#include <iostream>
#include <string>
#include "card.h"
#include "deck.h"
using namespace std;

/*********************************************************************
** Function: Deck::Deck()
** Description: It initializes a deck of 52 cards, then suffles them.
** Parameters: None
** Pre-Conditions: The number of cards in the deck at the beginning of the game should 
be 52.
** Post-Conditions: The deck should be completely shuffled.
*********************************************************************/
Deck::Deck() { //default constructor
    this->n_cards = 52; //52 cards in the deck at the beginning of game
    for (int i = 0; i < this->n_cards; ++i) {
		this->cards[i] = Card(i % 13, i / 13);
	}
    for(int i = 0; i < 52; i++) {
        int m = i + (rand() % (52 - i));
        swap(cards[i], cards[m]); //swap the cards
        cards[i].print_card();
    }
    cout << endl;
}

Card Deck::get_cards() { //accessor
    return this->cards[n_cards];
}

int Deck::get_n_cards() { //accessor
    return this->n_cards;
}

void Deck::set_cards(Card new_cards) { //mutator
    this->cards[n_cards] = new_cards;
}

void Deck::set_n_cards(int new_n_cards) { //mutator
    this->n_cards = new_n_cards;
}

/*********************************************************************
** Function: Card& Deck::removeCard()
** Description: The top card gets removed from the deck.
** Parameters: None
** Pre-Conditions: The number of cards left in the deck should be at least 1.
** Post-Conditions: The top card gets distributed to the player that got a "Go Fish."
*********************************************************************/
Card& Deck::removeCard() {
	this->n_cards--;
	return this->cards[this->n_cards];
}

/*******************************************************************************************
The Big Three is not necessary for the Deck class because there is no dynamic memory. All a 
Deck has is an array of cards that starts at 52 (because there are 52 cards in the deck at the 
beginning of the game) and a variable n_cards that keeps track of how many cards are left in the 
deck. There are no pointer variables in the Deck class. In addition, cards can only be removed 
from the deck, not added to the deck. Thus, a destructor, CC, and AOO are not required, which means 
the Big Three and the Const keyword aren't required for the Deck class.

By making variables private, encapsulation can be enforced. This hides the details of the Deck class 
from other classes. Accessors are necessary because throughout the game, it is important to know how 
many cards are left in the deck. Mutators are also necessary because they help set the number of cards 
that are left in the deck after every turn. 
*******************************************************************************************/