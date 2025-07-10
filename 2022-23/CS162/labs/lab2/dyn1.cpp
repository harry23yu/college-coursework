#include <iostream>
#include <string>
using  namespace std;

void create_mem(int **p){
	*p = new int;
	**p = 5;
	delete *p;
}

void create_mem2(int *&p){
	p = new int;
	*p = 5;
	delete p;
}

int* create_mem3(){
	int* p = new int;
	*p = 5;
	return p;
}

int main() {
	int* ptr1;
	int* ptr2;
	create_mem(&ptr1);
	create_mem2(ptr2);
	int* ptr3 = create_mem3();
	delete ptr3;
}
