/******************************************************
** Program: hand.cpp
** Author: Harry Yu
** Date: 11/6/2022
** Description: The Hand class helps sort the cards from highest to lowest rank. It 
also makes sure that books and cards can be removed from each player, as well as add 
a card to each player.
** Input: None
** Output: None
******************************************************/

#include <iostream>
#include <string>
#include "hand.h"
using namespace std;

Hand::Hand() { //default constructor
	this->n_cards = 0; //each player starts with 0 cards before they get 7 cards at the beginning of the game
    this->cards = NULL;
}

/*********************************************************************
** Function: Hand::~Hand()
** Description: It deletes the memory from the cards array.
** Parameters: None
** Pre-Conditions: The cards array should have at least one card in a player's hand.
** Post-Conditions: There should be no memory leaks.
*********************************************************************/
Hand::~Hand() { //destructor
    //cout << "Destructor is called..." << endl;
	if (this->cards != NULL) {
		delete [] this->cards;
		this->cards = NULL;
	}
}

/*********************************************************************
** Function: Hand& Hand::operator=(const Hand& p1)
** Description: Copies the contents of the old hand to the new hand.
** Parameters: const Hand& p1
** Pre-Conditions: There should be an array of cards in the player's hand.
** Post-Conditions: The old array of cards shouldn't be destroyed, and the new card 
should be added to the player's hand. Also, there shouldn't be any memory leaks.
*********************************************************************/
Hand& Hand::operator=(const Hand& p1) { //AOO
    //cout << "Inside our AOO..." << endl;
	//member-wise copy
	this->n_cards = p1.n_cards; 

	//free the memory first 
	if (this->cards != NULL) {
		delete [] this->cards;
    }
	//deep copy
	this->cards = new Card [this->n_cards];
	for (int i = 0; i < this->n_cards; i++) {
		this->cards[i] = p1.cards[i];
	}
	return *this;
}

/*********************************************************************
** Function: Hand::Hand(const Hand& p1)
** Description: Copies the contents of the old array to the new array.
** Parameters: const Hand& p1
** Pre-Conditions: There should be an array of cards in the player's hand.
** Post-Conditions: The player's hand should now contain a new card, and there 
should be no memory leaks.
*********************************************************************/ 
Hand::Hand(const Hand& p1) { //copy constructor
    //cout << "Inside our CC..." << endl;
	//member-wise copy
	this->n_cards = p1.n_cards; 

	//deep copy
	this->cards = new Card [this->n_cards];
	for (int i = 0; i < this->n_cards; ++i) {
		this->cards[i] = p1.cards[i];
	}
}

Card* Hand::get_cards() { //accessor
    return this->cards;
}

int Hand::get_n_cards() { //accessor
    return this->n_cards;
}

void Hand::set_cards(Card* new_cards) { //mutator
    this->cards = new_cards;
}

void Hand::set_n_cards(int new_n_cards) { //mutator
    this->n_cards = new_n_cards;
}

/*********************************************************************
** Function: void Hand::swap(Card* a, Card* b)
** Description: Swaps the position of two cards.
** Parameters: Card* a, Card* b
** Pre-Conditions: The two cards must exist and have a rank and suit value.
** Post-Conditions: The two cards should be swapped in terms of their position.
*********************************************************************/ 
void Hand::swap(Card* a, Card* b) {
	Card tmp = *a;
	*a = *b;
	*b = tmp;
}

/*********************************************************************
** Function: void Hand::insertion_sort()
** Description: Arranges the rank of the cards in the player's hand in descending order.
** Parameters: None
** Pre-Conditions: The player should have an array of cards in their hand.
** Post-Conditions: The array of cards should be in descending order in terms of the rank. 
For example, if a player has cards with ranks 3, 8, 4, and 6, then after the function is 
called, the player's hand should look like this: 8, 6, 4, and 3.
*********************************************************************/ 
void Hand::insertion_sort() {
  	for (int i = 1; i < this->n_cards; i++) {
    	for (int j = i; j > 0; j--) { //removed = sign on j
      		if (this->cards[j-1].get_rank() >= this->cards[j].get_rank()) {
        		break;
      		}	
      		swap(&this->cards[j-1], &this->cards[j]);
    	}
  	}
}

