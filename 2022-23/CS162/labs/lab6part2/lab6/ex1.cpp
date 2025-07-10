#include <fstream>

#include "ex1.h"

using namespace std;

//allocate an array of cars
Car* create_cars(int size) {
	Car* ptr = new Car[size];
	//return new Car [size];
	return ptr;
}

//populate a single car object
void populate_car (Car& c, ifstream& fin) {
	fin >> c.brand >> c.num_passenger;
}

//populate the garage object
void populate_garage(Garage& g, ifstream& fin){
	
	//loop through number of cars
	for (int i = 0; i < g.num_cars; ++i)
	{
		populate_car(g.car_arr[i], fin);
	}
}

//delete function to free memory allocated in g
void delete_garage(Garage& g){
	delete [] g.car_arr;
	g.car_arr = NULL;
}