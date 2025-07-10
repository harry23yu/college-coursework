/******************************************************
** Program: gold.cpp
** Author: Harry Yu
** Date: 11/20/2022
** Description: The Gold class represents the gold.
** Input: None
** Output: None
******************************************************/

#include "gold.h"
#include <iostream>
#include <string>

using namespace std;

/*********************************************************************
** Function: Gold::Gold() : Event()
** Description: At the beginning of the game, the gold hasn't been picked up by the player.
** Parameters: None
** Pre-Conditions: The game must start with the gold hiding somewhere in the cave.
** Post-Conditions: The gold hasn't been picked up yet.
*********************************************************************/
Gold::Gold() : Event() {
    this->goldPickedUp = false;
}

void Gold::inThisRoom() { //this message will print out if the player is inside the room with the gold
    cout << "You found the hidden gold and picked it up! " << endl;
    this->goldPickedUp = true;
}

void Gold::message() { //this message will print out if the player is adjacent to the room with the gold
    cout << "You see a glimmer nearby. " << endl;
}

char Gold::character() { //the gold is represented by 'G' in the grid
    return 'G';
}