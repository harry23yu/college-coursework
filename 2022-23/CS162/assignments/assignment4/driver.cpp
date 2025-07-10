/******************************************************
** Program: driver.cpp
** Author: Harry Yu
** Date: 11/20/2022
** Description: This program simulates a game of Hunt the Wumpus.
** Input: Size of the cave.
** Output: Cave displays all the events and player.
******************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "wumpus.h"
#include "bats.h"
#include "pit.h"
#include "gold.h"
#include "event.h"
#include "room.h"
#include "player.h"
#include "game.h"

using namespace std;

/*********************************************************************
** Function: int main()
** Description: The user will be asked what size they want for the grid in Hunt the 
Wumpus. The size of the grid must be at least 4x4 (it is a square). Then, the game 
will begin.
** Parameters: None
** Pre-Conditions: playAgain must be "yes."
** Post-Conditions: The size of the grid must be at least 4x4.
*********************************************************************/
int main() {
    string playAgain = "yes";
    do {
        cout << "Welcome to the game of Hunt the Wumpus! ";
        int sizeOfCave;
        cout << "What size do you want the cave to be? ";
        cin >> sizeOfCave;
        if (sizeOfCave < 4) {
            cout << "Caves smaller than 4 rooms per side aren't allowed. Please enter new size. " << endl;
            main();
        }
        else {
            //int dimension = sizeOfCave;
            Game g(sizeOfCave);
            g.initializeRooms();
            g.addEvents();
            g.displayGrid();
            g.moveOrFire();
            g.printMessages();
            g.inEventRoom();
            //string playAgain;
            playAgain = "";
            cout << "Do you want to play again? If yes, type 'yes.' ";
            cin >> playAgain;
            if (playAgain != "yes") {
                break;
            }
        }
    }
    while (playAgain == "yes");
    return 0;
}