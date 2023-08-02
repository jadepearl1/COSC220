//Jade Pearl
//Created: 9/20/2022
//Modified: 9/21/2022

//Update of the original IntegerList.cpp from the Lab04Files

#include <iostream>
#include <cstdlib>
#include "IntegerList.h"

using namespace std;

IntegerList::IntegerList(int size) {
    cout << "In Constructor" << endl;
	list = new int[size];
	numElements = size;
	for (int ndx = 0; ndx < size; ndx++)
		list[ndx] = 0;
}

IntegerList::~IntegerList() {
    cout << "In Destructor" << endl;
	delete[] list;
}

IntegerList::IntegerList(const IntegerList &obj) {
    cout << "In Copy Constructor" << endl;
	numElements = obj.numElements;
	list = new int[numElements];
	for (int i = 0; i < numElements; i++)
		list[i] = obj.list[i];
}

const IntegerList IntegerList::operator=(const IntegerList &right) {
    cout << "In Assignment Statement" << endl;
	delete[] list;
	numElements = right.numElements;
	list = new int[numElements];
	for (int i = 0; i < numElements; i++)
		list[i] = right.list[i];
	return *this;
}

IntegerList::IntegerList() //Default constructor that will be used when l3 is declared in main
{
    cout << "In Default Constructor" << endl;
    numElements = 0;
	list = new int[numElements];
}

bool IntegerList::isValid(int element) const {
	bool status;

	if (element < 0 || element >= numElements)
		status = false;
	else
		status = true;
	return status;
}

void IntegerList::setElement(int element, int value) {
	if (isValid(element))
		list[element] = value;
	else {
		cout << "Error: Invalid subscript\n";
	}
}

int IntegerList::getElement(int element) const {
	if (isValid(element))
		return list[element];
	else if (element < 0)
    {
		//cout << "Error: Invalid subscript\n";
	    return list[0];
	}
    else
    {
        return list[numElements-1];
    }
}

void IntegerList::displayList() const {
	for (int i = 0; i < numElements; i++)
		cout << list[i] << " ";
	cout << endl;
}

int& IntegerList::operator[](const int &sub) {
    cout << "The [] operator is being called with the index " << sub << endl;
	if (isValid(sub))
		return list[sub];
	else if (sub < 0)
    {
		//cout << "Error: Invalid subscript\n";
        return list[0];    
	}
    else
    {
        return list[numElements-1];
    }
}


const IntegerList IntegerList::operator+ (const IntegerList &right) //concatenates two lists
{
    cout << "In the + operator" << endl;
    IntegerList opList(numElements + right.numElements);
    for(int i=0; i<numElements; i++)
    {
        opList[i] = list[i];
    }
    for(int i=numElements; i<opList.numElements; i++)
    {
        opList[i] = right.list[i-numElements];
    }

    cout << "Out the + operator" << endl;
    return opList;
}


void IntegerList::resize(int a)
{
    int *sizList = nullptr;
    sizList = new int[a];
    
    for (int i=0; i<a; i++)
    {
        sizList[i] = list[i];
        if(i>=numElements)
        {
            sizList[i] = 0;
        }
    }
    delete [] list;
    list = sizList;
    numElements = a;
}


const IntegerList IntegerList::sublist(int num1, int num2)
{
    if (num2 > numElements)
    {
        num2 = numElements-1;
    }
    IntegerList newIntList((num2-num1)+1);
    for(int i=0; i<newIntList.numElements; i++)
    {
        newIntList[i] = list[i+num1];
    }

    return newIntList;
}


const IntegerList IntegerList::sublist(int elem)
{
    IntegerList newList(numElements-(elem));
    for(int i=0; i<newList.numElements; i++)
    {
        newList[i] = list[i+elem];
    }

    return newList;
}


const IntegerList IntegerList::sort()
{
    IntegerList sortList(numElements);
    for(int i=0; i<sortList.numElements; i++)
    {
        sortList[i] = list[i];
    }

    int temp;
    for (int i=0; i<sortList.numElements; i++)
    {
        for (int j=0; (j+1)<(sortList.numElements-i); j++)
        {
             if (sortList[j] > sortList[j+1])
            {
                temp = sortList[j];
                sortList[j] = sortList[j+1];
                sortList[j+1] = temp;
            }
        }
    }

    return sortList;
}