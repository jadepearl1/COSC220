PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o NumberArray.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

NumberArray.o : NumberArray.h NumberArray.cpp
	$(CC) $(CPPFLAGS) -c NumberArray.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