/*********************************************************************
** Function: void Hand::addACard(Card& c)
** Description: Adds a card to the player's hand.
** Parameters: Card& c
** Pre-Conditions: The player's hand should have an array of cards.
** Post-Conditions: After the player draws a card from the deck or steals a card 
from a player, then the card should be added to their hand.
*********************************************************************/ 
void Hand::addACard(Card& c) { //copied from Roger
	Card* temp_arr = new Card [this->n_cards + 1]; //allocate an array of cards with size + 1
	for (int i = 0; i < this->n_cards; i++) { //copy the old array objects (cards[i]) to new array (temp_arr[i])
		temp_arr[i] = this->cards[i]; //AOO of cards
	}
	temp_arr[this->n_cards] = c; //add the new card object c, into index n_cards
	if (this->cards != NULL) { //delete the old array using cards
		delete [] this->cards;
	}
	this->cards = temp_arr; //set cards to temp_arr
	this->n_cards++; //increment the n_cards
	insertion_sort();
}

/*********************************************************************
** Function: void Hand::removeACard(string requestRank)
** Description: Removes a card from a player's hand.
** Parameters: string requestRank
** Pre-Conditions: The player should have an array of cards in their hand.
** Post-Conditions: If the opponent asks for a rank and the player has the 
rank, then the opponent gets to steal the card of that rank from the player, 
and that card will be removed from the player.
*********************************************************************/ 
void Hand::removeACard(string requestRank) {
	bool cardAlreadyMatched = false; //initally, the card with the requested rank hasn't been found
	int temp = 0;
	for (int i = 0; i < this->n_cards; i++) {
		bool cardMatch = false;
		if (requestRank == this->cards[i].map_rank() && temp == 0) {
			cardMatch = true;
			cards[i] = cards[i + 1];
			cardAlreadyMatched = true;
			this->n_cards--;
			temp++;
		}
		if (cardMatch == false) {
			if (cardAlreadyMatched == false) { //if card with the requested rank hasn't been found
				cards[i] = cards[i];
			}
			if (cardAlreadyMatched == true) { //if card with the requested rank has already been found
				cards[i] = cards[i + 1];
				continue;
			}
		}
	}
	insertion_sort();
}

/*********************************************************************
** Function: void Hand::removeABook()
** Description: Removes a book from a player.
** Parameters: None
** Pre-Conditions: The player needs to have an a book.
** Post-Conditions: The book needs to removed from the player's hand.
*********************************************************************/ 
void Hand::removeABook() {
	for (int i = 0; i < n_cards - 3; i++) {
		if (cards[i].map_rank() == cards[i+1].map_rank()) {
			if (cards[i].map_rank() == cards[i+2].map_rank()) {
				if (cards[i].map_rank() == cards[i+3].map_rank()) {
					cout << endl << "Book found!" << endl;
					for (int j = i; j < i + 4; j++) {
						removeACard(cards[i].map_rank()); //remove all cards with the same rank in a book
					}
				}
			}
		}
	}
}

/*******************************************************************************************
I used the Big Three in the Hand class because the Hand class contain a Card pointer to cards, 
which stores the array of cards in a player's hand. As the game progresses, the number of cards
in each player's hand will increase and decrease. Dynamic memory exists in the Hand class. Some 
cards will stay the same and some cards will be removed or added after each turn. Also, I have 
to prevent changes to the hand I'm copying data from. This is why the CC, AOO, and the Const 
keyword are necessary. In order to make sure there are no memory leaks, a destructor must be 
called. Thus, the Big Three is required in the Hand class.

Private variables are vital to encapsulation. This way, they can’t be modified outside of the class. 
Accessors are important because during every turn, the program needs to know how many cards are left 
in both players' hands, as well as the array of cards in both players' hands. Mutators help set the value 
of the objects inside the Hand class and they are also vital to encapsulation, which avoids broken code.
*******************************************************************************************/