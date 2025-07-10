#include <stdlib.h>
#include <iostream>
#include <exception> //base class of all built-in exceptions
#include <stdexcept> //where out_of_range lives

template <class T>
class vector {
   private:
      T *v;  //a dynamic array of elements of type T
      int s; //size
      int c; //capacity
   public:
      //default constructor
      vector() {
	     this->s = 0;
	     this->v = NULL;
      }

      //destructor	  
      ~vector() {
	     delete [] this->v;
	     this->v = NULL;
      }

      //AOO
      vector& operator=(vector<T> &other) {
         this->s = other.s;
         if (this->v != NULL) {
            delete[] this->v;
         }
         this->v = new T [this->s];
         for (int i = 0; i < this->s; i++) {
            this->v[i] = other.v[i];
         }
         return *this;
      }

      //CC
      vector(vector &other) {
         this->s = other.s; 
         this->v = new T [this->s];
         for (int i = 0; i < this->s; ++i) {
            this->v[i] = other.v[i];
         }
      }

      //Only perform address arithmetic
      T operator[](int i) {
         return this->v[i];
      }

      //Check to make sure not out of bounds
      T at(int i) {
         if (i > this->s - 1) {
            throw std::out_of_range("out of my vector bounds");
         }
         return this->v[i];
      }
	
      //size function	  
      int size() {
	     return this->s;
      }

      //push_back: add an element to the end	  
      void push_back(T ele) {
	     T *temp;
	     temp = new T[++this->s];
	     for(int i = 0; i < this->s-1; i++)
	        temp[i] = this->v[i];

	     if (this->v != NULL)
	     	delete [] this->v;
	     this->v = temp;
	     this->v[s-1] = ele;
        if (this->s == this->c) {
         this->c = this->c * 2;
        }
      }

      //resize (change the size of the array)
      void resize(int i) {
         this->s = i;
      }

      //reserve (create a new array of the size based on user input)
      void reserve(int i) {
         this->c = i;
      }

      int capacity() {
         return this->c;
      }
};
