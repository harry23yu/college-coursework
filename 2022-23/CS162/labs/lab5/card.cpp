#include <iostream>
#include <string>
#include "card.h"
using namespace std;

Card::Card() {
    this->rank = -1;
    this->suit = -1;
}

Card::Card(int new_rank, int new_suit) {
    this->rank = new_rank;
    this->suit = new_suit;
}

void Card::set_rank(int new_rank) {
    this->rank = new_rank;
}

int Card::get_rank() {
    return this->rank;
}

void Card::set_suit(int new_suit) {
    this->suit = new_suit;
}

int Card::get_suit() {
    return this->suit;
}

string Card::map_rank() {
    if (this->rank == 0) {
        return "A";
    }
    if (this->rank > 0 && this->rank < 10) {
        return to_string(this->rank);
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
    return "Card doesn't exist";
}

string Card::map_suit() {
    if (this->suit == 0) {
        return "clubs";
    }
    if (this->suit == 1) {
        return "diamonds";
    }
    if (this->suit == 2) {
        return "hearts";
    }
    if (this->suit == 3) {
        return "spades";
    }
}

void print_card() {
    //Do it later on assignment 3
}