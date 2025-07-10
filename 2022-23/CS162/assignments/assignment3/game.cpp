/******************************************************
** Program: game.cpp
** Author: Harry Yu
** Date: 11/6/2022
** Description: The Game class is where the action of Go Fish takes place. Player 1 (the human player) 
will ask Player 2 (the computer player) for a rank. Depending on the scneario, Player 1 can go again 
and continue to ask for ranks or their turn will end, resulting in a "Go Fish" scneario. In a "Go Fish" 
scenario, the player will draw a card from the deck and it will be the other player's turn. The players
continue to alternate turns until all of the books are laid down. At the end of the game, the player with 
the most books wins. The rank selected by the computer player is random.
** Input: For each player's turn, they will ask the other player for a rank.
** Output: If the other player doesn't have a rank, then the player must draw one card from the deck. If they 
have the rank, then the player will "steal" the card with the rank from the other player, and they get to go 
again. If a player asks for a rank but doesn't have it in their hand, an error message will print out and they 
have to choose their rank again.
******************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "game.h"
#include "hand.h"
using namespace std;

Game::Game() { //default constructor
    
}

Deck Game::get_d() { //accessor
    return this->d;
}

Player Game::get_players() { //accessor
    return this->players[2];
}

void Game::set_d(Deck new_d) { //mutator
    this->d = new_d;
}

void Game::set_players(Player new_players) { //mutator
    this->players[2] = new_players;
}

/*********************************************************************
** Function: void Game::dealCard()
** Description: Deals 7 cards to both players.
** Parameters: None
** Pre-Conditions: Both players should have 0 cards at the very beginning.
** Post-Conditions: Both players should now have 7 cards, and the game will begin.
*********************************************************************/
void Game::dealCard() {
    cout << "Player 1 cards: ";
    for (int i = 0; i < 7; i++) { //deal 7 cards to player 1
        Card c = this->d.removeCard();
	    this->players[0].placeCard(c); //assign the card c to players[0]
        c.print_card();
    }
    cout << ", number of books in player 1: 0" << endl;
    cout << "Player 2 cards: ";
    for (int i = 0; i < 7; i++) { //deal 7 cards to player 2
        Card c = this->d.removeCard();
	    this->players[1].placeCard(c); //assign the card c to players[1]
        c.print_card();
    }
    cout << ", number of books in player 2: 0" << endl;
    cout << endl;
}

