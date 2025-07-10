#ifndef PLAYER_H
#define PLAYER_H
using namespace std;

#include <iostream>
#include <string>

class Player {
    protected:
        int numOfArrows;
        bool hasGold;
        bool wumpusDied;
        int row;
        int column;
    public:
        Player();
        Player(int, bool, bool);
        int get_numOfArrows();
        void set_numOfArrows(int);
        void decreaseNumOfArrows();
        bool get_hasGold();
        void set_hasGold(bool);
        bool get_wumpusDied();
        void set_wumpusDied(bool);
        char character();
        int get_row();
        void set_row(int);
        int get_column();
        void set_column(int);
};

#endif