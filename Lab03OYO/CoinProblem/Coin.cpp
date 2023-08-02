// Jade Pearl
// COSC 220-002 Lab 03 OYO
// Created: 9/14/2022
// Modified: 9/17/2022

#include <iostream>
#include "Coin.h"
#include <cstdlib>
#include <time.h>
#include <string>

using namespace std;

//*****************************************************************
//Constructor that will randomly pre-determines the value of sideUp
//*****************************************************************
Coin::Coin()
{
    srand(time(0));

    int num; //will hold the random number that is determined for sideUp initialization
    num = 1 + rand()%2;
    
    if (num == 1) //assign heads to 1 and tails to 2
        sideUp = "heads";
    else if (num == 2)
        sideUp = "tails";
}


//********************************************
//Member function that simulates the coin toss
//********************************************
void Coin::toss()
{
    //repeat same process as done in the constructor
    int num;
    num = 1 + rand()%2;

    if (num == 1)
        sideUp = "heads";
    else if (num == 2)
        sideUp = "tails";
}


//getSideUp already defined and initialized in the class declaration Coin.h file