#ifndef EVENT_H
#define EVENT_H
using namespace std;

#include <iostream>
#include <string>

class Event {
    protected:
        char symbol;
    public:
        Event();
        virtual ~Event();
        virtual void inThisRoom() = 0;
        virtual void message() = 0;
        virtual char character();
};

#endif