#include <iostream>
#include <string>
#include "hand.h"
#include "player.h"
using namespace std;

Player::Player() { //default constructor
    /*cout << "Player 1 cards: ";
    for(int i = 0; i < 7 ; i++) {
        hand.addCardToPlayer();
    }
    cout << "Player 2 cards: ";
    for(int i = 0; i < 7 ; i++) {
        hand.addCardToPlayer();
    }*/
}

Player::Player(int size) { //non-default constructor
    this->n_books = size;
    this->books = new int[size];
}

Player::~Player() { //destructor
    cout << "Destructor is called..." << endl;
	if (this->books != NULL) {
		delete [] this->books;
		this->books = NULL;
	}
}

Player& Player::operator=(const Player& p1){ //AOO
    cout << "Inside our AOO..." << endl;
	//member-wise copy
	//this->hand = p1.hand;
	this->n_books = p1.n_books; 

	//free the memory first 
	if (this->books != NULL) {
		delete [] this->books;
    }
	//deep copy
	this->books = new int [this->n_books];
	for (int i = 0; i < this->n_books; i++) {
		this->books[i] = p1.books[i];
	}
	return *this;
}

Player::Player(const Player& p1) { //copy constructor
	cout << "inside our CC..." << endl;
	//member-wise copy
	//this->hand = p1.hand;
	this->n_books = p1.n_books; 

	//deep copy
	this->books = new int [this->n_books];
	for (int i = 0; i < this->n_books; ++i)
	{
		this->books[i] = p1.books[i];
	}
}

Hand Player::get_hand() { //accessor
    return this->hand;
}

int* Player::get_books() { //accessor
    return this->books;
}

int Player::get_n_books() { //accessor
    return this->n_books;
}

void Player::set_hand(Hand new_hand) { //mutator
    this->hand = new_hand;
}

void Player::set_books(int* new_books) { //mutator
    this->books = new_books;
}

void Player::set_n_books(int new_n_books) { //mutator
    this->n_books = new_n_books;
}