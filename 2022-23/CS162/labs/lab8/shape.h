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
        string get_name();
        string get_color();
        void display() const;
        //int area();
        virtual int area() = 0;

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