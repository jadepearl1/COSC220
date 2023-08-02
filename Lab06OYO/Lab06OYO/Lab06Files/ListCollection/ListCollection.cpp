#include <iostream>
#include <cstdlib>
#include "ListCollection.h"

using namespace std;

//**************************************************************************************
// tests if an element is valid and if it is a valid index of the list; returns a boolean
//**************************************************************************************
bool ListCollection::isValid(int element) const
{
    bool status;

    if (element >= 0 || element <= numElements)
        status = true;
    else
        status = false;
    return status;
}

//****************
// resizes the list
//****************
void ListCollection::resize(int a)
{
    int *arr = nullptr;
    arr = new int[a];
    if (a > numCapacity) // if the size of the new list shall exceed the capacity of the old one, the capacity will automatically double
        numCapacity = numCapacity * 2;

    for (int i = 0; i < a; i++)
    {
        arr[i] = list[i];
        if (i >= numElements)
        {
            arr[i] = 0;
        }
    }
    delete[] list;
    list = arr;
    numElements = a;
}

//***********
// Constructor
//***********
ListCollection::ListCollection(int sz)
{
    //sz = 10;
    numCapacity = sz;
    numElements = 0;
    list = new int[sz];
    for (int ndx = 0; ndx < sz; ndx++)
        list[ndx] = 0;
}

//**********
// Destructor
//**********
ListCollection::~ListCollection()
{
    delete[] list;
}

//**************************
// Sets an element to a value
//**************************
void ListCollection::setElement(int position, int element)
{
    if (isValid(position))
        list[position] = element;
    else
    {
        cout << "Error: Invalid subscript\n";
    }
}

//******************
// Returns an element
//******************
int ListCollection::getElement(int position) const
{
    if (isValid(position))
        return list[position];
    else if (position < 0)
    {
        return list[0];
    }
    else
    {
        return list[numElements - 1];
    }
}

//*****************
// Displays the list
//*****************
void ListCollection::displayList(bool nl) const
{
    for (int i = 0; i < numElements; i++) {
	    cout << list[i] << " ";
    if (nl)
		cout << endl;
	}
	if (!nl)
		cout << endl;
}

//****************
// Copy constructor
//****************
ListCollection::ListCollection(const ListCollection &obj)
{
    numElements = obj.numElements;
    list = new int[numElements];
    for (int i = 0; i < numElements; i++)
        list[i] = obj.list[i];
}

//******************************
// Overloaded Assignment Operator
//******************************
const ListCollection ListCollection::operator=(const ListCollection &right)
{
    delete[] list;
    numElements = right.numElements;
    numCapacity = right.numCapacity;
    list = new int[numElements];
    for (int i = 0; i < numElements; i++)
        list[i] = right.list[i];

    return *this;
}

//*************************************************
// Overloaded + operator that concatenates two lists
//*************************************************
const ListCollection ListCollection::operator+(const ListCollection &right) // concatenates two lists
{
    ListCollection *newArr = nullptr;
    newArr = new ListCollection[numElements + right.numElements];
    newArr->numCapacity = numCapacity;
    for (int i = 0; i < numElements; i++)
    {
        newArr[i] = list[i];
    }
    for (int i = numElements; i < newArr->numElements; i++)
    {
        newArr[i] = right.list[i - numElements];
    }
    return *newArr;
}

//**********************************************************************************
// returns new ListCollection of elements within an index range of a preexisting list
//**********************************************************************************
const ListCollection ListCollection::sublist(int num1, int num2)
{
    if (num2 > numElements)
    {
        num2 = numElements-1;
    }
    ListCollection newList(this->numElements);
    newList.numElements = num2-num1+1;
    newList.numCapacity = newList.numElements;
    for(int i=0; i<newList.numElements; i++)
    {
        newList.list[i] = list[i+num1];
    }

    return newList;
    
}

//********************************************************************************************************************************************
// returns a new list that starts at the parameter index from the original list and the last element is reached at the end of the original list
//********************************************************************************************************************************************
const ListCollection ListCollection::sublist(int elem)
{
    ListCollection *newArr = nullptr;
    newArr = new ListCollection[numElements - (elem)];
    newArr->numCapacity = numCapacity;
    for (int i = 0; i < newArr->numElements; i++)
    {
        newArr[i] = list[i + elem];
    }
    return *newArr;
}

