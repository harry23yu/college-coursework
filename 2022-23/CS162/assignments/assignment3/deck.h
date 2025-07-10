#ifndef DECK_H
#define DECK_H
using namespace std;

#include <iostream>
#include <string>
#include "card.h"

class Deck {
    private:
        Card cards[52]; //A full deck of cards
        int n_cards; //Number of cards remaining in the deck.
    public:
        //constructors
        Deck();
        //no big 3
        //accessors
        Card get_cards();
        int get_n_cards();
        //mutators
        void set_cards(Card);
        void set_n_cards(int);
        //other member functions
        Card& removeCard();
};

#endif