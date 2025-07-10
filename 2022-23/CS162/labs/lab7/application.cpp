#include <iostream>
#include <string>
#include "circle.h"
#include "square.h"

using namespace std;

int main() {
    Shape s;
    s.display();
    Rectangle r;
    r.display();
    Circle c;
    c.display();
    Square sq;
    sq.set_width(2.5);
    sq.set_height(100);
    sq.display();
}