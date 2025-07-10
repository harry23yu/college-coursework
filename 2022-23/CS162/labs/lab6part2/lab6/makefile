CC=g++ -std=c++11 -g
exe1=ex1
exe2=ex2

all: $(exe1) $(exe2)

$(exe1): ex1.o main.cpp
	$(CC) main.cpp ex1.o -o $(exe1)

ex1.o: ex1.h ex1.cpp
	$(CC) -c ex1.cpp

$(exe2): ex2.cpp
	$(CC) ex2.cpp -o $(exe2)


clean: 
	rm -f *.o $(exe1) $(exe2)
