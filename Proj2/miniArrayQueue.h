#ifndef MINIARRAYQUEUE_H
#define MINIARRAYQUEUE_H
#include <iostream> // For cout
#include "RuntimeException.h"
using namespace std;

template <class DataType>
class miniArrayQueue
{
private:
    DataType *arr; // The array of items
    int capacity;  // The size of the current array
    int front;     // The location of the front element
    int rear;      // The location of the rear element
    int queueSize;

public:
    miniArrayQueue();                                                      // Constructor
    miniArrayQueue(const miniArrayQueue<DataType> &);                      // Copy Constructor
    ~miniArrayQueue();                                                     //   Destructor
    int size() const;                                                      // get the number of elements in the queue
    bool isEmpty() const;                                                  // Check if the queue is empty
    void enqueue(const DataType &e);                                       // throw(QueueFull), Enqueue element at rear
    void dequeue();                                                        // throw(QueueEmpty), dequeue element at front
    const DataType &getFront() const;                                      // throw(QueueEmpty), return the front element but not remove
    void printQueue() const;                                               // Prints the queue from the front to the rear
    miniArrayQueue<DataType> &operator=(const miniArrayQueue<DataType> &); // Assignment operator
};

template<class DataType>
miniArrayQueue<DataType>::miniArrayQueue()
{
    front = 0;
    rear = 0;
    capacity = 100;
    queueSize = rear-front;
    arr = new DataType[capacity];
}

template<class DataType>
miniArrayQueue<DataType>::miniArrayQueue(const miniArrayQueue<DataType> &obj)
{
    arr = new DataType[obj.capacity];
    front = obj.front;
    rear = obj.rear;
    queueSize = obj.queueSize;
    for(int i=0; i<=capacity; i++)
    {
        arr[i] = obj.arr[i];
    }
}

template<class DataType>
miniArrayQueue<DataType>::~miniArrayQueue()
{
    delete[] arr;
}

template<class DataType>
int miniArrayQueue<DataType>::size() const
{
    return (rear-front);
}

template<class DataType>
bool miniArrayQueue<DataType>::isEmpty() const
{
    if(size() != 0)
        return false;
    else
        return true;
}

template<class DataType>
void miniArrayQueue<DataType>::enqueue(const DataType &e)
{
    queueSize = size();
    // if(queueSize>capacity)
    //     throw QueueFull("");
    rear++;
    arr[rear] = e;
}

template<class DataType>
void miniArrayQueue<DataType>::dequeue()
{
    if(isEmpty())
        throw QueueEmpty("");
    front++;
    queueSize = size();
}

template<class DataType>
const DataType& miniArrayQueue<DataType>::getFront() const
{
    // if(isEmpty())
    //    throw QueueEmpty("");
    return arr[front+1];
}

template<class DataType>
void miniArrayQueue<DataType>::printQueue() const
{
    for(int i=front+1; i<=rear; i++)
        cout << arr[i] << " ";
    cout << endl;
}

template<class DataType>
miniArrayQueue<DataType>& miniArrayQueue<DataType>::operator=(const miniArrayQueue<DataType> &right)
{
    delete [] this->arr;
    this->arr = new DataType[right.capacity];
    this->queueSize = right.queueSize;
    this->front = right.front;
    this->rear = right.rear;
    for (int i = this->front; i<=this->rear; i++)
        this->arr[i] = right.arr[i];
    return *this;
}

#endif