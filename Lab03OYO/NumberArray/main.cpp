//Jade Pearl
//COSC 220 Lab03 OYO
//Created: 9/13/2022
//Modified: 9/14/2022

#include <iostream>
#include "NumberArray.h"

using namespace std;

int main()
{
    int size, index;
    float element;
    
    cout << "Welcome to the NumberArray class! Input the size of the array: ";
    cin >> size;
    cout << endl << endl;
    NumberArray myArray(size);

    for (int i=0; i<size; i++)
    {
        cout << "Please input the element for index " << i << ": ";
        cin >> element;
        myArray.storeNums(element, i);
    }

    cout << endl << endl;
    cout << "Which index (between 0 and " << size-1 << ")" << " would you like to search?: ";
    cin >> index;
    cout << endl << endl;

    cout << "The element at index " << index << " is: " << myArray.getNums(index) << endl;
    cout << "The highest element is: " << myArray.getHighest(size) << endl;
    cout << "The lowest element is: " << myArray.getLowest(size) << endl;
    cout << "The average of all elements in the array is: " << myArray.getAverage(size) << endl;

    return 0;
}
