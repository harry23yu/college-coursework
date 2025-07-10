#include <iostream>
#include <string>
#include "multdiv.h"
#include <iomanip>
using namespace std;

Multdiv_entry** create_array(int numRows, int numColumns) {
    Multdiv_entry** array;
    array = new Multdiv_entry*[numRows]; //create rows
    for (int i = 0; i < numRows; i++) {
        array[i] = new Multdiv_entry[numColumns]; //create columns
    }
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            array[i][j].mult = (i + 1) * (j + 1); //create multiplication table (assign values to each spot in the array)
        }
    }
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            float k = (float) i;
            float m = (float) j;
            array[i][j].div = (float)(k + 1.0) / (float)(m + 1.0); //create division table (assign values to each spot in the array)
        }
    }
    return array;
}

void print_array(Multdiv_entry** array, int numRows, int numColumns) {
    cout << "Multiplication table:" << endl;
    cout << endl;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            cout << array[i][j].mult << " "; //print multiplication table
        }
        cout << endl;
    }
    cout << endl;
    cout << "Division table:" << endl;
    cout << endl;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            cout << setprecision(2) << fixed;
            cout << array[i][j].div << " "; //print division table
        }
        cout << endl;
    }
    cout << endl;
}

void delete_array(Multdiv_entry** array, int numRows) {
    for (int i = 0; i < numRows; i++) {
        delete array[i];
    }
    delete []array;
    array = NULL;
}