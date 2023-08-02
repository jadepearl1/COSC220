#include <iostream>
#include <cstdlib>
#include "IntegerList.h"

using namespace std;

IntegerList::IntegerList(int size) {
	list = new int[size];
	numElements = size;
	for (int ndx = 0; ndx < size; ndx++)
		list[ndx] = 0;
}

IntegerList::~IntegerList() {
	delete[] list;
}

IntegerList::IntegerList(const IntegerList &obj) {
	numElements = obj.numElements;
	list = new int[numElements];
	for (int i = 0; i < numElements; i++)
		list[i] = obj.list[i];
}

const IntegerList IntegerList::operator=(const IntegerList &right) {
	delete[] list;
	numElements = right.numElements;
	list = new int[numElements];
	for (int i = 0; i < numElements; i++)
		list[i] = right.list[i];

	return *this;
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
		exit(EXIT_FAILURE);
	}
}

int IntegerList::getElement(int element) const {
	if (isValid(element))
		return list[element];
	else {
		cout << "Error: Invalid subscript\n";
		exit(EXIT_FAILURE);
	}
}

void IntegerList::displayList() const {
	for (int i = 0; i < numElements; i++)
		cout << list[i] << " ";
	cout << endl;
}

int& IntegerList::operator[](const int &sub) {
	if (isValid(sub))
		return list[sub];
	else {
		cout << "Error: Invalid subscript\n";
		exit(EXIT_FAILURE);
	}
}

