#ifndef WUMPUS_H
#define WUMPUS_H
using namespace std;

#include <iostream>
#include <string>
#include "event.h"

//Wumpus inherits from Event
class Wumpus : public Event {
    private:
        bool isDead;
    public:
        Wumpus();
        void inThisRoom();
        void message();
        char character();
};

#endif