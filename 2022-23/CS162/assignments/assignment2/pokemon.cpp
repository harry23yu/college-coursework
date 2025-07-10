/******************************************************
** Program: pokemon.cpp
** Author: Harry Yu
** Date: 10/23/2022
** Description: The user will can choose if they want the Pokemon info
to be printed in the terminal or in a file. If a Pokemon exists, then the
info for that Pokemon will be printed. If a Pokemon doesn't exist, then
an error message will be printed out and the user have to try again to 
find a matching Pokemon.
** Input: The user can choose 1 to print it on the terminal or 2 to print
it into a file. When adding Pokemon, the user will fill in the dex number, 
name, type, number of moves, and name of all moves.
** Output: If the user chooses to search a Pokemon by dex number, name, or
type, then the matching Pokemon(s) will be printed onto the terminal or into 
a file, if the Pokemon(s) exist. If the Pokemon doesn't exist, then an error
message will be printed and the user must enter a dex number, name, or type 
of a Pokemon that exists. When adding Pokemon, the new Pokemon will be displayed 
in the terminal or in pokedex.txt, based on the user input for dex number, 
name, type, etc. 
******************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include "pokemon.h"
using namespace std;

/*********************************************************************
** Function: Pokemon* create_pokemons(int numOfPokemon)
** Description: A dynamic array will be created to hold the Pokemon 
of the requested size.
** Parameters: numOfPokemon
** Pre-Conditions: numOfPokemon must be an integer.
** Post-Conditions: An array with the size numOfPokemon must be created.
*********************************************************************/
Pokemon* create_pokemons(int numOfPokemon) {
    Pokemon* ptr = new Pokemon[numOfPokemon];
    return ptr;
}

/*********************************************************************
** Function: void populate_pokedex_data(Pokedex &pokedex, ifstream &inputFile)
** Description: Pokemon information (dex number, name, type, etc.) will be 
filled into the Pokedex.
** Parameters: &pokedex, &inputFile
** Pre-Conditions: num_pokemon must be an integer and the file name must be exist.
** Post-Conditions: The Pokedex should contain information for every Pokemon.
*********************************************************************/
void populate_pokedex_data(Pokedex &pokedex, ifstream &inputFile) {
    for (int i = 0; i < pokedex.num_pokemon; i++) {
        populate_pokemon(pokedex.dex[i], inputFile);
    }
    cout << endl << endl;
}

/*********************************************************************
** Function: string* create_moves(int numOfMoves)
** Description: An array that stores all moves of the Pokemon will be created.
** Parameters: numOfMoves
** Pre-Conditions: numOfMoves must be an integer.
** Post-Conditions: Each Pokemon will have an array that is able to contain all 
of the their moves. The array should be dynamic because the number of moves depends 
for each Pokemon. 
*********************************************************************/
string* create_moves(int numOfMoves) {
    string* ptr2 = new string[numOfMoves];
    return ptr2;
}

/*********************************************************************
** Function: void populate_pokemon(Pokemon &pokemon, ifstream &inputFile)
** Description: The information (dex number, name, etc.) will be stored for 
a Pokemon.
** Parameters: &pokemon, &inputFile
** Pre-Conditions: pokemon.num_moves must be an integer.
** Post-Conditions: Information should be stored for a Pokemon. The moves should 
also be stored for a Pokemon, and depending on the Pokemon, it could be 1 move, 
2 moves, 3 moves, etc.
*********************************************************************/
void populate_pokemon(Pokemon &pokemon, ifstream &inputFile) {
    inputFile >> pokemon.dex_num;
    inputFile >> pokemon.name;
    inputFile >> pokemon.type;
    inputFile >> pokemon.num_moves;
    pokemon.moves = create_moves(pokemon.num_moves);
    for (int j = 0; j < pokemon.num_moves; j++) {
        inputFile >> pokemon.moves[j];
    }
}

