#ifndef MINIDLISTSTACK_H
#define MINIDLISTSTACK_H
#include <iostream> // For cout
#include "RuntimeException.h"
using namespace std;

template <class DataType>
class miniDListStack
{
private:
    miniDList<DataType> list;
    class StackEmpty : public RuntimeException
    {
    public:
        StackEmpty(const string &err) : RuntimeException(err) {}
    };

public:
    miniDListStack();                                                      // Constructor for ListStack
    miniDListStack(const miniDListStack<DataType> &);                      // Copy contstructor
    ~miniDListStack();                                                     // Destructor
    int size() const;                                                      // get the number of elements in the stack
    bool isEmpty() const;                                                  // Check if the stack is empty
    const DataType &top() const;                                           // throw(StackEmpty);       //get the top emement without popping it
    void push(const DataType &);                                           // Pushes  an  object  onto  the  stack
    void pop();                                                            // throw(StackEmpty);	// Pop an object off the stack
    void printStack() const;                                               // Prints the stack from the top, down
    miniDListStack<DataType> &operator=(const miniDListStack<DataType> &); //  Assignment  operator
};

template<class DataType>
miniDListStack<DataType>::miniDListStack()
{
    
}

template<class DataType>
miniDListStack<DataType>::miniDListStack(const miniDListStack<DataType> &obj)
{
    list = obj.list;
}

template<class DataType>
miniDListStack<DataType>::~miniDListStack()
{

}

template<class DataType>
int miniDListStack<DataType>::size() const
{
    return list.size();
}

template<class DataType>
bool miniDListStack<DataType>::isEmpty() const
{
    bool empty = false;
    if (list.size()==0)
        empty = true;
    return empty;
}

template<class DataType>
const DataType& miniDListStack<DataType>::top() const
{
    if(isEmpty())
        throw StackEmpty("");
    return list.front();
}

template<class DataType>
void miniDListStack<DataType>::push(const DataType &e)
{
    list.addFront(e);
}

template<class DataType>
void miniDListStack<DataType>::pop()
{
    if(isEmpty())
        throw StackEmpty ("");
    list.removeFront();
}

template<class DataType>
void miniDListStack<DataType>::printStack() const
{
    list.display();
}

template<class DataType>
miniDListStack<DataType>& miniDListStack<DataType>::operator=(const miniDListStack<DataType> &right)
{
    list = right.list;
    return *this;
}

#endif