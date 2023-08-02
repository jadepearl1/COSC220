//Jade Pearl
//COSC 220 Lab 03 OYO
//Date created: 9/13/2022
//Date updated: 9/14/2022

#include <iostream>
#include "NumberArray.h"

using namespace std;

//******************************************************************************
//Constructor that allocates the array and size; sets all elements to 0 at first
//******************************************************************************
NumberArray::NumberArray(int size)
{
    nums = new float[size];
    arrSize = size;
	for (int i=0; i<size; i++)
		*(nums+i) = 0;
}


//*************************************************
//Destructor meant to free memory held by the array
//*************************************************
NumberArray::~NumberArray()
{
    delete[] nums;
}


//********************************************************************************************************************************
//Member function that accepts a float element and an index number as arguments and stores the numbers in any element of the array
//********************************************************************************************************************************
void NumberArray::storeNums(float elem, int ndx)
{
    *(nums+ndx) = elem;
}


//********************************************************
//Member function that retrieves a number from any element
//********************************************************
float NumberArray::getNums(int ndx)
{
    return *(nums+ndx);
}


//**********************************************************************
//Member function that finds and returns the maximum number in the array
//**********************************************************************
float NumberArray::getHighest(int size)
{
    float highest = *nums; //variable that holds the highest element
    for (int i=0; i<size; i++) //for loop that finds the highest element
    {
        if (*(nums+i)>highest)
            highest = *(nums+i);
    }
    return highest;
}


//**********************************************************************
//Member function that finds and returns the lowest element of the array
//**********************************************************************
float NumberArray::getLowest(int size)
{
    float lowest = *nums; //make a variable to store the smallest element
    for (int i=0; i<size; i++) //for loop that finds the lowest element
    {
        if (*(nums+i)<lowest)
            lowest = *(nums+i);
    }
    return lowest;
}


//*************************************************************************************
//Member function that finds and returns the average of all numbers stored in the array
//*************************************************************************************
float NumberArray::getAverage(int size)
{
    float sum = 0; //make a variable that stores the sum of all elements in the array
    for (int i=0; i<size; i++)
        sum += *(nums+i);
    return sum/size;
}