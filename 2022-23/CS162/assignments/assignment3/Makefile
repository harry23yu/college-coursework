OBJS	= driver.o card.o deck.o hand.o player.o game.o
SOURCE	= driver.cpp card.cpp deck.cpp hand.cpp player.cpp game.cpp
HEADER	= card.h deck.h hand.h player.h game.h
OUT	= driver_run
CC	 = g++ -std=c++11
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

driver.o: driver.cpp
	$(CC) $(FLAGS) driver.cpp

card.o: card.cpp card.h
	$(CC) $(FLAGS) card.cpp 

deck.o: deck.cpp deck.h
	$(CC) $(FLAGS) deck.cpp 

hand.o: hand.cpp hand.h
	$(CC) $(FLAGS) hand.cpp 

player.o: player.cpp player.h
	$(CC) $(FLAGS) player.cpp 

game.o: game.cpp game.h
	$(CC) $(FLAGS) game.cpp 


clean:
	rm -f $(OBJS) $(OUT)