PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = tokencpp.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

tokencpp.o : tokencpp.cpp
	$(CC) $(CPPFLAGS) -c tokencpp.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make