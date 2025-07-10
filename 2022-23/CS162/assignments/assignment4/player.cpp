/******************************************************
** Program: player.cpp
** Author: Harry Yu
** Date: 11/20/2022
** Description: The Player class keeps track of how many arrows are left, if 
the gold has been picked up, and if the Wumpus has been killed.
** Input: None
** Output: None
******************************************************/

#include "player.h"
#include <iostream>
#include <string>

using namespace std;

/*********************************************************************
** Function: Player::Player()
** Description: When the player starts, they have 3 arrows, and the gold hasn't been 
collected yet. The Wumpus isn't dead yet.
** Parameters: None
** Pre-Conditions: The player has 3 arrows, the gold hasn't been collected yet, and the Wumpus 
is alive.
** Post-Conditions: The player will be able to find the gold and kill the Wumpus using arrows.
*********************************************************************/
Player::Player() {
    this->numOfArrows = 3;
    this->hasGold = false;
    this->wumpusDied = false;
}

Player::Player(int arrowsLeft, bool gold, bool deadWumpus) { //non-default constructor
    this->numOfArrows = arrowsLeft;
    this->hasGold = gold;
    this->wumpusDied = deadWumpus;
}

int Player::get_numOfArrows() { //returns the number of arrows that the player has
    return this->numOfArrows;
}

void Player::set_numOfArrows(int numArrows) { //sets the number of arrows that the player has
    this->numOfArrows = numArrows;
}

void Player::decreaseNumOfArrows() { //when the player shoots an arrow, the number of arrows decreases by 1
    this->numOfArrows--;
}

bool Player::get_hasGold() { //returns a bool value that indicates if the gold has been collected by the player
    return this->hasGold;
}

void Player::set_hasGold(bool a) { //sets the bool value of whether or not the gold has been collected by the player
    this->hasGold = a;
}

bool Player::get_wumpusDied() { //returns a bool value that indicates if the Wumpus is dead
    return this->wumpusDied;
}

void Player::set_wumpusDied(bool b) { //sets the bool value of whether or not the Wumpus has been killed
    this->wumpusDied = b;
}

int Player::get_row() { //gets the row of the player
    return this->row;
}

void Player::set_row(int r) { //sets the row of the player
    this->row = r;
}

int Player::get_column() { //gets the column of the player
    return this->column;
}

void Player::set_column(int c) { //sets the column of the player
    this->column = c;
}

char Player::character() { //the room with the player is represented by *
    return '*';
}