/******************************************************
** Program: event.cpp
** Author: Harry Yu
** Date: 11/20/2022
** Description: The Event class is the parent class of Wumpus, Bats, 
Pit, and Gold. Each room with an event contains a different message if the 
player is adjacent to them or in them, and each event is represented by a 
different letter.
** Input: None
** Output: None
******************************************************/

#include "event.h"
#include <iostream>
#include <string>

using namespace std;

Event::Event() {
    //empty
}

Event::~Event() {
    //empty
}

// void Event::inThisRoom() {
//     //inThisRoom = " ";
// }

// void Event::message() {
//     //message = " ";
// }

char Event::character() { //the default symbol for a room is ' ' (empty room)
    char symbol = ' ';
    return symbol;
}