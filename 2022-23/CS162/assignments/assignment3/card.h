#ifndef CARD_H
#define CARD_H
using namespace std;

#include <iostream>
#include <string>

class Card {
    private:
        int rank;
        int suit;
    public:
        //constructors
        Card();
        Card(int, int);
        //no big 3
        //accessors
        int get_rank();
        int get_suit();
        //mutators
        void set_rank(int);
        void set_suit(int);
        //other member functions
        string map_rank();
        string map_suit();
        void print_card();
};

#endif