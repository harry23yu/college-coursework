#ifndef BATS_H
#define BATS_H
using namespace std;

#include <iostream>
#include <string>
#include "event.h"

//Bats inherits from Event
class Bats : public Event {
    private:
        //no private variables
    public:
        Bats();
        void inThisRoom();
        void message();
        char character();
};

#endif