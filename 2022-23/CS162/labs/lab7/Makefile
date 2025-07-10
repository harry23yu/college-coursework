OBJS	= application.o shape.o rectangle.o circle.o square.o
SOURCE	= application.cpp shape.cpp rectangle.cpp circle.cpp square.cpp
HEADER	= shape.h rectangle.h circle.h square.h
OUT	= application_run
CC	 = g++ -std=c++11
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

application.o: application.cpp
	$(CC) $(FLAGS) application.cpp

shape.o: shape.cpp shape.h
	$(CC) $(FLAGS) shape.cpp

rectangle.o: rectangle.cpp rectangle.h
	$(CC) $(FLAGS) rectangle.cpp

circle.o: circle.cpp circle.h
	$(CC) $(FLAGS) circle.cpp

square.o: square.cpp square.h
	$(CC) $(FLAGS) square.cpp

clean:
	rm -f $(OBJS) $(OUT)