#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include "ListCollection.h"

using namespace std;

template <class T>
class Stack:public ListCollection <T>
{
private:
    ListCollection<T> stack;

public:
    Stack();
    ~Stack();
    void displayStack(bool nl = false) const;

    Stack(const Stack &obj);
    const Stack operator=(const Stack &right);

    void clear();
    int size();
    void push(T);
    T pop();
    bool isEmpty();

};

#endif


template<class T>
Stack<T>::Stack()
{
    stack = ListCollection<T>();
}


template<class T>
Stack<T>::~Stack()
{

}


template<class T>
void Stack<T>::displayStack(bool nl) const
{
    stack.displayList();
}


template<class T>
Stack<T>::Stack(const Stack &obj)
{
    stack = obj.stack;
}


template<class T>
const Stack<T> Stack<T>::operator=(const Stack &right)
{
    stack = right.stack;
    return *this;
}


template<class T>
void Stack<T>::clear()
{
    stack.clear();
}


template<class T>
int Stack<T>::size()
{
    return stack.size();
}


template<class T>
void Stack<T>::push(T elt)
{
    stack.pushBack(elt);
}


template<class T>
T Stack<T>::pop()
{
    return stack.popBack();
}


template<class T>
bool Stack<T>::isEmpty()
{
    bool empty = false;
    if (stack.size()==0)
        empty = true;
    return empty;
}