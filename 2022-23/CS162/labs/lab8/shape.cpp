#include "shape.h"
#include <iostream>
#include <string>

using namespace std;

Shape::Shape() : name("some shape") {
    //cout << "Shape constructor" << endl;
    this->color = "some color";
}

Shape::~Shape() {
    //cout << "Shape Destructor is called..." << endl;
}

string Shape::get_name() {
    return this->name;
}

string Shape::get_color() {
    return this->color;
}

void Shape::display() const {
    cout << "Name: " << this->name << endl;
    cout << "Color: " << this->color << endl;
}

/*int Shape::area() {
    return 0;
}*/