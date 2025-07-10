/******************************************************
** Program: game.cpp
** Author: Harry Yu
** Date: 11/20/2022
** Description: The Game class simulates a game of Hunt the Wumpus. If the 
player falls into a pit or gets eaten by the Wumpus, they lose. If they enter 
a room with bats, they will get taken into a random room somewhere else in the 
cave. If they enter a room with gold, they will take the gold with them. The player 
wins by killing the Wumpus, taking the gold, and making it back to their starting 
position unharmed. If the player is adjacent to a room with an event, a message will 
be printed in the terminal.
** Input: Move or fire an arrow north, west, east, or south.
** Output: Player will move to an adjacent room or the number of arrows will decrease.
******************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "wumpus.h"
#include "pit.h"
#include "gold.h"
#include "bats.h"
#include "player.h"
#include "event.h"
#include "room.h"
#include "game.h"

/*********************************************************************
** Function: Game::Game(int dimension)
** Description: At the beginning of the game, the player hasn't won and it is not 
game over yet. The size of the grid is the dimension.
** Parameters: int dimension
** Pre-Conditions: The player haven't won or lost.
** Post-Conditions: The player will be able to move.
*********************************************************************/
Game::Game(int dimension) {
    this->gameOver = false;
    this->playerHasWon = false;
    this->size = dimension;
}

Game::~Game() { //deletes the player after the game is over so there are no memory leaks
    delete this->player;
}

/*********************************************************************
** Function: void Game::initializeRooms()
** Description: Initialize a 2D vector of rooms.
** Parameters: None
** Pre-Conditions: The 2D vector of rooms must be at least 4x4 or larger, and 
it must be a square.
** Post-Conditions: The 2D vector of rooms will be initialized.
*********************************************************************/
void Game::initializeRooms() {
    for (int i = 0; i < this->size; i++) {
        vector<Room> row_vec;
        for (int j = 0; j < this->size; j++) {
            row_vec.push_back(Room());
        }
        this->caveGrid.push_back(row_vec);
    }
}

/*********************************************************************
** Function: void Game::addEvents()
** Description: Events will be added to rooms, as well as the player.
** Parameters: None
** Pre-Conditions: The array of rooms must be a sqaure and have a size of at least 
4x4.
** Post-Conditions: Each room can only contain at most one event and one player. Some 
rooms will be empty.
*********************************************************************/
void Game::addEvents() {
    srand(time(NULL));
    int randomRow = rand() % this->size;
    int randomColumn = rand() % this->size;
    Event* wumpus = new Wumpus();
    caveGrid[randomRow][randomColumn].set_event(wumpus); //add Wumpus to random room
    while (caveGrid[randomRow][randomColumn].get_event() != NULL) { //if room already has an event, randomize event for an empty room
        randomRow = rand() % this->size;
        randomColumn = rand() % this->size;
        if (caveGrid[randomRow][randomColumn].get_event() == NULL) { //if room does not have an event, exit the while loop
            break;
        }
    }
    Event* bats1 = new Bats();
    caveGrid[randomRow][randomColumn].set_event(bats1); //add first bat to random room
    while (caveGrid[randomRow][randomColumn].get_event() != NULL) { //if room already has an event, randomize event for an empty room
        randomRow = rand() % this->size;
        randomColumn = rand() % this->size;
        if (caveGrid[randomRow][randomColumn].get_event() == NULL) { //if room does not have an event, exit the while loop
            break;
        }
    }
    Event* bats2 = new Bats();
    caveGrid[randomRow][randomColumn].set_event(bats2); //add second bat to random room
    while (caveGrid[randomRow][randomColumn].get_event() != NULL) { //if room already has an event, randomize event for an empty room
        randomRow = rand() % this->size;
        randomColumn = rand() % this->size;
        if (caveGrid[randomRow][randomColumn].get_event() == NULL) { //if room does not have an event, exit the while loop
            break;
        }
    }
    Event* pit1 = new Pit();
    caveGrid[randomRow][randomColumn].set_event(pit1); //add first pit to random room
    while (caveGrid[randomRow][randomColumn].get_event() != NULL) { //if room already has an event, randomize event for an empty room
        randomRow = rand() % this->size;
        randomColumn = rand() % this->size;
        if (caveGrid[randomRow][randomColumn].get_event() == NULL) { //if room does not have an event, exit the while loop
            break;
        }
    }
    Event* pit2 = new Pit();
    caveGrid[randomRow][randomColumn].set_event(pit2); //add second pit to random room
    while (caveGrid[randomRow][randomColumn].get_event() != NULL) { //if room already has an event, randomize event for an empty room
        randomRow = rand() % this->size;
        randomColumn = rand() % this->size;
        if (caveGrid[randomRow][randomColumn].get_event() == NULL) { //if room does not have an event, exit the while loop
            break;
        }
    }
    Event* gold = new Gold();
    caveGrid[randomRow][randomColumn].set_event(gold); //add gold to random room
    while (caveGrid[randomRow][randomColumn].get_event() != NULL) { //if room already has an event, randomize event for an empty room
        randomRow = rand() % this->size;
        randomColumn = rand() % this->size;
        if (caveGrid[randomRow][randomColumn].get_event() == NULL) { //if room does not have an event, exit the while loop
            break;
        }
    }
    // Player* player = new Player();
    this->player = new Player();
    caveGrid[randomRow][randomColumn].set_player(this->player); //add player to random room
    this->playerRow = randomRow;
    this->playerColumn = randomColumn;
    this->playerStartRow = randomRow;
    this->playerStartColumn = randomColumn;
}

