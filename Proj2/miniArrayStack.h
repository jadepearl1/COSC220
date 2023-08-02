#ifndef MINIARRAYSTACK_H
#define MINIARRAYSTACK_H
#include <iostream> // For cout
#include "RuntimeException.h"
using namespace std;

template <class DataType>
class miniArrayStack
{
private:
    enum
    {
        DEF_CAPACITY = 100
    };             // default stack capacity
    DataType *arr; // The array of items
    int capacity;  // The size of the current array
    int top;       // The location of the top element
    int stackSize;

public:
    miniArrayStack(int cap = DEF_CAPACITY);                                // Constructor for ArrStack
    miniArrayStack(const miniArrayStack<DataType> &);                      // Copy contstructor
    ~miniArrayStack();                                                     // Destructor
    int size() const;                                                      // get the number of elements in the stack
    bool isEmpty() const;                                                  // Check if the stack is empty
    const DataType &getTop() const;                                        // throw(StackEmpty);       //get the top emement without popping it
    void push(const DataType &);                                           // throw(StackFull);	// Pushes  an  object  onto  the  stack
    void pop();                                                            // throw(StackEmpty);	// Pop an object off the stack
    void printStack() const;                                               // Prints the stack from the top, down
    miniArrayStack<DataType> &operator=(const miniArrayStack<DataType> &); //  Assignment  operator
};

template<class DataType>
miniArrayStack<DataType>::miniArrayStack(int cap)
{
    top = -1;
    stackSize = 0;
    capacity = cap;
    arr = new DataType[stackSize];
}

template<class DataType>
miniArrayStack<DataType>::miniArrayStack(const miniArrayStack<DataType> &obj)
{
    obj.stackSize = stackSize;
    obj.capacity = capacity;
    if (top!=-1)
    {
        for(int i=0; i<stackSize; i++)
        {
            obj.arr[i] = arr[i];
        }
    }
}

template<class DataType>
miniArrayStack<DataType>::~miniArrayStack()
{
    delete[] arr;
}

template<class DataType>
int miniArrayStack<DataType>::size() const
{
    return stackSize;
}

template<class DataType>
bool miniArrayStack<DataType>::isEmpty() const
{
    if(size()==0)
        return true;
    else
        return false;
}

template<class DataType>
const DataType& miniArrayStack<DataType>::getTop() const
{
    return arr[0];
}

template<class DataType>
void miniArrayStack<DataType>::push(const DataType &e)
{
    if(stackSize>capacity)
        throw StackFull("");
    top++;
    stackSize++;
    for(int i=stackSize-1; i>0; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = e;
}

template<class DataType>
void miniArrayStack<DataType>::pop()
{
    if(isEmpty())
        throw StackEmpty ("");
    if(isEmpty() == false)
    for(int i=0; i<stackSize; i++)
    {
        arr[i] = arr[i+1];
    }
    top--;
    stackSize--;
}

template<class DataType>
void miniArrayStack<DataType>::printStack() const
{
    for(int i=0; i<stackSize; i++)
        cout << arr[i] << " ";
    cout << endl;
}

template<class DataType>
miniArrayStack<DataType>& miniArrayStack<DataType>::operator=(const miniArrayStack<DataType> &right)
{
    right.stackSize = stackSize;
    right.capacity = capacity;
    right.top = top;
    for (int i = 0; i < capacity; i++)
        right.arr[i] = arr[i];
}


#endif