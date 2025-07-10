/******************************************************
** Program: room.cpp
** Author: Harry Yu
** Date: 11/20/2022
** Description: The Room class creates a room, either with an event or 
without an event. It also keeps tracks of rows and columns.
** Input: None
** Output: None
******************************************************/

#include "room.h"
#include "event.h"
#include "player.h"
#include <iostream>
#include <string>

using namespace std;

/*********************************************************************
** Function: Room::Room()
** Description: The row and column are initialized to be 0, and by default, there is 
no event or player in a room.
** Parameters: None
** Pre-Conditions: The array of rooms must be a square and it must have a size of at 
least 4x4.
** Post-Conditions: By default, there is no event or player in a room.
*********************************************************************/
Room::Room() {
    this->row = 0;
    this->column = 0;
    this->eventInRoom = false;
    this->event = NULL;
    this->playerInRoom = false;
    this->player = NULL;
}

Room::~Room() { //delete the event in a room so there are no memory leaks
    delete this->event;
}

Room::Room(int r, int c) { //non-default constructor
    this->row = r;
    this->column = c;
}

int Room::get_row() { //get the row of a room
    return this->row;
}

int Room::get_column() { //get the column of a room
    return this->column;
}

bool Room::get_eventInRoom() { //get a bool value of whether or not there is an event in a room
    return this->eventInRoom;
}

Event* Room::get_event() { //get the event in a room if there is an event
    return this->event;
}

void Room::set_event(Event* evt) { //set the event in a room if there is an event
    this->event = evt;
    this->eventInRoom = true;
}

Player* Room::get_player() { //get the player in a room
    return this->player;
}

void Room::set_player(Player* player1) { //set the player in a room
    this->player = player1;
    this->playerInRoom = true;
}