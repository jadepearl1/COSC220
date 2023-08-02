prog: FeetInches.o
	g++ -o prog FeetInches.o

FeetInches.o: FeetInches.cpp FeetInches.h miniDList.h miniDListQueue.h miniArrayStack.h miniArrayQueue.h miniArrayStack.h RuntimeException.h
	g++ -g -Wall -std=c++11 -c FeetInches.cpp

clean:
	rm -f prog *.o

rebuild:
	make clean
	make