#ifndef MINIDLISTQUEUE_H
#define MINIDLISTQUEUE_H
#include <iostream> // For cout
#include "RuntimeException.h"
using namespace std;

template <class DataType>
class miniDListQueue
{
private:
    miniDList<DataType> *list;

    class QueueEmpty : public RuntimeException
    {
    public:
        QueueEmpty(const string &err) : RuntimeException(err) {}
    };

public:
    miniDListQueue();                                                      // Constructor
    miniDListQueue(const miniDListQueue<DataType> &);                      // Copy Constructor
    ~miniDListQueue();                                                     //   Destructor
    int size() const;                                                      // get the number of elements in the queue
    bool isEmpty() const;                                                  // Check if the queue is empty
    void enqueue(const DataType &e);                                       // Enqueue element at rear
    void dequeue();                                                        // throw(QueueEmpty);	// dequeue element at front
    const DataType &front() const;                                         // throw(QueueEmpty); //return the front element but not remove
    void printQueue() const;                                               // Prints the queue from the front to the rear
    miniDListQueue<DataType> &operator=(const miniDListQueue<DataType> &); // Assignment operator
};

template<class DataType>
miniDListQueue<DataType>::miniDListQueue()
{
    list = new miniDList<DataType>;
}

template<class DataType>
miniDListQueue<DataType>::miniDListQueue(const miniDListQueue &obj)
{
    list = obj.list;
}

template<class DataType>
miniDListQueue<DataType>::~miniDListQueue()
{
    //Destructor: nothing needs to be written here
}

template<class DataType>
int miniDListQueue<DataType>::size() const
{
    return list->size();
}

template<class DataType>
bool miniDListQueue<DataType>::isEmpty() const
{
    bool empty = false;
    if(list->size() == 0)
        empty = true;
    return empty;
}

template<class DataType>
void miniDListQueue<DataType>::enqueue(const DataType &e)
{
    list->addBack(e);
}

template<class DataType>
void miniDListQueue<DataType>::dequeue()
{
    if(isEmpty())
        throw QueueEmpty ("");
    list->removeFront();
}

template<class DataType>
const DataType& miniDListQueue<DataType>::front() const
{
    if(isEmpty())
        throw QueueEmpty ("");
    return list->front();
}

template<class DataType>
void miniDListQueue<DataType>::printQueue() const
{
    list->display();
}

template<class DataType>
miniDListQueue<DataType>& miniDListQueue<DataType>::operator=(const miniDListQueue<DataType> &obj)
{
    list = obj.list;
    return *this;
}

#endif