/*********************************************************************
** Function: void Game::displayGrid()
** Description: Prints the grid (array of rooms) in the terminal.
** Parameters: None
** Pre-Conditions: The grid must be a square and have a size of at least 4x4.
** Post-Conditions: Some rooms will have one letter representing the event, while 
some rooms won't have any letters, which means that there are no events in those rooms. 
The player will start in a room without an event.
*********************************************************************/
void Game::displayGrid() {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            cout << " | ";
            if (caveGrid.at(i).at(j).get_event() != NULL) {
            // if (caveGrid.at(i).at(j).get_event()) {
                // cout << "Row: " << caveGrid.size() << endl;
                // cout << "Col: " << caveGrid.at(0).size() << endl;
                //cout << caveGrid[i][j].get_event()->character();
                cout << caveGrid.at(i).at(j).get_event()->character(); //display the characters of events in the grid
            }
            // else {
            //     cout << " ";
            // }
            if (caveGrid.at(i).at(j).get_player() != NULL) {
                cout << caveGrid.at(i).at(j).get_player()->character(); //display the character for the player (*) in the grid
            }
        }
        cout << endl;
    }
}

/*********************************************************************
** Function: void Game::moveOrFire()
** Description: The player will be able to move or fire an arrow in four directions: 
north, west, south, or east.
** Parameters: None
** Pre-Conditions: The player can only move within the grid (in other words, they can't 
go out of bounds). When firing an arrow, the arrow can only travel up to three rooms in 
one direction.
** Post-Conditions: The player will move to an adjacent room or the number of arrows that they 
have will decrease by one. If the arrow enters the Wumpus' room, the Wumpus will be killed.
*********************************************************************/
void Game::moveOrFire() {
    do {
        cout << "Press w, a, s, or d to move. If you want to fire an arrow, press ww, aa, ss, or dd." << endl;
        cout << "You have " << player->get_numOfArrows() << " arrows remaining." << endl;
        string direction;
        cout << "Which way do you want to move or fire an arrow? ";
        cin >> direction;
        if (direction == "w") { //move up
            if (this->playerRow == 0) {
                cout << "You can't move up. Pick a different direction." << endl;
                moveOrFire();
            }
            else {
                caveGrid.at(this->playerRow).at(this->playerColumn).set_player(NULL);
                this->playerRow = this->playerRow - 1;
                caveGrid.at(this->playerRow).at(this->playerColumn).set_player(player);
                displayGrid();
                cout << "You are at " << this->playerRow << ", " << this->playerColumn << endl;
            }
        }
        if (direction == "s") { //move down
            if (this->playerRow == this->size - 1) {
                cout << "You can't move down. Pick a different direction." << endl;
                moveOrFire();
            }
            else {
                caveGrid.at(this->playerRow).at(this->playerColumn).set_player(NULL);
                this->playerRow = this->playerRow + 1;
                caveGrid.at(this->playerRow).at(this->playerColumn).set_player(player);
                displayGrid();
                cout << "You are at " << this->playerRow << ", " << this->playerColumn << endl;
            }
        }
        if (direction == "a") { //move left
            if (this->playerColumn == 0) {
                cout << "You can't move left. Pick a different direction." << endl;
                moveOrFire();
            }
            else {
                caveGrid.at(this->playerRow).at(this->playerColumn).set_player(NULL);
                this->playerColumn = this->playerColumn - 1;
                caveGrid.at(this->playerRow).at(this->playerColumn).set_player(player);
                displayGrid();
                cout << "You are at " << this->playerRow << ", " << this->playerColumn << endl;
            }
        }
        if (direction == "d") { //move right
            if (this->playerColumn == this->size - 1) {
                cout << "You can't move right. Pick a different direction." << endl;
                moveOrFire();
            }
            else {
                caveGrid.at(this->playerRow).at(this->playerColumn).set_player(NULL);
                this->playerColumn = this->playerColumn + 1;
                caveGrid.at(this->playerRow).at(this->playerColumn).set_player(player);
                displayGrid();
                cout << "You are at " << this->playerRow << ", " << this->playerColumn << endl;
            }
        }
        if (player->get_numOfArrows() > 0) { //if there are arrows left
            if (direction == "ww") { //fire an arrow north
                cout << "You fire an arrow north." << endl;
                for (int i = 1; i < 4; i++) { //arrow can't travel more than 3 rooms
                    if (this->playerRow - i >= 0) {
                        if (caveGrid.at(this->playerRow - i).at(this->playerColumn).get_event() != NULL) {
                            if (caveGrid.at(this->playerRow - i).at(this->playerColumn).get_event()->character() == 'W') { //if arrow goes through Wumpus' room
                                player->set_wumpusDied(true);
                            }
                        }
                    }
                }
                if (!(player->get_wumpusDied())) { //if Wumpus didn't die after arrow has been released (in other words, arrow missed Wumpus)
                    wumpusMove();
                }
                player->decreaseNumOfArrows();
                displayGrid();
            }
            if (direction == "ss") { //fire an arrow south
                cout << "You fire an arrow south." << endl;
                for (int i = 1; i < 4; i++) { //arrow can't travel more than 3 rooms
                    if (this->playerRow + i < this->size) {
                        if (caveGrid.at(this->playerRow + i).at(this->playerColumn).get_event() != NULL) {
                            if (caveGrid.at(this->playerRow + i).at(this->playerColumn).get_event()->character() == 'W') { //if arrow goes through Wumpus' room
                                player->set_wumpusDied(true);
                            }
                        }
                    }
                }
                if (!(player->get_wumpusDied())) { //if Wumpus didn't die after arrow has been released (in other words, arrow missed Wumpus)
                    wumpusMove();
                }
                player->decreaseNumOfArrows();
                displayGrid();
            }
            if (direction == "aa") { //fire an arrow west
                cout << "You fire an arrow west." << endl;
                for (int i = 1; i < 4; i++) { //arrow can't travel more than 3 rooms
                    if (this->playerColumn - i >= 0) {
                        if (caveGrid.at(this->playerRow).at(this->playerColumn - i).get_event() != NULL) {
                            if (caveGrid.at(this->playerRow).at(this->playerColumn - i).get_event()->character() == 'W') { //if arrow goes through Wumpus' room
                                player->set_wumpusDied(true);
                            }
                        }
                    }
                }
                if (!(player->get_wumpusDied())) { //if Wumpus didn't die after arrow has been released (in other words, arrow missed Wumpus)
                    wumpusMove();
                }
                player->decreaseNumOfArrows();
                displayGrid();
            }
            if (direction == "dd") { //fire an arrow east
                cout << "You fire an arrow east." << endl;
                for (int i = 1; i < 4; i++) { //arrow can't travel more than 3 rooms
                    if (this->playerColumn + i < this->size) {
                        if (caveGrid.at(this->playerRow).at(this->playerColumn + i).get_event() != NULL) {
                            if (caveGrid.at(this->playerRow).at(this->playerColumn + i).get_event()->character() == 'W') { //if arrow goes through Wumpus' room
                                player->set_wumpusDied(true);
                            }
                        }
                    }
                }
                if (!(player->get_wumpusDied())) { //if Wumpus didn't die after arrow has been released (in other words, arrow missed Wumpus)
                    wumpusMove();
                }
                player->decreaseNumOfArrows();
                displayGrid();
            }
        }
        cout << "Is Wumpus dead? 0 = no, 1 = yes: " << player->get_wumpusDied() << endl;
        cout << "Has gold been picked up yet? 0 = no, 1 = yes: " << player->get_hasGold() << endl;
        if (player->get_wumpusDied() && player->get_hasGold()) { //if the player killed the Wumpus and they have the gold
            if ((this->playerRow == this->playerStartRow) && (this->playerColumn == this->playerStartColumn)) { //if the player is at their starting point
                this->playerHasWon = true; //player wins
                playerWins();
            }
        }
        printMessages();
        inEventRoom();
    }
    while ((this->gameOver == false) && (this->playerHasWon == false));
}

