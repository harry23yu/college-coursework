#ifndef PIT_H
#define PIT_H
using namespace std;

#include <iostream>
#include <string>
#include "event.h"

//Pit inherits from Event
class Pit : public Event {
    private:
        //no private variables
    public:
        Pit();
        void inThisRoom();
        void message();
        char character();
};

#endif