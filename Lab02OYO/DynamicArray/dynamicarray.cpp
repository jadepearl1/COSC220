//Jade Pearl
//COSC 220-002 -- Lab 02
//Date created: 9/6/2022
//Date last modified: 9/6/2022

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int size = 0;
    cout << "Input size of array: ";
    cin >> size;
    int* arr = new int[size];

    int n = 0;
    cout << "Input n > 0 for upper bound on range of random numbers, [1, n]: ";
    cin >> n;

    if (n<=0)
        return 1;

    srand(time(0));

    for(int i=0; i<size; i++)
    {
        *(arr+i) = (rand()% n) +1;
    }

    string ans; //string representing the option if the user wants or does not want the array printed
    cout << "Do you want a printout of the array? (Y/N): ";
    cin >> ans;
    if (ans == "y" || ans == "Y")
    {
        cout << "Array" << endl;
        for (int j=0; j<2; j++) //to print the array twice
        {        
            for (int i=0; i<size; i++)
                cout << *(arr+i) << " ";
            cout << endl;
        }
    }

    int *counts = new int[n]; //make new array that tallies up how often a number is listen in the first array

    for (int i=0; i<n; i++)
    {
        for(int j=0; j<size; j++)
        {
            if(*(arr+j)==i+1)
                (*(counts+i))++;
        }
    }

    cout << endl << "Counts" << endl;

    for(int i=0; i<n; i++)
    {
        cout << i+1 << ": " << *(counts+i) << endl;
    }

    delete[] arr;
    delete[] counts;

    arr = nullptr;
    counts = nullptr;

    return 0;
}