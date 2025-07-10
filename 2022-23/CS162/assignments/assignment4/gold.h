#ifndef GOLD_H
#define GOLD_H
using namespace std;

#include <iostream>
#include <string>
#include "event.h"

//Gold inherits from Event
class Gold : public Event {
    private:
        bool goldPickedUp;
    public:
        Gold();
        void inThisRoom();
        void message();
        char character();
};

#endif