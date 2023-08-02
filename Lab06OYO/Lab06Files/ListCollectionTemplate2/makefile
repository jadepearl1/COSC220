PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = ListCollection.o ListTest.o FeetInches.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

ListCollection.o : ListCollection.cpp ListCollection.h
	$(CC) $(CPPFLAGS) -c ListCollection.cpp

ListTest.o : ListTest.cpp
	$(CC) $(CPPFLAGS) -c ListTest.cpp

FeetInches.o : FeetInches.cpp FeetInches.h
	$(CC) $(CPPFLAGS) -c FeetInches.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make

