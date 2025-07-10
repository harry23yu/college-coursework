#include <iostream>
#include <string>
#include "card.h"
#include "deck.h"
using namespace std;

Deck::Deck() { //default constructor
    int i = 0;
    this->n_cards = 52; //52 cards in the deck at the beginning of game
    for(int j = 0; j < 13; j++) {
        for(int k = 0; k < 4; k++) {
            cards[i].set_rank(j);
            cards[i].set_suit(k);
            i++;
        }
    }
    for(int i = 0; i < 52; i++) {
        int m = i + (rand() % (52 - i));
        swap(cards[i], cards[m]);
        cards[i].print_card();
    }
    cout << endl;
}

Card Deck::drawCardFromDeck() {
    Card tempCards = this->cards[n_cards];
    this->n_cards = this->n_cards-1;
    this->cards[n_cards].print_card();
    return tempCards;
}

Card Deck::get_cards() { //accessor
    return this->cards[n_cards];
}

int Deck::get_n_cards() { //accessor
    return this->n_cards;
}

void Deck::set_cards(Card new_cards) { //mutator
    this->cards[n_cards] = new_cards;
}

void Deck::set_n_cards(int new_n_cards) { //mutator
    this->n_cards = new_n_cards;
}