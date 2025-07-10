#ifndef CIRCLE_H
#define CIRCLE_H 

#include "shape.h"

using namespace std;

//Circle inherits from Shape 
class Circle : public Shape {
    private:
        float radius;
    public:
        Circle();
        ~Circle();
        void set_width(float);
        void set_height(float);
        void display() const; //redefine
};

#endif