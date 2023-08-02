//Jade Pearl
//COSC 220-002 -- Lab 02
//Date created: 9/7/2022
//Date Modified: 9/9/2022

#include <iostream>
using namespace std;

int *ConcatenateArrays(const int *, const int *, int, int);
int *ReverseArray (const int *, int);
int *ArrayExpander (const int *, int);
int *ElementShiftRight (const int *, int);
int *ElementShiftLeft (const int*, int);
void swap(int*, int*);

int main()
{
    int *arrA = nullptr;
    int *arrB = nullptr;
    int SA = 5; //size of array A
    int SB = 7; //Size of array B
    int n = SA+SB; //size of concatenation array for purposes of calling ReverseArray in main

    arrA = new int[SA];
    arrB = new int[SB];
    
    *arrA = 5, *(arrA+1) = 4, *(arrA+2) = 3, *(arrA+3) = 2, *(arrA+4) = 1;
    for(int i=0; i<SA; i++)
        cout << *(arrA+i) << " ";
    cout << endl;

    *arrB = 6, *(arrB+1) = 7, *(arrB+2) = 9, *(arrB+3) = 11, *(arrB+4) = 12, *(arrB+5) =13, *(arrB+6) = 14;
    for(int i=0; i<SB; i++)
        cout << *(arrB+i) << " ";
    cout << endl;

    int *concat = ConcatenateArrays(arrA, arrB, SA, SB);
    int *revConcat = ReverseArray(concat, n);

    int *exArray = ArrayExpander(arrA, SA);

    int *right = ElementShiftRight(arrB, SB);
    int *left = ElementShiftLeft(arrB, SB);

    delete[] arrA;
    delete[] arrB;
    delete[] concat;
    delete[] revConcat;
    delete[] exArray;
    delete[] right;
    delete[] left;

    return 0;
}



int *ConcatenateArrays(const int *arrA, const int *arrB, int SA, int SB)
{
    int *concat = nullptr;
    int conSize = SA + SB; //size of the new concatenation array
    concat = new int[conSize];
    for(int i=0; i<SA; i++)
    {
        *(concat+i) = *(arrA+i);
    }
    for(int i=SA; i<conSize; i++)
    {
        *(concat+i) = *(arrB+(i-SA));
    }
    for(int i=0; i<conSize; i++)
    {
        cout << *(concat+i) << " ";
    }
    cout << endl;

    return concat;
}


int *ReverseArray(const int *concat, int size)
{
    int *revConcat = nullptr;
    revConcat = new int[size];
    for(int i=0; i<size; i++)
    {
        *(revConcat+i) = *(concat+i);
    }
    int *ptr1 = revConcat;
    int *ptr2 = revConcat + (size-1);
    while(ptr1<ptr2)
    {
        swap(ptr1, ptr2);
        ptr1++;
        ptr2--;
    }

    for(int i=0; i<size; i++)
    {
        cout << *(revConcat+i) << " ";
    }
    cout << endl;
    return revConcat;
}


void swap(int *one, int *two)
{
    int temp = *one;
    *one = *two;
    *two = temp;
}


int *ArrayExpander(const int *arrA, int size)
{
    int *exArray = nullptr;
    int exSize = size * 2;
    exArray = new int[exSize];

    for (int i=0; i<exSize; i++)
    {
        if(i >= size)
            *(exArray+i) = 0;
        else
            *(exArray+i) = *(arrA+i);
        cout << *(exArray+i) << " ";
    }
    cout << endl;
    return exArray;
}


int *ElementShiftRight(const int *arrB, int size)
{
    int *right = nullptr;
    right = new int[size];
    for (int i=0; i<size; i++)
    {
        *(right+i) = *(arrB+i);
    }
    
    int final = *(right+(size-1)); //holds onto the last element in order to swap the first and last elements of the array
    for (int i=size-2; i>=0; i--)
    {
        *(right+(i+1)) = *(right+i);
    }
    *right = final;
    for (int i=0; i<size; i++)
    {
        cout << *(right+i) << " ";
    }
    cout << endl;
    return right;
}


int *ElementShiftLeft(const int *arrB, int size)
{
    int *left = nullptr;
    left = new int[size];
    for (int i=0; i<size; i++)
    {
        *(left+i) = *(arrB+i);
    }

    int first = *left; //holds onto the value of the first element to switch with the last element at the end of the shift
    for (int i=0; i<size-1; i++)
    {
        *(left+i) = *(left+(i+1));
    }
    *(left+(size-1)) = first;
    for (int i=0; i<size; i++)
    {
        cout << *(left+i) << " ";
    }
    cout << endl;
    return left;
}