#ifndef HAND_H
#define HAND_H
using namespace std;

#include <iostream>
#include <string>

#include "card.h"

class Hand {
    private:
        Card* cards; //An array of cards in hand
        int n_cards; //Number of cards in the hand
    public: //must have constructors, destructor, accessors, and mutators
        //constructors
        Hand();
        Hand(Card*&);
        //destructor
        ~Hand();
        //AOO
        Hand &operator=(const Hand&);
        //copy constructor
        Hand(const Hand&);
        //accessors
        Card* get_cards();
        int get_n_cards();
        //mutators
        void set_cards(Card*);
        void set_n_cards(int);
        //other member functions
        void addCardToPlayer();
        void removeCardFromPlayer();
        void checkBooks();
        void removeBooks();
};

#endif