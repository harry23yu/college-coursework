#include <iostream>
#include <string>
#include "hand.h"
using namespace std;

Hand::Hand() { //default constructor
    this->cards = new Card[7];
    this->n_cards = 0; //each player starts with 0 cards before they get 7 cards at the beginning of the game
}

Hand::~Hand() { //destructor

}

Hand::Hand(const Hand& obj) {

}

Hand& Hand::operator=(const Hand&) {

}

Hand::Hand(Card*& deck_cards) {
    //Insert code here
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