#include <iostream>
#include <fstream>

#include "ex1.h"

using namespace std;


int main(int argc, char const *argv[])
{
	//file stream object
	ifstream file;
	file.open("file.txt");


	//error opening the file
	if (!file.is_open()){
		cout << "Error opening the file!" << endl; 
		return 1;
	}

	//read info from file into Garage g
	Garage g;
	//file >> g.num_cars;
	int size;
	g.num_cars = size; //new line
	Car* car_arr = create_cars(g.num_cars); 

	populate_garage(g, file);

	delete_garage(g);

	return 0;
}