//**********************************************************************
// Sorts the list into ascending order without altering the original list
//**********************************************************************
const ListCollection ListCollection::sort()
{
    //ListCollection temp(*this);
    ListCollection sortList(numElements);
    sortList.numElements = numElements;

    for(int i=0; i<sortList.numElements; i++)
    {
        sortList.list[i] = list[i];
    }

    int temp;
    for (int i=0; i<sortList.numElements; i++)
    {
        for (int j=0; (j+1)<(sortList.numElements-i); j++)
        {
             if (sortList.list[j] > sortList.list[j+1])
            {
                temp = sortList.list[j];
                sortList.list[j] = sortList.list[j+1];
                sortList.list[j+1] = temp;
            }
        }
    }

    sortList.numCapacity = numElements;
    return sortList;
}

//*******************************
// clears the contents of the list
//*******************************
void ListCollection::clear()
{
    numElements = 0;
}

//*************************
// returns current list size
//*************************
int ListCollection::size()
{
    return numElements;
}

//*********************************
// returns the current list capacity
//*********************************
int ListCollection::capacity()
{
    return numCapacity;
}

//*********************************************************************************
// Adds input parameter into beginning of the list and moves the other elements down
//*********************************************************************************
void ListCollection::pushFront(int elem)
{
    numElements += 1; // since an element is being added to the list, the number of elements goes up by 1
    for (int i = numElements - 1; i > 0; i--)
    {
        list[i] = list[i - 1]; // shift all existing elements to the right
    }
    list[0] = elem; // put the input parameter in the first index of the list
}

//*********************************
// Adds input to the end of the list
//*********************************
void ListCollection::pushBack(int elem)
{
    numElements++; // since an element is being added to the list, the number of elements will increase by 1
    if (numElements > numCapacity)
    {
        numCapacity = numCapacity * 2;
    }
    list[numElements-1] = elem;
}

//**********************************************
// Removes and returns the first item in the list
//**********************************************
int ListCollection::popFront()
{
    int removed = list[0]; // will represent the element that will be removed
    //int last = list[numElements];
    numElements--;
    //list[numElements + 1] = last;
    for (int i = 0; i < numElements; i++)
    {
        list[i] = list[i + 1];
    }

    return removed;
}

//************************************************
// Removes and returns the last element in the list
//************************************************
int ListCollection::popBack()
{
    int removed = list[numElements];
    numElements--;
    return removed;
}

//******************************************************************************************
// Inserts parameter item into the list so that smaller values occur before the inserted item
//******************************************************************************************
void ListCollection::insertOrdred(int elem)
{
    // int temp = numCapacity;
    // pushFront(elem);
    // *this = this->sort();
    // numCapacity = temp;
    if (numElements == numCapacity)
		resize(2 * numCapacity);

	int pos = 0;
	while (pos < numElements && list[pos] < elem)
		pos++;

	if (pos == 0)
		pushFront(elem);
	else if (pos == numElements)
		pushBack(elem);
	else {
		for (int i = numElements; i >= pos; i--)
			list[i + 1] = list[i];

		list[pos] = elem;
		numElements++;
	}
}

//*******************************************************************************************
// Searches for the first occurence of the parameter in the list and removes it if it is found
//*******************************************************************************************
void ListCollection::removeElement(int elem)
{
    for (int i = 0; i < numElements; i++) {
        if (list[i] == elem) {
            remove(i);
            numElements--;
            break;
        }
    }
}

//**********************************************************************************************
// First parameter = position, second = element. insert element into given position(sent to front
// if position too small or back if position too large)
//**********************************************************************************************
void ListCollection::insert(int position, int elem)
{
    if (position < 0)
    {
        pushFront(elem);
    }
    else if (position > numElements)
    {
        pushBack(elem);
    }
    else
    {
        numElements += 1;
        for (int i = position; i < numElements; i++)
        {
            list[i] = list[i + 1]; // shifts all elements at the parameter position to the right
        }
        elem = list[position];
    }
}

//***************************************************************************************
// Removes item at parameter position. List remains unaltered if parameter is out of range
//***************************************************************************************
void ListCollection::remove(int position)
{
    if ((position >= 0) && (position <= numElements))
    {
        for (int i = position; i < numElements - 1; i++)
        {
            list[i] = list[i + 1]; // overwrites the element with the elements behind it for the rest of the list
        }
    }
}