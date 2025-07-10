/******************************************************
** Program: wumpus.cpp
** Author: Harry Yu
** Date: 11/20/2022
** Description: The Wumpus class represents the Wumpus.
** Input: None
** Output: None
******************************************************/

#include "wumpus.h"
#include <iostream>
#include <string>

using namespace std;

/*********************************************************************
** Function: Wumpus::Wumpus() : Event()
** Description: At the beginning of the game, the Wumpus is not dead.
** Parameters: None
** Pre-Conditions: The game must start with the Wumpus hiding somewhere in the cave.
** Post-Conditions: The Wumpus is not dead.
*********************************************************************/
Wumpus::Wumpus() : Event() {
    this->isDead = false;
}

void Wumpus::inThisRoom() { //this message will print out if the player is inside the Wumpus room, and the Wumpus is still alive
    cout << "You entered the Wumpus room when he is alive! He ate you. " << endl;
}

void Wumpus::message() { //this message will print out if the player is adjacent to the Wumpus room
    cout << "You smell a terrible stench. " << endl;
}

char Wumpus::character() { //the Wumpus is represented by 'W' in the grid
    return 'W';
}