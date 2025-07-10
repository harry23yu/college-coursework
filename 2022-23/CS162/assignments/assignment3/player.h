#ifndef PLAYER_H
#define PLAYER_H
using namespace std;

#include <iostream>
#include <string>

#include "card.h"
#include "hand.h"

class Player {
    private:
        Hand hand;
        int* books; // Array with ranks for which the player has books.
        int n_books;
    public:
        //constructors
        Player();
        Player(int);
        //destructor
        ~Player();
        //AOO
        Player &operator=(const Player&);
        //copy constructor
        Player(const Player&);
        //accessors
        Hand get_hand();
        int* get_books();
        int get_n_books();
        //mutators
        void set_hand(Hand);
        void set_books(int*);
        void set_n_books(int);
        //other member functions
        void placeCard(Card&);
        void removeCard(string);
        //void swap(Card*, Card*);
        //void insertion_sort();
        void removeBook(int); //edited line
};

#endif