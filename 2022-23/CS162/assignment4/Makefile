OBJS	= driver.o bats.o event.o gold.o pit.o room.o wumpus.o player.o game.o
SOURCE	= driver.cpp bats.cpp event.cpp gold.cpp pit.cpp room.cpp wumpus.cpp player.cpp game.cpp
HEADER	= bats.h event.h gold.h pit.h room.h wumpus.h player.h game.h
OUT	= driver_run
CC	 = g++ -std=c++11
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

driver.o: driver.cpp
	$(CC) $(FLAGS) driver.cpp

bats.o: bats.cpp bats.h
	$(CC) $(FLAGS) bats.cpp 

event.o: event.cpp event.h
	$(CC) $(FLAGS) event.cpp 

gold.o: gold.cpp gold.h
	$(CC) $(FLAGS) gold.cpp 

pit.o: pit.cpp pit.h
	$(CC) $(FLAGS) pit.cpp 

room.o: room.cpp room.h
	$(CC) $(FLAGS) room.cpp 

wumpus.o: wumpus.cpp wumpus.h
	$(CC) $(FLAGS) wumpus.cpp 

player.o: player.cpp player.h
	$(CC) $(FLAGS) player.cpp 

game.o: game.cpp game.h
	$(CC) $(FLAGS) game.cpp

clean:
	rm -f $(OBJS) $(OUT)