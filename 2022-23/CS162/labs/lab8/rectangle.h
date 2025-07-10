#ifndef RECTANGLE_H
#define RECTANGLE_H 

#include "shape.h"

using namespace std;

//Rectangle inherits from Shape 
class Rectangle : public Shape {
    private:
        float width;
        float height;
    public:
        Rectangle();
        ~Rectangle();
        void set_width(float);
        void set_height(float);
        void display() const; //redefine
        int area();
};

#endif