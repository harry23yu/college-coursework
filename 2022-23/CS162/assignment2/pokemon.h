/******************************************************
** Program: pokemon.h
** Author: Harry Yu
** Date: 10/23/2022
** Description: The list of all functions is here. Also, the structs are 
here, which list the attributes for each Pokemon, as well as the Pokedex.
** Input: None
** Output: None
******************************************************/

#ifndef POKEMON
#define POKEMON
#include <iostream>
using namespace std;

struct Pokemon {
    int dex_num;
    string name;
    string type;
    int num_moves;
    string* moves;
};

struct Pokedex {
    string trainer;
    int num_pokemon;
    Pokemon* dex;
};

Pokemon* create_pokemons(int numOfPokemon);
void populate_pokedex_data(Pokedex &pokedex, ifstream &inputFile);
string* create_moves(int numOfMoves);
void populate_pokemon(Pokemon &pokemon, ifstream &inputFile);
void outputPokemonByDexNumber(Pokedex&, int numOfPokemon, ofstream &outputFile);
void outputPokemonByName(Pokedex& ptr, int numOfPokemon, ofstream &outputFile);
void outputPokemonByType(Pokedex& ptr, int numOfPokemon, ofstream &outputFile);
void addPokemon(Pokedex& ptr, ofstream &outputFile);
void delete_info(Pokedex &pokedex);

#endif