/*********************************************************************
** Function: void Game::wumpusMove()
** Description: There is a 75% chance that the Wumpus will move to a different room (without 
events) if the player fires an arrow and misses the Wumpus.
** Parameters: None
** Pre-Conditions: The arrow must miss the Wumpus.
** Post-Conditions: The Wumpus will move to a different room (without events, but could be in 
the same room that the player is in), or the Wumpus will stay where he currently is.
*********************************************************************/
void Game::wumpusMove() {
    srand(time(NULL));
    int randomNumber = rand() % 4 + 1;
    if (randomNumber <= 3) { //75% chance Wumpus moves after arrow misses the monster
        cout << "The Wumpus heard your arrow. He is now in a different room." << endl;
        for (int i = 0; i < this->size; i++) {
            for (int j = 0; j < this->size; j++) {
                if (caveGrid.at(i).at(j).get_event() != NULL) {
                    if (caveGrid.at(i).at(j).get_event()->character() == 'W') {
                        caveGrid.at(i).at(j).set_event(NULL); //delete the Wumpus at the old location
                    }
                }
            }
        }
        Event* wumpus = new Wumpus(); //add a new Wumpus
        int randomRow = rand() % this->size;
        int randomColumn = rand() % this->size;
        while (caveGrid[randomRow][randomColumn].get_event() != NULL) { //if room already has an event, add Wumpus in a different room
            randomRow = rand() % this->size;
            randomColumn = rand() % this->size;
            if (caveGrid[randomRow][randomColumn].get_event() == NULL) {
                if (caveGrid[randomRow][randomColumn].get_player() == NULL)  {
                    break; //if room doesn't have an event or player, exit the while loop
                }
            }
        }
        caveGrid[randomRow][randomColumn].set_event(wumpus); //add the Wumpus to the new location, which is a random empty room
    }
    else { //25% chance Wumpus will not move after an arrow has been fired
        cout << "The Wumpus didn't hear your arrow, and stayed where he was." << endl;
    }
}

