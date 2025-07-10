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
        void swap(Card*, Card*);
        void insertion_sort();
        void addACard(Card&);
        void removeACard(string);
        void removeABook();
};

#endif