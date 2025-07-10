#include "circle.h"
#include <iostream>
#include <string>

using namespace std;

Circle::Circle() : Shape() {
	//cout << "Inside Circle constructor " << endl;
	this->radius = 10.0;
}

Circle::~Circle() {
	//cout << "Circle Destrcutor is called..." << endl;
}

void Circle::display() const {
	Shape::display();
	//cout << "Area of circle: " << 3.14 * radius * radius << endl;
}

int Circle::area() {
    cout << "Area of circle: " << 3.14 * this->radius * this->radius << endl;
    return 0;
}