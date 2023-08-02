PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o CustomerData.o PersonData.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

CustomerData.o : CustomerData.h CustomerData.cpp
	$(CC) $(CPPFLAGS) -c CustomerData.cpp

PersonData.o : PersonData.h PersonData.cpp
	$(CC) $(CPPFLAGS) -c PersonData.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make