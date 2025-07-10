#ifndef GAME_H
#define GAME_H
using namespace std;

#include <iostream>
#include <string>

#include "player.h"
#include "deck.h"
#include "hand.h"

class Game {
    private:
        Deck d;
        Player players[2];
    public:
        //constructors
        Game();
        //destructor

        //accessors
        Deck get_d();
        Player get_players();
        //mutators
        void set_d(Deck);
        void set_players(Player);
        //other member functions
        void addCardToPlayer();
        void askPlayer2ForRank();
        void askPlayer1ForRank();
        void nextPlayerTurn();
        void isGameOver();
};

#endif