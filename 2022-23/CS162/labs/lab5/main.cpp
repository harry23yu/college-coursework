#include <iostream>
#include <string.h>
#include "card.h"

using namespace std;

int main() {
    //default constructor
    Card card_1;
    cout << card_1.map_rank() << endl;
    card_1.set_rank(5);
    cout << card_1.map_rank() << endl;

    //non-default constructor
    Card card_2(3, 2);
    cout << card_2.map_rank() << ", " << card_2.map_suit() << endl;
    Card card_3(12, 2);
    cout << card_3.map_rank() << ", " << card_3.map_suit() << endl;

    return 0;
}

/*****************************************************************
Classes have different objects in them. For example, in this assignment, 
the Card class has a rank and a suit, because cards can range from aces 
to kings, and they can be a club, diamond, heart, or spade. The Deck class 
has 52 cards at first, and then the number of cards will decrease as the 
game goes on. The Hand class has an array of cards in the hand and the number 
of cards in the hand. The Player class has a hand that belongs to the player, 
the number of books, and the array with ranks for which the player has books. 
The Game class has a deck and 2 players, which represents the state of an 
entire game. I will put all of my classes in the header file.
****************************************************************/