/*********************************************************************
** Function: void outputPokemonByDexNumber(Pokedex& ptr, int numOfPokemon, ofstream &outputFile)
** Description: The Pokemon and its information with the matching dex number will be printed.
** Parameters: &ptr, numOfPokemon, &outputFile
** Pre-Conditions: numOfPokemon, dex_num, and wantInfo must be integers.
** Post-Conditions: If the user enters a dex number that matches a Pokemon's dex number, that 
Pokemon and its information will be printed either onto the terminal or in a file. If there 
is no matching dex number, then an error message will print out and the user have to search 
again.
*********************************************************************/
void outputPokemonByDexNumber(Pokedex& ptr, int numOfPokemon, ofstream &outputFile) {
    int wantInfo;
    cout << "How do you want to display or add the Pokemon info? Press 1 for output on screen. Press 2 for output in a file. ";
    cin >> wantInfo;
    int dex_num;
    bool pokemonFound = false;
    if (wantInfo == 1) { //if user wants to print in the terminal
        cout << "Enter dex number: ";
        cin >> dex_num;
        cout << endl;
        for (int i = 0; i < numOfPokemon; i++) {
            if (dex_num == ptr.dex[i].dex_num) {
                pokemonFound = true;
                cout << ptr.dex[i].dex_num << " " << ptr.dex[i].name << " " << ptr.dex[i].type << " " << ptr.dex[i].num_moves << endl;
                for (int j = 0; j < ptr.dex[i].num_moves; j++) {
                    cout << ptr.dex[i].moves[j] << " "; //prints out all moves for each Pokemon (each Pokemon has different number of moves)
                }
                cout << endl;
            }
        }
        if (pokemonFound == false) { //if no Pokemon is found
            cout << "No Pokemon found. Try again." << endl;
            outputPokemonByDexNumber(ptr, numOfPokemon, outputFile);
        }
    }
    if (wantInfo == 2) { //if user wants to print in a file
        string nameOfFile;
        cout << "Enter name of file: ";
        cin >> nameOfFile;
        outputFile.open(nameOfFile.c_str(), ios::app); //outputs Pokemon info to name of file
        cout << "Enter dex number: ";
        cin >> dex_num;
        for (int i = 0; i < numOfPokemon; i++) {
            if (dex_num == ptr.dex[i].dex_num) {
                pokemonFound = true;
                outputFile << ptr.dex[i].dex_num << " " << ptr.dex[i].name << " " << ptr.dex[i].type << " " << ptr.dex[i].num_moves << endl;
                for (int j = 0; j < ptr.dex[i].num_moves; j++) {
                    outputFile << ptr.dex[i].moves[j] << " ";
                }
                outputFile << endl;
            }
        }
        if (pokemonFound == false) { //if no Pokemon is found
            cout << "No Pokemon found. Try again." << endl;
            outputPokemonByDexNumber(ptr, numOfPokemon, outputFile);
        }
    }
}

/*********************************************************************
** Function: void outputPokemonByName(Pokedex& ptr, int numOfPokemon, ofstream &outputFile)
** Description: The Pokemon and its information with the matching name will be printed.
** Parameters: &ptr, numOfPokemon, &outputFile
** Pre-Conditions: numOfPokemon and wantInfo must be integers. The variable "name" must be a string.
** Post-Conditions: If the user enters a name that matches a Pokemon's name, that Pokemon and its 
information will be printed either onto the terminal or in a file. If there is no matching name, 
then an error message will print out and the user have to search again.
*********************************************************************/
void outputPokemonByName(Pokedex& ptr, int numOfPokemon, ofstream &outputFile) {
    int wantInfo;
    cout << "How do you want to display or add the Pokemon info? Press 1 for output on screen. Press 2 for output in a file. ";
    cin >> wantInfo;
    string name;
    bool pokemonFound = false;
    if (wantInfo == 1) { //if user wants to print on screen
        cout << "Enter Pokemon name: ";
        cin >> name;
        cout << endl;
        for (int i = 0; i < numOfPokemon; i++) {
            if (name == ptr.dex[i].name) {
                pokemonFound = true;
                cout << ptr.dex[i].dex_num << " " << ptr.dex[i].name << " " << ptr.dex[i].type << " " << ptr.dex[i].num_moves << endl;
                for (int j = 0; j < ptr.dex[i].num_moves; j++) {
                    cout << ptr.dex[i].moves[j] << " ";
                }
                cout << endl;
            }
        }
        if (pokemonFound == false) {
            cout << "No Pokemon found. Try again." << endl;
            outputPokemonByName(ptr, numOfPokemon, outputFile);
        }
    }
    if (wantInfo == 2) { //if user wants to print in a file
        string nameOfFile;
        cout << "Enter name of file: ";
        cin >> nameOfFile;
        outputFile.open(nameOfFile.c_str(), ios::app);
        cout << "Enter Pokemon name: ";
        cin >> name;
        for (int i = 0; i < numOfPokemon; i++) {
            if (name == ptr.dex[i].name) {
                pokemonFound = true;
                outputFile << ptr.dex[i].dex_num << " " << ptr.dex[i].name << " " << ptr.dex[i].type << " " << ptr.dex[i].num_moves << endl;
                for (int j = 0; j < ptr.dex[i].num_moves; j++) {
                    outputFile << ptr.dex[i].moves[j] << " ";
                }
                outputFile << endl;
            }
        }
        if (pokemonFound == false) {
            cout << "No Pokemon found. Try again." << endl;
            outputPokemonByName(ptr, numOfPokemon, outputFile);
        }
    }
}

