/******************************************************
** Program: run_pokemon.cpp
** Author: Harry Yu
** Date: 10/23/2022
** Description: The user will be able to search through a Pokemon
encyclopedia using three different ways: dex number, name, and type. The 
user can also choose to add new pokemon to the encyclopedia.
** Input: At the very beginning, the user will type the name of an 
existing file that contains Pokemon information. After the program starts, 
the user will choose which way they want to search (for example, type 1 
for "search by dex number," type 2 for "search by name," etc.). The user 
can also choose to quit.
** Output: If the user wants to search by dex number or name, then
the program should print out the Pokemon's information (name, type, 
number of moves, etc.). If the user wants to search by type, then it
should print out the information for all Pokemon with that type. If
the user wants to add Pokemon, then it should prompt the user to enter
information about the Pokemon. If the user chooses to quit, then the
program should exit.
******************************************************/

#include "pokemon.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*********************************************************************
** Function: int main()
** Description: Asks user for file name. If it doesn't exist, the program will 
exit. If it exists, the user can choose how they want to search the Pokemon, or 
if they want to add new Pokemon.
** Parameters: None
** Pre-Conditions: The variable "method" must be an integer.
** Post-Conditions: If the user chooses 1, 2, or 3 for "method," then they can 
search for Pokemon. If the user chooses 4, then they can add Pokemon. If the user 
chooses 5, then the program must exit.
*********************************************************************/
int main() {
    cout << "Welcome to the CS 162 Pokedex! Please type file name: "; //ask user for file name
    string nameOfFile;
    cin >> nameOfFile;
    cout << endl;
    ifstream inputFile; //input file stream: inputFile
    int method = 1;
    while (method != 5) {
        inputFile.open(nameOfFile.c_str());
        if (!(inputFile.is_open())) { //if file name doesn't exist
            cout << "Error opening file." << endl;
            return 0;
        }
        else { //if file name exists
            cout << "How would you like to search Pokemon today?" << endl << endl;
            cout << "Press 1 for search by dex number. 2 for search by name. 3 for search by type. 4 for add new Pokemon into the list. 5 if you want to quit. ";
            cin >> method;
            int numOfPokemon;
            inputFile >> numOfPokemon; //prints number of Pokemon into the file
            Pokedex pokedex;
            pokedex.num_pokemon = numOfPokemon;
            pokedex.dex = create_pokemons(numOfPokemon); //creates an array of Pokemon
            populate_pokedex_data(pokedex, inputFile);

            if (method == 1) {
                ofstream outputFile;
                outputPokemonByDexNumber(pokedex, numOfPokemon, outputFile);
            }
            if (method == 2) {
                ofstream outputFile;
                outputPokemonByName(pokedex, numOfPokemon, outputFile);
            }
            if (method == 3) {
                ofstream outputFile;
                outputPokemonByType(pokedex, numOfPokemon, outputFile);
            }
            if (method == 4) {
                ofstream outputFile;
                addPokemon(pokedex, outputFile);
            }

            inputFile.close();
            delete_info(pokedex); //delete array so there are no memory leaks
        }
    }

    return 0;
}

/*********************************************************************
The main function has over 15 lines because I have to take into account many scenarios. For 
example, I have to first check to see if the file exists or not. Then, I need print the number 
of Pokemon into the file and create an array of Pokemon. Finally, I have to use four if statements 
to allow the user to search Pokemon by dex number, name, or type, or to add new Pokemon to the 
Pokedex.
*********************************************************************/