/*********************************************************************
** Function: void Game::printMessages()
** Description: If the player is adjacent to a room with an event, a message will print out 
in the terminal depending on the event. It is possible for multiple messages to be printed 
in the terminal at once.
** Parameters: None
** Pre-Conditions: The player must be adjacent to a room with an event.
** Post-Conditions: Depending on the event, a message will be printed in the terminal.
*********************************************************************/
void Game::printMessages() {
    if (this->playerRow != 0) { //event to the north
        if (caveGrid.at(this->playerRow - 1).at(this->playerColumn).get_event() != NULL) {
            caveGrid.at(this->playerRow - 1).at(this->playerColumn).get_event()->message();
        }
    }
    if (this->playerRow != this->size - 1) { //event to the south
        if (caveGrid.at(this->playerRow + 1).at(this->playerColumn).get_event() != NULL) {
            caveGrid.at(this->playerRow + 1).at(this->playerColumn).get_event()->message();
        }
    }
    if (this->playerColumn != 0) { //event to the west
        if (caveGrid.at(this->playerRow).at(this->playerColumn - 1).get_event() != NULL) {
            caveGrid.at(this->playerRow).at(this->playerColumn - 1).get_event()->message();
        }
    }
    if (this->playerColumn != this->size - 1) { //event to the east
        if (caveGrid.at(this->playerRow).at(this->playerColumn + 1).get_event() != NULL) {
            caveGrid.at(this->playerRow).at(this->playerColumn + 1).get_event()->message();
        }
    }
}

