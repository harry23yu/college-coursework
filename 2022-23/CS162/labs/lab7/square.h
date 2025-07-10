#ifndef SQUARE_H
#define SQUARE_H 

#include "rectangle.h"

using namespace std;

//Square inherits from Rectangle 
class Square : public Rectangle {
    public:
        Square();
        ~Square();
        void set_width(float);
        void set_height(float);
        void display() const; //redefine
};

#endif