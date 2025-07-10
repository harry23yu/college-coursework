#ifndef MULTDIV
#define MULTDIV

#include <iostream>

using namespace std;

struct Multdiv_entry {
    int mult;
    float div;
};

Multdiv_entry** create_array(int numRows, int numColumns);
void print_array(Multdiv_entry**, int numRows, int numColumns);
void delete_array(Multdiv_entry**, int numRows);

#endif