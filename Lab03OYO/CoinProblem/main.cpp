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

int main()
{
    srand(time(0));
    Coin gameCoin;
    string up; //stores the value of sideUp in main
    int heads = 0;
    int tails = 0; //two integer variables that count how many times heads and tails have been flipped
    //get the initial side that was up before the tosses begin
    cout << "The coin starts on " << gameCoin.getSideUp() << endl << endl;

    //flip coin 20 times
    for(int i=0; i<20; i++)
    {
        gameCoin.toss();
        up = gameCoin.getSideUp();
        cout << "Coin is on " << up << endl;
        
        if(up == "heads")
        {
            heads++;
        }
        else if(up == "tails")
        {
            tails++;
        }
    }

    cout << endl;
    cout << "Total heads: " << heads << endl;
    cout << "Total tails: " << tails << endl;

    return 0;
}