#include <iostream>
#include <string>
#include "player.h"
#include "game.h"
#include "hand.h"
using namespace std;

Game::Game() { //default constructor
    //Insert code here
}

void Game::addCardToPlayer() {
    cout << endl << "Player 1 cards: ";
    for (int i = 0; i < 7; i++) {
        this->d.drawCardFromDeck();
    }
    cout << endl << "Player 2 cards: ";
    for (int i = 0; i < 7; i++) {
        this->d.drawCardFromDeck();
    }
}

void Game::askPlayer2ForRank() {
    cout << "Player 1's turn. What rank do you want to ask Player 2? ";
    string requestRank;
    cin >> requestRank;
    for (int i = 0; i < players[0].get_hand().get_n_cards(); i++) {
        if (players[0].get_hand().get_cards()[i].map_rank() != requestRank) {
            cout << "Rank is not in your hand. Please enter another rank.";
        }
    }
}

void Game::askPlayer1ForRank() {
    cout << "Player 2's turn. What rank do you want to ask Player 1? ";
    string requestRank;
    cin >> requestRank;
    for (int i = 0; i < players[1].get_hand().get_n_cards(); i++) {
        if (players[1].get_hand().get_cards()[i].map_rank() != requestRank) {
            cout << "Rank is not in your hand. Please enter another rank.";
        }
    }
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