#include "./vector.h"
#include <vector>
#include <iostream>
#include <string>

//We do NOT want to include either stmt. We wouldn't 
//be able to compare our vector template to the Standard 
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;

int main (){
   vector<int> v;   //Our vector class
   std::vector<int> stdv; //Standard vector from <vector>

   //Compare operation of our vector to std
   v.push_back(23);
   stdv.push_back(23);
   
   //both of the following should display "1"
   cout << "Our vector size: " << v.size() << endl;
   cout << "STL vector size: " << stdv.size() << endl;


   //Step 1.....
   //uncomment the following to test Copy Construtor
   vector<int> v2 = v; //envoke cc
   cout << "v2 size: " << v2.size() << endl; //should display 1

   //uncomment the following to test AOO
   vector<int> v3;
   v3.push_back(10);
   v3.push_back(100);
   v3.push_back(1000);
   cout << "v3 size: " << v3.size() << endl; //should display 3
   v3 = v; //envoke aoo
   cout << "v3 size: " << v3.size() << endl; //should display 1


   //Step 2...
   cout << "v[0]: " << v[0] << endl; //should display 23
   cout << "stdv[0]: " << stdv[0] << endl; //should display 23

   v3.push_back(500);
   cout << "v3[1]: " << v3[1] << endl; //should display 500
   cout << "v[1]: " << v[1] << endl; //should display a garbage or crash the program
   
   // should throw an "out_of_range" exception
   // and exit the program gracefully
   try {
      cout << "v.at(1): " << v.at(1) << endl;
   }
   catch(std::out_of_range &error) {
      cout << "Error: out of range" << endl;
   }
   
   //Step 3...
   //Include your own testing code to prove that
   //your push_back(), resize(), and reserve() works

   vector<int> v4;
   for (int i = 0; i < 10; i++) {
      v4.push_back(i + 1);
   }
   cout << "v4 size: " << v4.size() << endl;
   for (int i = 0; i < 10; i++) {
      cout << v4[i] << " ";
   }
   v4.resize(5);
   cout << endl << "v4 size: " << v4.size() << endl;
   for (int i = 0; i < v4.size(); i++) {
      cout << v4[i] << " ";
   }
   cout << endl;
   v4.reserve(9);
   int sizeArray = v4.capacity();
   for (int i = 0; i < 30; i++) {
      v4.push_back(i);
      if (sizeArray != v4.capacity()) {
         sizeArray = v4.capacity();
         cout << "Increase the size limit of v4 so that it can hold " << sizeArray << " elements." << endl;
      }
   }
   return 0;
}