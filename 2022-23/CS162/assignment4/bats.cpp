/******************************************************
** Program: bats.cpp
** Author: Harry Yu
** Date: 11/20/2022
** Description: The Bats class represents the bats.
** Input: None
** Output: None
******************************************************/

#include "bats.h"
#include <iostream>
#include <string>

using namespace std;

Bats::Bats() : Event() {
    //empty
}

void Bats::inThisRoom() { //this message will print out if the player is inside a room with bats
    cout << "You entered a room with bats. They took you away to another room! " << endl;
}

void Bats::message() { //this message will print out if the player is adjacent to a room with bats
    cout << "You hear wings flapping. " << endl;
}

char Bats::character() { //bats are represented by 'B' in the grid
    return 'B';
}