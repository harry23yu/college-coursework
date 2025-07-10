#ifndef POINT_H
#define POINT_H
using namespace std;

#include <iostream>
#include <string>
#include <fstream>

class Card {
    private: //only what's in theis class can access it
        int rank;
        int suit;
    public: //any function anywhere can access it
        //constructors create objects of this class
        Card(); //default constructor
        Card(int, int);

        //getters prints private attributes
        int get_rank();
        int get_suit();
        //and setters
        void set_rank(int);
        void set_suit(int);
        string map_rank();
        string map_suit();
};

// Card(); //Card constructor
// void set_rank(int);
// int get_rank();
// void set_suit(int);
// int get_suit();
// string map_suit(); //convert the int suit to corresponding string
// string map_rank(); //convert the int rank to corresponding string
// void print_card(); //print the card out

#endif