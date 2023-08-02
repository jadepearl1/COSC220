//Jade Pearl
//COSC 220 Lab 03 OYO
//Date created: 9/13/2022
//Date updated: 9/13/2022

#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H

class NumberArray
{
    private:
        float *nums; //pointer to the array that is to be allocated
        int arrSize; //size of the allocated array
    
    public:
        NumberArray(int); //constructor which will accept the size to dynamically allocate the array
        ~NumberArray(); //destructor which frees the memory held by the array
        
        void storeNums(float, int); //Stores chosen numbers in the elements of the array
        float getNums(int); //retrieves a number from any element in the array
        float getHighest(int); //function that returns the highest value stored in the array
        float getLowest(int); //returns the lowest value found in the array
        float getAverage(int); //finds and returns the average of the array
};

#endif