/*********************************************************************
** Function: void outputPokemonByType(Pokedex& ptr, int numOfPokemon, ofstream &outputFile)
** Description: The Pokemon(s) and its/their information with the matching type will be printed.
** Parameters: &ptr, numOfPokemon, &outputFile
** Pre-Conditions: numOfPokemon and wantInfo must be integers. The variable "type" must be a string.
** Post-Conditions: If the user enters a type that matches at least one Pokemon's type, then all Pokemon 
with that type and the information will be printed either onto the terminal or in a file. If there is 
no matching type, then an error message will print out and the user have to search again.
*********************************************************************/
void outputPokemonByType(Pokedex& ptr, int numOfPokemon, ofstream &outputFile) {
    int wantInfo;
    cout << "How do you want to display or add the Pokemon info? Press 1 for output on screen. Press 2 for output in a file. ";
    cin >> wantInfo;
    string type;
    bool pokemonFound = false;
    if (wantInfo == 1) { //if user wants to print on screen
        cout << "Enter Pokemon type (make sure to capitalize!): ";
        cin >> type;
        cout << endl;
        for (int i = 0; i < numOfPokemon; i++) {
            if (type == ptr.dex[i].type) {
                pokemonFound = true;
                cout << ptr.dex[i].dex_num << " " << ptr.dex[i].name << " " << ptr.dex[i].type << " " << ptr.dex[i].num_moves << endl;
                for (int j = 0; j < ptr.dex[i].num_moves; j++) {
                    cout << ptr.dex[i].moves[j] << " ";
                }
                cout << endl;
            }
        }
        if (pokemonFound == false) {
            cout << "No Pokemon found. Try again." << endl;
            outputPokemonByType(ptr, numOfPokemon, outputFile);
        }
    }
    if (wantInfo == 2) { //if user wants to print in a file
        string nameOfFile;
        cout << "Enter name of file: ";
        cin >> nameOfFile;
        outputFile.open(nameOfFile.c_str(), ios::app);
        cout << "Enter Pokemon type (make sure to capitalize!): ";
        cin >> type;
        for (int i = 0; i < numOfPokemon; i++) {
            if (type == ptr.dex[i].type) {
                pokemonFound = true;
                outputFile << ptr.dex[i].dex_num << " " << ptr.dex[i].name << " " << ptr.dex[i].type << " " << ptr.dex[i].num_moves << endl;
                for (int j = 0; j < ptr.dex[i].num_moves; j++) {
                    outputFile << ptr.dex[i].moves[j] << " ";
                }
                outputFile << endl;
            }
        }
        if (pokemonFound == false) {
            cout << "No Pokemon found. Try again." << endl;
            outputPokemonByType(ptr, numOfPokemon, outputFile);
        }
    }
}

/*********************************************************************
** Function: void rewriteFile(Pokedex& ptr, Pokemon p)
** Description: The file pokedex.txt will be overwritten. All of the original Pokemon will be 
added along with the new Pokemon(s).
** Parameters: &ptr, p
** Pre-Conditions: pokedex.txt should contain Pokemon information that already exists. ptr.num_pokemon 
must be an integer.
** Post-Conditions: The number of Pokemon in pokedex.txt must be updated every time after a new Pokemon 
is created. All information for original Pokemon, as well as for new Pokemon, must be visible to the 
user.
*********************************************************************/
void rewriteFile(Pokedex& ptr, Pokemon p) {
    ofstream outputFile;
    outputFile.open("pokedex.txt", ios::out);
    outputFile << ptr.num_pokemon + 1 << endl; //number of Pokemon must be updated every time after a new Pokemon is created
    for (int i = 0; i < ptr.num_pokemon; i++) {
        outputFile << ptr.dex[i].dex_num << " " << ptr.dex[i].name << " " << ptr.dex[i].type << " " << ptr.dex[i].num_moves << endl;
        for (int j = 0; j < ptr.dex[i].num_moves; j++) {
            outputFile << ptr.dex[i].moves[j] << " ";
        }
        outputFile << endl;
    }
}

