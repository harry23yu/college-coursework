CC=g++ -g -std=c++11
EXE_FILE=main_run
all: $(EXE_FILE)
$(EXE_FILE): card.o card.h main.cpp
	$(CC) card.o main.cpp -o $(EXE_FILE)
card.o: card.h card.cpp
	$(CC) -c card.cpp