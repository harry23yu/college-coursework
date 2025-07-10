#ifndef SHAPE_H
#define SHAPE_H
using namespace std;

#include <iostream>
#include <string>

class Shape {
    protected:
        const string name;
        string color;
    public:
        Shape();
        ~Shape();
        void display() const;
        int area();

        /*//accessors
        Card get_cards();
        int get_n_cards();
        //mutators
        void set_cards(Card);
        void set_n_cards(int);
        //other member functions
        Card drawCardFromDeck();*/
};

#endif