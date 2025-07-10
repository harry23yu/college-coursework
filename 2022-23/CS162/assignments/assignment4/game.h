#ifndef GAME_H
#define GAME_H
using namespace std;

#include <iostream>
#include <string>

#include "wumpus.h"
#include "pit.h"
#include "gold.h"
#include "bats.h"
#include "player.h"
#include "event.h"
#include "room.h"

class Game {
    protected:
        bool gameOver;
        bool playerHasWon;
        int size;
        Player* player;
        int playerRow;
        int playerColumn;
        int playerStartRow;
        int playerStartColumn;
        vector <vector<Room> > caveGrid;
    public:
        Game(int);
        ~Game();
        void initializeRooms();
        void addEvents();
        void displayGrid();
        void moveOrFire();
        void wumpusMove();
        void printMessages();
        void inEventRoom();
        void playerWins();
        void gameIsOver();
};

#endif