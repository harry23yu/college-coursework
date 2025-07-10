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

int main() {
    srand(time(0));
    cout << "Full deck: ";
    // Game gameOne;
    // gameOne.addCardToPlayer();
    cout << endl;
    Player p1(10);
    Player p2(5);
    p2 = p1; //AOO
    Player p3(p2); //copy constructor
    //gameOne.askPlayer2ForRank();
    //gameOne.askPlayer1ForRank();
    return 0;
}