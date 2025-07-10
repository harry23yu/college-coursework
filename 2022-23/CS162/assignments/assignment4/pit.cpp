/******************************************************
** Program: pit.cpp
** Author: Harry Yu
** Date: 11/20/2022
** Description: The Pit class represents the pits.
** Input: None
** Output: None
******************************************************/

#include "pit.h"
#include <iostream>
#include <string>

using namespace std;

Pit::Pit() : Event() {
    //empty
}

void Pit::inThisRoom() { //this message will print out if the player is inside a room with a pit
    cout << "You fell into a pit. You lost. " << endl;
}

void Pit::message() { //this message will print out if the player is adjacent to a room with a pit
    cout << "You feel a breeze. " << endl;
}

char Pit::character() { //pits are represented by 'P' in the grid
    return 'P';
}