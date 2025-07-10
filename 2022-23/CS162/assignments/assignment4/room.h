#ifndef ROOM_H
#define ROOM_H
using namespace std;

#include <iostream>
#include <string>
#include "event.h"
#include "player.h"

class Room {
    protected:
        int row;
        int column;
        bool eventInRoom;
        Event* event;
        bool playerInRoom;
        Player* player;
    public:
        Room();
        ~Room();
        Room(int, int);
        int get_row();
        int get_column();
        bool get_eventInRoom();
        Event* get_event();
        void set_event(Event*);
        Player* get_player();
        void set_player(Player*);
};

#endif