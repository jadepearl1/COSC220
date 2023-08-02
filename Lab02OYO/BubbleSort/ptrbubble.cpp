//Jade Pearl
//COSC 220-002 -- Lab 02
//Date created: 9/7/2022
//Date Modified: 9/8/2022

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int* duplicateArray(const int *, int);
void displayArray (const int *, int);
int* getRandomNumbers(int);
void sort(int *, int);
bool sorted(const int *, int);
void swap (int *, int *);

int main()
{
    
    int arrSize;

    cout << "Input array size: ";
    cin >> arrSize;

    int *arr = getRandomNumbers(arrSize);

    displayArray (arr, arrSize);

    sort (arr, arrSize);

    int *newarr = duplicateArray(arr, arrSize);

    displayArray (newarr, arrSize);

    bool check = sorted(arr, arrSize);
    if (check == true)
        cout << "Array is sorted." << endl;
    else
        cout << "Array is not sorted." << endl;

    delete[] newarr;

    return 0;
}


int *getRandomNumbers(int size)
{
    int *arr = new int[size];
    srand(time(0));
    for(int i=0; i<size; i++)
        *(arr+i) = rand();
    
    return arr;
}


void displayArray (const int *arr, int size)
{
    for (int i=0; i<size; i++)
    {
        cout << *(arr+i) << "  ";
    }
    cout << endl;
}


void sort(int *arr, int size)
{
    for (int i=0; i<size-1; i++)
    {
        for (int j=0; j<size-i-1; j++)
            if (*(arr+j)>*(arr+(j+1)))
            {
                swap(*(arr+j), *(arr+(j+1)));
            }
    }
}


void swap(int* one, int* two)
{
    int temp = *one;
    *one = *two;
    *two = temp;
}


 int* duplicateArray(const int *arr, int size)
 {
     int *newArr = nullptr;

     if (size <= 0)
         return nullptr;

     newArr = new int[size];

     for (int i=0; i<size; i++)
         *(newArr+i) = *(arr+i);

    delete[] arr;
     return newArr;
 }


 bool sorted(const int *arr, int size)
 {
    for (int i=0; i<=size; i++)
    {
        if(*(arr+i)>*(arr+i+1))
            return false;
        else
            return true;
    }
 }