#include "square.h"
#include <iostream>
#include <string>

using namespace std;

Square::Square() : Rectangle() {
	//cout << "Inside Square constructor " << endl;
	// this->width = 2.5;
    // this->height = 10;
}

Square::~Square() {
	//cout << "Square Destrcutor is called..." << endl;
}

void Square::set_width(float new_width) {
    Rectangle::set_width(new_width); //first option
    Rectangle::set_height(new_width); //first option
    //Rectangle* ptr = this; (second option)
    //ptr->set_width(new_width); (second option)
    // this->width = new_width;
}

void Square::set_height(float new_width) {
    Rectangle::set_height(new_width);
    Rectangle::set_width(new_width);
    // this->height = this->width; //a square has the same height and width
}

void Square::display() const {
	Rectangle::display();
	//cout << "Area of square: " << this->width * this->height << endl;
}