/******************************************************
** Program: card.cpp
** Author: Harry Yu
** Date: 11/6/2022
** Description: The Card class helps identify the rank and suit for each card.
** Input: None
** Output: None
******************************************************/

#include <iostream>
#include <string.h>
#include "card.h"
using namespace std;

Card::Card() { //default constructor
    this->rank = -1;
    this->suit = -1;
}

Card::Card(int new_rank, int new_suit) { //non-default constructor
    this->rank = new_rank;
    this->suit = new_suit;
}

int Card::get_rank() { //accessor
    return this->rank;
}

int Card::get_suit() { //accessor
    return this->suit;
}

void Card::set_rank(int new_rank) { //mutator
    this->rank = new_rank;
}

void Card::set_suit(int new_suit) { //mutator
    this->suit = new_suit;
}

/*********************************************************************
** Function: string Card::map_rank()
** Description: Depending on the integer of the rank, it will return a value. The 
possible values are A, 2-10, J, Q, and K, or the rank doesn't exist.
** Parameters: None
** Pre-Conditions: this->rank must be an integer.
** Post-Conditions: A value of the rank should be returned. For example, 10 would 
return "J."
*********************************************************************/
string Card::map_rank() {
    if (this->rank == 0) {
        return "A";
    }
    if (this->rank > 0 && this->rank < 10) {
        return to_string(this->rank + 1);
    }
    if (this->rank == 10) {
        return "J";
    }
    if (this->rank == 11) {
        return "Q";
    }
    if (this->rank == 12) {
        return "K";
    }
    return "Card rank doesn't exist";
}

/*********************************************************************
** Function: string Card::map_suit()
** Description: Depending on the integer of the suit, it will return a value. The 
possible values are club, diamond, heart, and spade (represent by symbols), or the suit 
doesn't exist.
** Parameters: None
** Pre-Conditions: this->suit must be an integer.
** Post-Conditions: A value of the suit should be returned. For example, 2 would 
return "♥️."
*********************************************************************/
string Card::map_suit() {
    if (this->suit == 0) {
        return "♣️";
    }
    if (this->suit == 1) {
        return "♦️";
    }
    if (this->suit == 2) {
        return "♥️";
    }
    if (this->suit == 3) {
        return "♠️";
    }
    return "Card suit doesn't exist";
}

/*********************************************************************
** Function: void Card::print_card()
** Description: The card will be printed with its rank and suit.
** Parameters: None
** Pre-Conditions: The rank and suit variables should be non-negative integers.
** Post-Conditions: The card should be printed with the correct rank and suit. For 
example, if this->rank = 12 and this->suit = 0, then it should print out "K♣️."
*********************************************************************/
void Card::print_card() {
    cout << this->map_rank() << this->map_suit() << " ";
}

/*******************************************************************************************
The Big Three is not necessary for the Card class because there is no dynamic memory. All a 
Card has is a rank (int) and a suit (int). There are no pointer variables in the Card class. 
A destructor, CC, and AOO are not required, which means the Big Three and the Const keyword 
aren't required for the Card class.

Variables are private because of encapsulation, which avoids broken code. Accessors are necessary 
because the players need to know what rank and what suit each card in their hand has. Mutators 
can set the values of the rank and the suit. This will help with encapsulation.
*******************************************************************************************/