/******************************************************
** Program: driver.cpp
** Author: Harry Yu
** Date: 11/6/2022
** Description: This game simulates a game of Go Fish using standard rules (52 cards, 
13 ranks, and 4 suits). Each player takes turns, and in the end, the player with the 
most books (4 suits of the same rank) wins.
** Input: After the game, the user will be asked if they want to play again or not. 
If they want to play again, they should type "yes."
** Output: If they type "yes," then they will play another game of Go Fish. If they 
type anything other than "yes," then the program will exit.
******************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "game.h"
using namespace std;

/*********************************************************************
** Function: int main()
** Description: This function helps the game of Go Fish execute. At the end of the game, 
the user will be asked if they wanted to play again.
** Parameters: None
** Pre-Conditions: playAgain must be a string of whether or not the user wants to play again.
** Post-Conditions: 7 cards will be dealt to each player and the game will begin with player 1 
asking player 2 for a rank. If the user wants to play again, a new game will be generated. If the 
user doesn't want to play again, the program will exit.
*********************************************************************/
int main() {
    string playAgain = "yes";
    do {
        srand(time(0));
        cout << "Full deck: ";
        cout << endl;
        Game g;
        g.dealCard();
        g.askPlayer2ForRank();
        g.askPlayer1ForRank();
        string playAgain;
        cout << "Do you want to play again? If yes, type 'yes.' ";
        cin >> playAgain;
        cout << " " << endl;
        if (playAgain != "yes") {
            return 0;
        }
    }
    while (playAgain == "yes");
}