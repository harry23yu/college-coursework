#include <iostream>
#include <string>
#include <vector>
#include "circle.h"
#include "square.h"

using namespace std;

void print_shape_info(Shape *);

void print_shape_info(Shape * s) {
    // (*s).display();
    // //cout << (*s).area() << endl;
    // (*s).area();
    cout << s->get_name() << endl;
    cout << s->get_color() << endl;
    cout << s->area() << endl;
    // cout << "Size: " << shape_vec.size() << endl;
    // cout << "Capacity: " << shape_vec.capacity() << endl;
}

int main() {
    // Shape s;
    // s.display();
    // Rectangle r;
    // r.display();
    // r.area();
    // Circle c;
    // print_shape_info(&c);
    // Square sq;
    // sq.set_width(2.5);
    // sq.set_height(100);
    // sq.display();
    // sq.area();
    // (*s).display();
    // //cout << (*s).area() << endl;
    // (*s).area();
    vector<Shape* > shape_vec;
    for (int i = 0; i < 3; i++) {
        shape_vec.push_back(new Circle());
    }
    for (int i = 0; i < 3; i++) {
        shape_vec.push_back(new Square());
    }
    for (int i = 0; i < 4; i++) {
        shape_vec.push_back(new Rectangle());
    }
    for (int i = 0; i < 10; i++) {
        print_shape_info(shape_vec[i]);
    }
    cout << "Size: " << shape_vec.size() << endl;
    cout << "Capacity: " << shape_vec.capacity() << endl;
}