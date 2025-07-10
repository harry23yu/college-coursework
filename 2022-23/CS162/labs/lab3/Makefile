CC=g++
EXE_FILE=multdiv_run
all: $(EXE_FILE)
$(EXE_FILE): multdiv.o multdiv.h main.cpp
	$(CC) multdiv.o main.cpp -o $(EXE_FILE)
multdiv.o: multdiv.h multdiv.cpp
	$(CC) -c multdiv.cpp