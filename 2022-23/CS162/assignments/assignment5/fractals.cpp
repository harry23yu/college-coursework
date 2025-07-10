/******************************************************
** Program: fractals.cpp
** Author: Harry Yu
** Date: 12/4/2022
** Description: This program generates recursive fractals. The longest line,
in the middle, contains n stars. The fractal is shifted col columns to the right.
n must be a positive odd integer, and col must be a nonnegative integer.
** Input: n (number of stars on the longest line) and col (number of columns the 
fractal is shifted to the right).
** Output: A fractal will be printed out.
******************************************************/

#include <iostream>
#include <string>
using namespace std;

/*********************************************************************
** Function: void pattern(int n, int col)
** Description: Recursively prints out stars and spaces, generating fractals 
within the main fractal, until it hits the base case.
** Parameters: int n, int col
** Pre-Conditions: n bust be a positive odd integer and col must be a nonnegative 
integer.
** Post-Conditions: The fractal must be printed out using recursion.
*********************************************************************/
void pattern(int n, int col) {
    if (n == 1) { //base case
        for (int i = 0; i < col; i++) {
            cout << " ";
        }
        cout << "*" << endl;
    }
    else {
        pattern(n - 2, col + 2);
        for (int i = 0; i < col; i++) {
            cout << " ";
        }
        for (int i = 0; i < n; i++) {
            cout << "* ";
        }
        cout << endl;
        pattern(n - 2, col + 2);
    }
}

/*********************************************************************
** Function: int main()
** Description: Asks the user what they want n and col to be.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: n must be a positive odd integer and col must be a nonnegative 
integer.
*********************************************************************/
int main() {
    int valueOfN, numOfCols;
    cout << "What do you want value of n to be? ";
    cin >> valueOfN;
    cout << "What do you want the number of columns to be? ";
    cin >> numOfCols;
    pattern(valueOfN, numOfCols); //call the recursive function
    return 0;
}