/*********************************************************************
** Function: void addPokemon(Pokedex& ptr, ofstream &outputFile)
** Description: The user will type in information for a new Pokemon. Then, the Pokemon and its 
information will be printed onto the terminal or into a file.
** Parameters: &ptr, &outputFile
** Pre-Conditions: wantInfo, dex_num, and num_moves must be integers. Variables "name," "type," and "moves" 
must be strings.
** Post-Conditions: After the user enters information for a new Pokemon, the information for that Pokemon 
should be printed onto the screen or into a file. As the number of Pokemon increases, the size of the 
Pokedex will also increase.
*********************************************************************/
void addPokemon(Pokedex& ptr, ofstream &outputFile) {
    int wantInfo;
    cout << "How do you want to display or add the Pokemon info? Press 1 for output on screen. Press 2 for output in a file. ";
    cin >> wantInfo;
    if (wantInfo == 1) { //if user wants to print on screen
        Pokemon p;
        cout << "Enter dex number: ";
        cin >> p.dex_num;
        cout << "Enter name: ";
        cin >> p.name;
        cout << "Enter type (make sure to capitalize!): ";
        cin >> p.type;
        cout << "Enter number of moves: ";
        cin >> p.num_moves;
        p.moves = new string[p.num_moves];
        for (int i = 0; i < p.num_moves; i++) {
            cout << "Enter move: ";
            cin >> p.moves[i];
        }
        cout << endl << p.dex_num << " " << p.name << " " << p.type << " " << p.num_moves << endl;
        for (int i = 0; i < p.num_moves; i++) {
            cout << p.moves[i] << " ";
        }
        cout << endl << endl;
        delete [] p.moves; //deletes the memory that was dynamically allocated
        p.moves = NULL;
    }
    if (wantInfo == 2) { //if user wants to print in a file
        Pokemon p;
        outputFile.open("pokedex.txt", ios::app);
        cout << "Enter dex number: ";
        cin >> p.dex_num;
        cout << "Enter name: ";
        cin >> p.name;
        cout << "Enter type (make sure to capitalize!): ";
        cin >> p.type;
        cout << "Enter number of moves: ";
        cin >> p.num_moves;
        p.moves = new string[p.num_moves];
        for (int i = 0; i < p.num_moves; i++) {
            cout << "Enter move: ";
            cin >> p.moves[i];
        }
        rewriteFile(ptr, p); //rewrites the file instead of adding the new Pokemon at the end of the file
        outputFile << p.dex_num << " " << p.name << " " << p.type << " " << p.num_moves << endl;
        for (int i = 0; i < p.num_moves; i++) {
            outputFile << p.moves[i] << " ";
        }
        delete [] p.moves; //deletes the memory that was dynamically allocated
        p.moves = NULL;
    }
}

/*********************************************************************
** Function: void delete_info(Pokedex &pokedex)
** Description: Deletes of the memory that was created from the arrays.
** Parameters: &pokedex
** Pre-Conditions: pokedex.num_pokemon must be an integer.
** Post-Conditions: There should be no memory leaks after the program has finished running.
*********************************************************************/
void delete_info(Pokedex &pokedex) {
    for (int i = 0; i < pokedex.num_pokemon; i++) {
        delete [] pokedex.dex[i].moves; //deletes all the memory that was dynamically allocated
    }
    delete [] pokedex.dex; //makes sure there are no memory leaks
}

/*********************************************************************
The output Pokemon by dex number, name, and type, as well as the add Pokemon functions, have more 
than 15 lines because I have to take many situations into account. First, I have to ask the user if 
they want to print the information on the terminal or in a file. I also need to check if such a Pokemon 
exists for searching by dex number, name, or type. Then, I have to print out the information for the Pokemon 
and use another for loop for the moves, because each Pokemon has a different number of moves. For the add 
Pokemon function, I have to ask the user for all information, such as name, type, and number of moves, which 
will make the function pretty long. Thus, because there are so many ways to print out a Pokemon, this is why 
these four functions have more than 15 lines.
*********************************************************************/