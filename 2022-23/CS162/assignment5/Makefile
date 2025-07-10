OBJS	= linked_list.o
SOURCE	= test_linked_list.cpp
HEADER	= linked_list.h node.h
OUT	= driver_run
CC	 = g++ -std=c++11
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(SOURCE) $(OBJS) -o $(OUT) $(LFLAGS)

linked_list.o: linked_list.cpp
	$(CC) $(FLAGS) linked_list.cpp

clean:
	rm -f $(OBJS) $(OUT)