/*********************************************************************
** Function: void Game::inEventRoom()
** Description: If the player is in a room with an event, different things will happen depending 
on the event.
** Parameters: None
** Pre-Conditions: The player must be in a room with an event.
** Post-Conditions: Something good or bad will happen to the player.
*********************************************************************/
void Game::inEventRoom() {
    srand(time(NULL));
    if (caveGrid.at(this->playerRow).at(this->playerColumn).get_event() != NULL) {
        if (caveGrid.at(this->playerRow).at(this->playerColumn).get_event()->character() == 'W') { //enter a room with Wumpus
            if (!(player->get_wumpusDied())) { //if Wumpus is alive
                caveGrid.at(this->playerRow).at(this->playerColumn).get_event()->inThisRoom();
                this->gameOver = true; //player loses
                gameIsOver();
            }
        }
        if (caveGrid.at(this->playerRow).at(this->playerColumn).get_event()->character() == 'P') { //enter a room with pit
            caveGrid.at(this->playerRow).at(this->playerColumn).get_event()->inThisRoom();
            this->gameOver = true; //player loses
            gameIsOver();
        }
        if (caveGrid.at(this->playerRow).at(this->playerColumn).get_event()->character() == 'G') { //enter a room with gold
            if (!(player->get_hasGold())) { //if gold hasn't been picked up yet
                caveGrid.at(this->playerRow).at(this->playerColumn).get_event()->inThisRoom();
                player->set_hasGold(true); //player has gold now
            }
        }
        if (caveGrid.at(this->playerRow).at(this->playerColumn).get_event()->character() == 'B') { //enter a room with bats
            caveGrid.at(this->playerRow).at(this->playerColumn).get_event()->inThisRoom();
            caveGrid.at(this->playerRow).at(this->playerColumn).set_player(NULL);
            int randomRow = rand() % this->size;
            int randomColumn = rand() % this->size;
            this->playerRow = randomRow;
            this->playerColumn = randomColumn;
            caveGrid.at(this->playerRow).at(this->playerColumn).set_player(player); //player gets carried away to a random room
            displayGrid();
            cout << "You are at " << this->playerRow << ", " << this->playerColumn << endl;
        }
    }
}

/*********************************************************************
** Function: void Game::playerWins()
** Description: The player has won, and will be asked if they want to play again.
** Parameters: None
** Pre-Conditions: The player must have killed the Wumpus, collected the gold, and made it back to 
their starting position.
** Post-Conditions: The terminal will print a message congratulating the player, and the player will 
be asked if they want to play again.
*********************************************************************/
void Game::playerWins() {
    cout << "Congratulations! You won!" << endl; //winning message
    return;
}

/*********************************************************************
** Function: void Game::gameIsOver()
** Description: The player has lost, and will be asked if they want to play again.
** Parameters: None
** Pre-Conditions: The player fell into a pit or got eaten by the Wumpus.
** Post-Conditions: The terminal will print a message telling the player "Game over," and the player 
will be asked if they want to play again.
*********************************************************************/
void Game::gameIsOver() {
    cout << "Game over!" << endl; //losing message
    return;
}

/*********************************************************************
The addEvents(), moveOrFire(), and inEventRoom() functions have more than 15 lines because I had to take 
into account many different situations. In addEvents(), I had to add a Wumpus, two bats, two pits, the gold 
room, and the player. I also had to make sure that I randomize the row and column after every event is added 
because no room can have two events or more. In moveOrFire(), I need to write the code for 8 moves: move west, 
north, east, or south, as well as fire an arrow in the west, north, east, or south direction. In addition, in 
moveOrFire(), I need to make sure what happens if the arrow hits or misses the Wumpus, what if the player is on 
the edge of the grid (can't go out of bounds), and set the previous location of the player to be NULL because 
the player isn't in the previous room anymore. In inEventRoom(), what made the function somewhat long was what 
happens if the player enters a room with bats: the previous location of the player needs to be set to NULL, the 
new location of the player requires the rand() function, and the player needs to be transported to another empty room. 
There are four different types of events (pit, gold, Wumpus, and bats), so that also made the inEventRoom() function 
a little bit lengthy. Thus, because of the reasons stated above, the addEvents(), moveOrFire(), and inEventRoom() 
functions have more than 15 lines.
*********************************************************************/

/*********************************************************************
I have a destructor in the Game class because I have to delete the player after the game to prevent memory leaks. I 
also have a destructor in the Room class because I have to delete events after the game to prevent memory leaks. I didn't 
use a copy constructor or AOO function because I didn't need to; I already have no memory leaks after running my program. 
I do have accessors and mutators because these functions are public, and I need to access them to get important information 
(for example, the character of an event and whether or not the player has the gold). I can also use mutators to set important 
information (for example, set the Wumpus to be dead if an arrow goes through his room). I didn't use const because I didn't 
need to; the program runs really well without memory leaks or errors.
*********************************************************************/