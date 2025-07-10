#include "rectangle.h"
#include <iostream>
#include <string>

using namespace std;

Rectangle::Rectangle() : Shape() {
	//cout << "Inside Rectangle constructor " << endl;
	this->width = 2.5;
    this->height = 8.32;
}

Rectangle::~Rectangle() {
	//cout << "Rectangle Destrcutor is called..." << endl;
}

void Rectangle::set_width(float new_width) {
    this->width = new_width;
}

void Rectangle::set_height(float new_height) {
    this->height = new_height;
}

void Rectangle::display() const {
	Shape::display();
	cout << "Area of rectangle/square: " << this->width * this->height << endl;
}