/*********************************************************************
** Function: void Game::askPlayer2ForRank()
** Description: Player 1 (the human player) asks player 2 (the computer player) for a rank.
** Parameters: None
** Pre-Conditions: Player 1 must have at least 1 card in their hand.
** Post-Conditions: If player 1 asks for a rank that they don't have in their hand, they have 
to choose a different rank. If they have a rank and the other player doesn't have it, they will 
draw a card from the deck in the "Go fish" scenario. If both players have the rank, then player 1 
will steal that card of that rank from player 2, and player 1 gets to go again until they get a 
"Go Fish." Also, when both players have a combined 13 books, the game is over.
*********************************************************************/
void Game::askPlayer2ForRank() {
    int rankBookRemoved;
    for (int i = 0; i < (players[0].get_hand().get_n_cards()) - 3; i++) { //checks to see if players[0] has any books (if yes, remove them)
        if (players[0].get_hand().get_cards()[i].map_rank() == players[0].get_hand().get_cards()[i+1].map_rank()) {
            if (players[0].get_hand().get_cards()[i].map_rank() == players[0].get_hand().get_cards()[i+2].map_rank()) {
                if (players[0].get_hand().get_cards()[i].map_rank() == players[0].get_hand().get_cards()[i+3].map_rank()) {
                    rankBookRemoved = players[0].get_hand().get_cards()[i].get_rank() + 1;
                    players[0].removeBook(rankBookRemoved);
                    cout << "Player 1 has " << players[0].get_n_books() << " books. Array of books: ";
                    for (int i = 0; i < players[0].get_n_books(); i++) { //print out the book array
                        cout << players[0].get_books()[i] << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
    if (players[0].get_n_books() + players[1].get_n_books() == 13) { //check to see if the game is over
        gameOver();
        return;
    }
    if (players[0].get_hand().get_n_cards() == 0) { //if player has no cards, they need to draw one from the stock
        cout << "Player 1 draws a card from the stock because they don't have any cards. Player 1's cards right now: ";
        Card c = this->d.removeCard();
	    this->players[0].placeCard(c); //assign the card c to players[0]
        c.print_card();
    }
    if (players[1].get_hand().get_n_cards() == 0) { //if opponent has no cards, they need to draw one from the stock
        cout << "Player 2 draws a card from the stock because they don't have any cards. Player 2's cards right now: ";
        Card c = this->d.removeCard();
	    this->players[1].placeCard(c); //assign the card c to players[1]
        c.print_card();
    }
    cout << endl << "Player 1's turn. What rank do you want to ask Player 2? ";
    bool rankFound = false;
    bool rankFoundInOpponent = false;
    string requestRank;
    cin >> requestRank;
    for (int i = 0; i < players[0].get_hand().get_n_cards(); i++) {
        if (requestRank == players[0].get_hand().get_cards()[i].map_rank()) {
            rankFound = true; //rank is in player's hand
        }
    }
    for (int i = 0; i < players[1].get_hand().get_n_cards(); i++) {
        if (requestRank == players[1].get_hand().get_cards()[i].map_rank()) {
            rankFoundInOpponent = true; //rank is in opponent's hand
        }
    }
    if (rankFound == false) { //must choose another rank because player doesn't have it in their hand
        cout << "Rank is not in your hand. Enter another rank." << endl;
        askPlayer2ForRank();
    }
    if (rankFound == true && rankFoundInOpponent == false) { //go fish scenario
        cout << "Player 2 says, Go Fish!" << endl;
        Card c = this->d.removeCard();
	    this->players[0].placeCard(c); //players[0] chooses one card from the stock
        for (int i = 0; i < (players[0].get_hand().get_n_cards()) - 3; i++) { //checks to see if players[0] has any books after drawing from stock
            if (players[0].get_hand().get_cards()[i].map_rank() == players[0].get_hand().get_cards()[i+1].map_rank()) {
                if (players[0].get_hand().get_cards()[i].map_rank() == players[0].get_hand().get_cards()[i+2].map_rank()) {
                    if (players[0].get_hand().get_cards()[i].map_rank() == players[0].get_hand().get_cards()[i+3].map_rank()) {
                        rankBookRemoved = players[0].get_hand().get_cards()[i].get_rank() + 1;
                        players[0].removeBook(rankBookRemoved);
                        cout << "Player 1 has " << players[0].get_n_books() << " books. Array of books: ";
                        for (int i = 0; i < players[0].get_n_books(); i++) { //print out array of books
                            cout << players[0].get_books()[i] << " ";
                        }
                        cout << endl;
                    }
                }
            }
        }
        cout << "Player 1 draws a card from the stock. Player 1's cards right now: ";
        for (int i = 0; i < players[0].get_hand().get_n_cards(); i++) {
            players[0].get_hand().get_cards()[i].print_card();
        }
        if (c.map_rank() == requestRank) { //if newly drawn card from stock has the rank the player originally asked
            askPlayer2ForRank(); //player gets to go again
        }
        cout << endl;
    }
    if (rankFound == true && rankFoundInOpponent == true) { //steal card from opponent scenario
        cout << "Player 2 gives all of cards with rank " << requestRank << " to player 1." << endl;
        for (int i = 0; i < players[1].get_hand().get_n_cards(); i++) {
            if (requestRank == players[1].get_hand().get_cards()[i].map_rank()) {
                Card c = players[1].get_hand().get_cards()[i];
                this->players[1].removeCard(requestRank); //remove from opponent's hand
                this->players[0].placeCard(c); //add to player's hand
            }
        }
        cout << "Player 1's cards right now: ";
        for (int i = 0; i < players[0].get_hand().get_n_cards(); i++) {
            players[0].get_hand().get_cards()[i].print_card(); //print out new array of cards in player
        }
        cout << endl << "Player 2's cards right now: ";
        for (int i = 0; i < players[1].get_hand().get_n_cards(); i++) {
            players[1].get_hand().get_cards()[i].print_card(); //print out new array of cards in opponent
        }
        cout << endl;
        askPlayer2ForRank();
    }
    cout << "Cards in deck: " << this->d.get_n_cards() << ", cards in P1: " << players[0].get_hand().get_n_cards() << ", cards in P2: " << players[1].get_hand().get_n_cards() << endl;
    askPlayer1ForRank(); //next player's turn
}

/*********************************************************************
** Function: void Game::askPlayer1ForRank()
** Description: Player 2 (the computer player) asks player 1 (the human player) for a rank.
** Parameters: None
** Pre-Conditions: Player 2 must have at least 1 card of that rank in their hand, because they 
choose a rank at random.
** Post-Conditions: If Player 2 have a rank and the other player doesn't have it, Player 2 will 
draw a card from the deck in the "Go fish" scenario. If both players have the rank, then player 2 
will steal that card of that rank from player 1, and player 2 gets to go again until they get a 
"Go Fish." Also, when both players have a combined 13 books, the game is over.
*********************************************************************/
void Game::askPlayer1ForRank() {
    int rankBookRemoved;
    for (int i = 0; i < (players[1].get_hand().get_n_cards()) - 3; i++) { //checks to see if players[1] has any books (if yes, remove them)
        if (players[1].get_hand().get_cards()[i].map_rank() == players[1].get_hand().get_cards()[i+1].map_rank()) {
            if (players[1].get_hand().get_cards()[i].map_rank() == players[1].get_hand().get_cards()[i+2].map_rank()) {
                if (players[1].get_hand().get_cards()[i].map_rank() == players[1].get_hand().get_cards()[i+3].map_rank()) {
                    rankBookRemoved = players[1].get_hand().get_cards()[i].get_rank() + 1;
                    players[1].removeBook(rankBookRemoved);
                    cout << "Player 2 has " << players[1].get_n_books() << " books. Array of books: ";
                    for (int i = 0; i < players[1].get_n_books(); i++) { //print out array of books
                        cout << players[1].get_books()[i] << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
    if (players[0].get_n_books() + players[1].get_n_books() == 13) { //check to see if the game is over
        gameOver();
        return;
    }
    if (players[1].get_hand().get_n_cards() == 0) { //if player has no cards, they need to draw one from the stock
        cout << "Player 2 draws a card from the stock because they don't have any cards. Player 2's cards right now: ";
        Card c = this->d.removeCard();
	    this->players[1].placeCard(c); //assign the card c to players[1]
        c.print_card();
    }
    if (players[0].get_hand().get_n_cards() == 0) { //if opponent has no cards, they need to draw one from the stock
        cout << "Player 1 draws a card from the stock because they don't have any cards. Player 1's cards right now: ";
        Card c = this->d.removeCard();
	    this->players[0].placeCard(c); //assign the card c to players[0]
        c.print_card();
    }
    int indexRequestRank = rand() % players[1].get_hand().get_n_cards();
    string requestRank = players[1].get_hand().get_cards()[indexRequestRank].map_rank(); //randomly select a rank to ask the human player
    cout << endl;
    cout << "Player 2's turn. Player 2 asks " << requestRank << " rank from player 1." << endl;
    bool rankFoundInOpponent = false;
    for (int i = 0; i < players[0].get_hand().get_n_cards(); i++) {
        if (requestRank == players[0].get_hand().get_cards()[i].map_rank()) {
            rankFoundInOpponent = true; //rank is in opponent's hand
        }
    }
    if (rankFoundInOpponent == false) { //go fish scenario
        cout << "Player 1 says, Go Fish!" << endl;
        Card c = this->d.removeCard();
	    this->players[1].placeCard(c); //players[1] chooses one card from the stock
        for (int i = 0; i < (players[1].get_hand().get_n_cards()) - 3; i++) { //checks to see if players[1] has any books after drawing from stock
            if (players[1].get_hand().get_cards()[i].map_rank() == players[1].get_hand().get_cards()[i+1].map_rank()) {
                if (players[1].get_hand().get_cards()[i].map_rank() == players[1].get_hand().get_cards()[i+2].map_rank()) {
                    if (players[1].get_hand().get_cards()[i].map_rank() == players[1].get_hand().get_cards()[i+3].map_rank()) {
                        rankBookRemoved = players[1].get_hand().get_cards()[i].get_rank() + 1;
                        players[1].removeBook(rankBookRemoved);
                        cout << "Player 2 has " << players[1].get_n_books() << " books. Array of books: ";
                        for (int i = 0; i < players[1].get_n_books(); i++) { //print out array of books
                            cout << players[1].get_books()[i] << " ";
                        }
                        cout << endl;
                    }
                }
            }
        }
        cout << "Player 2 draws a card from the stock. Player 2's cards right now: ";
        for (int i = 0; i < players[1].get_hand().get_n_cards(); i++) {
            players[1].get_hand().get_cards()[i].print_card();
        }
        if (c.map_rank() == requestRank) { //if newly drawn card from stock has the rank the player originally asked
            askPlayer1ForRank(); //player gets to go again
        }
        cout << endl;
    }
    if (rankFoundInOpponent == true) { //steal card from opponent scenario
        cout << "Player 1 gives all of cards with rank " << requestRank << " to player 2." << endl;
        for (int i = 0; i < players[0].get_hand().get_n_cards(); i++) {
            if (requestRank == players[0].get_hand().get_cards()[i].map_rank()) {
                Card c = players[0].get_hand().get_cards()[i];
                this->players[0].removeCard(requestRank); //remove from opponent's hand
                this->players[1].placeCard(c); //add to player's hand
            }
        }
        cout << "Player 2's cards right now: ";
        for (int i = 0; i < players[1].get_hand().get_n_cards(); i++) {
            players[1].get_hand().get_cards()[i].print_card(); //print out new array of cards in player
        }
        cout << endl;
        cout << "Player 1's cards right now: ";
        for (int i = 0; i < players[0].get_hand().get_n_cards(); i++) {
            players[0].get_hand().get_cards()[i].print_card(); //print out new array of cards in opponent
        }
        cout << endl;
        askPlayer1ForRank();
    }
    cout << "Cards in deck: " << this->d.get_n_cards() << ", cards in P1: " << players[0].get_hand().get_n_cards() << ", cards in P2: " << players[1].get_hand().get_n_cards() << endl;
    askPlayer2ForRank(); //next player's turn
}

/*********************************************************************
** Function: void Game::gameOver()
** Description: When the game is over, prints out the winner and ask if they want to play again.
** Parameters: None
** Pre-Conditions: Both players must have a combined 13 books.
** Post-Conditions: The winner should be correctly printed out and the user should be asked if 
they want to play again.
*********************************************************************/
void Game::gameOver() {
    if (players[0].get_n_books() > players[1].get_n_books()) {
        cout << "Thanks for playing! Player 1 is our winner!" << endl;
    }
    else {
        cout << "Thanks for playing! Player 2 is our winner!" << endl;
    }
    return;
}

/*******************************************************************************************
The Big Three is not necessary for the Game class because there is no dynamic memory. All a 
Game has is a deck of cards and two players. The number of cards in the deck can't be increased 
and there are only two players throuhgout the entire game. Thus, there is no dynamic memory in 
the Game class, which means the Big Three (destructor, CC, and AOO) are not required, as well 
as the Const keyword.

The Game class is at the "highest" hierachy. It consists of a deck and 2 players. No other classes 
contain a deck and 2 players, which is why these variables are private so that broken code can be 
avoided. Just like with all the other classes, accessors and mutators helps with changing or accessing 
private variables. They are crucial to encapsulation, which avoids broken code. 
*******************************************************************************************/

/*******************************************************************************************
Both askPlayer2ForRank() and askPlayer1ForRank() have more than 15 lines because there are many scenarios 
I have to take into account for. For example, what if there are no cards in either player's hand? Then they 
need to draw a card from the deck. Also, what if there are books at the beginning of a player's turn, or if they  
get a book after they drew a card from the stock after a "Go Fish" scenario? And I have to check if both players 
have a combined 13 books (indicating that game is over), which can happen on either turn. Furthermore, I need to check 
if the player has the requested rank in their hand; otherwise they have to choose a different rank. Then, I need to write 
both the "steal from opponent" and "go fish" situations, and print the cards in each player after each turn. There are a 
lot of if statements to check if something is true, and a lot of for loops to loop through the book array and the card 
array. A lot of statements need to be printed to make it clear what is going on, so there are a lot of cout statements. 
(Examples include printing player 1 cards, player 2 cards, player 1 asks rank from player 2, player 2 books, etc.) 
Because of those reasons, both functions mentioned above have more than 15 lines of code to satisfy all the scenarios.
*******************************************************************************************/