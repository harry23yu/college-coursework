#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool powerOfTwo(int n) {
    if ((n & (n-1)) == 0 && n!=1) {
        return true;
    }
    return false;
}

int star(int n) {
    int i = n;
    int answer = 0;
    while (i % 2 == 0) {
        i = i / 2;
        answer++;
    }
    return pow(2, answer);
}

int spaces(int n) {
    if (powerOfTwo(n) == true) {
        return 0;
    }
    return (n - 1) / 2;
}

void printpattern(int n) {
    int i, numOfSpaces, numOfStars;
    numOfSpaces = spaces(n);
    for(i = 1; i <= numOfSpaces; i++)
        cout << " ";
    numOfStars = star(n);
    for(i = 1; i <= numOfStars; i++)
        cout << "* ";
}

void pattern(int n) {
    int i, j, numOfSpaces;
    for(i = 1; i <= n; i++) {
        printpattern(i);
        cout << endl;
    }
    numOfSpaces = n / 2;
    for(i = 1; i <= n - 1; i++) {
        for(j = 1; j <= n; j++) {
            cout << " ";
        }
        printpattern(i);
        cout << endl;
    }
}

int main() {
    int n;
    cout << "What do you want n to be? ";
    cin >> n;
    pattern(n);
    return 0;
}