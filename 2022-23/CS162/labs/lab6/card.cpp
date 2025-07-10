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

string Card::map_suit() { //member functions within the class
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

void Card::print_card() {
    cout << this->map_rank() << this->map_suit() << " ";
}