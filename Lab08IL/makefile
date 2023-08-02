prog: StackQueueTest.o
	g++ -o prog StackQueueTest.o

StackQueueTest.o: StackQueueTest.cpp ListCollection.h Stack.h Queue.h
	g++ -g -Wall -std=c++11 -c StackQueueTest.cpp

clean:
	rm -f prog *.o

rebuild:
	make clean
	make