/******************************************************
** Program: player.cpp
** Author: Harry Yu
** Date: 11/6/2022
** Description: The Player class helps adding and removing cards from each player. It 
makes sure books can be removed from each player and keeps track of the array of books.
** Input: None
** Output: None
******************************************************/

#include <iostream>
#include <string>
#include "hand.h"
#include "player.h"
using namespace std;

Player::Player() { //default constructor
    this->n_books = 0;
	this->books = NULL;
}

Player::Player(int size) { //non-default constructor
    this->n_books = size;
    this->books = new int[size];
}

/*********************************************************************
** Function: Player::~Player()
** Description: It deletes the memory from the books array.
** Parameters: None
** Pre-Conditions: There should be at least one integer in the books array.
** Post-Conditions: There should be no memory leaks.
*********************************************************************/ 
Player::~Player() { //destructor
    //cout << "Destructor is called..." << endl;
	if (this->books != NULL) {
		delete [] this->books;
		this->books = NULL;
	}
}

/*********************************************************************
** Function: Player& Player::operator=(const Player& p1)
** Description: Copies the contents of the old books array to the new books array.
** Parameters: const Player& p1
** Pre-Conditions: There should be an array of books in the player's hand.
** Post-Conditions: The old array of books shouldn't be destroyed, and the rank of 
the new book should be added to the player's book array. Also, there shouldn't be any 
memory leaks.
*********************************************************************/ 
Player& Player::operator=(const Player& p1) { //AOO
    //cout << "Inside our AOO..." << endl;
	//member-wise copy
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

/*********************************************************************
** Function: Player::Player(const Player& p1)
** Description: Copies the contents of the old array to the new array.
** Parameters: const Player& p1
** Pre-Conditions: There player should have an array of books.
** Post-Conditions: The player's book array should now contain the rank of a new 
book, and there should be no memory leaks.
*********************************************************************/
Player::Player(const Player& p1) { //copy constructor
	//cout << "Inside our CC..." << endl;
	//member-wise copy
	this->n_books = p1.n_books; 

	//deep copy
	this->books = new int [this->n_books];
	for (int i = 0; i < this->n_books; ++i) {
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

/*********************************************************************
** Function: void Player::placeCard(Card& c)
** Description: Adds a card to the player's hand.
** Parameters: Card& c
** Pre-Conditions: The player should have an array of cards in their hand.
** Post-Conditions: The new card should be added to their hand, without affecting 
the old cards.
*********************************************************************/
void Player::placeCard(Card& c) {
	this->hand.addACard(c);
}

/*********************************************************************
** Function: void Player::removeCard(string requestRank)
** Description: The card(s) with the rank the opponent asked for gets removed 
from the player's hand.
** Parameters: string requestRank
** Pre-Conditions: The player should have at least one card of the rank that the 
opponent asked for.
** Post-Conditions: The card(s) with that rank should be removed from the player's hand, 
and transferred to the opponent.
*********************************************************************/
void Player::removeCard(string requestRank) {
	this->hand.removeACard(requestRank);
}

/*********************************************************************
** Function: void Player::removeBook(int rankBookRemoved)
** Description: Creates an array of the rank of the books that the player has.
** Parameters: int rankBookRemoved
** Pre-Conditions: The player should have at least one book.
** Post-Conditions: With each book being removed from the player, the rank of each 
of those books should be added to the array.
*********************************************************************/
void Player::removeBook(int rankBookRemoved) { //I got this idea from Roger's demo
	this->hand.removeABook();
	//this->n_books++;
	int* temp_arr = new int [this->n_books + 1]; //allocate an array of books with books + 1
	for (int i = 0; i < this->n_books; i++) { //copy the old array objects (books[i]) to new array (temp_arr[i])
		temp_arr[i] = this->books[i]; //AOO of books
	}
	temp_arr[this->n_books] = rankBookRemoved; //add the new book object rankBookRemoved, into index n_cards
	if (this->books != NULL) { //delete the old array using books
		delete [] this->books;
	}
	this->books = temp_arr; //set books to temp_arr
	this->n_books++; //increment the n_books
}

/*******************************************************************************************
I used the Big Three in the Player class because the Player class contain a int pointer to books, 
which stores the array of books for a player. As the game progresses, the number of books in each 
player will increase. Thus, dynamic memory exists in the Player class. Also, I have 
to prevent changes to the book array I'm copying data from. For example, if I have an array of books 
8 and 4, and then get a book 10, I have to copy the 8 and 4 over to the new array. Now my array of 
books is 8, 4, 10. This is why the CC, AOO, and the Const keyword are necessary. In order to make 
sure there are no memory leaks, a destructor must be called. Thus, the Big Three is required in the 
Player class.

As previously mentioned, if variables are private, then it helps avoid broken code by enforcing 
encapsulation. Accessors help the game know how many books are in each player and the array of 
books. Mutators help set the number of books and the array of books in each player. Just like private 
variables, mutators help with encapsulation.
*******************************************************************************************/