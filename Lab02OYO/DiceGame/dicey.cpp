//Jade Pearl
//COSC 220-002 -- Lab 02
//Date Created: 9/7/2022
//Date Modified 9/7/2022

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int *arr= nullptr; //creates a pointer to point at the memory location
                        //of the first index of the array to be used
    int rolls= 0; //initialize a variable representing number of dice rolls

    cout << "Input the number of rolls: ";
    cin >> rolls;

    if (rolls<=0)
        return 1;

    arr = new int[rolls];

    int die= 1; //integer representing number of dice to be rolled
    cout << "Input the number of dice: ";
    cin >> die;

    if (die<=0)
        return 1;

    srand(time(0));

    int *counts; //pointer variable that will describe # of times a number is rolled
    counts = new int[5 * die +1];

    for(int i=0; i<rolls; i++)
    {
        int sum = 0;
        for(int j=0; j<die; j++)
        {
            sum += ((rand()% 6) + 1); //gets a number between 1 and 6 for however many dice are rolled
        }
        *(arr+i) = sum;
    }

    string ans; //string representing the option if the user wants or does not want the array printed
    cout << "Do you want a printout of the array? (Y/N): ";
    cin >> ans;
    if (ans == "y" || ans == "Y")
    {
        cout << endl;
        cout << "Rolls" << endl;
        for (int i=0; i<rolls; i++)
            cout << *(arr+i) << " ";
        cout << endl;
    }

    cout << endl;

    cout << "Counts" << endl;
    for (int i=0; i<(5*die+1); i++)
    {
        for(int j=0; j<rolls; j++)
        {
            if(*(arr+j) == i+die)
                (*(counts+i))++;
        }
        cout << i+(die) << ": " << *(counts+i) << endl;
    }

    delete[] arr;
    delete[] counts;

    arr = nullptr;
    counts = nullptr;

    return 0;
}