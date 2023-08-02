// Jade Pearl
// COSC 220-002 Lab 03 OYO
// Created: 9/14/2022
// Modified: 9/17/2022

#include <string>
#ifndef COIN_H
#define COIN_H
using namespace std;

class Coin
{
    private:
        string sideUp; //the variable that stores the condition of the coin flip
    public:
        Coin(); //constructor that will randomly decides what side of the coin is face up and pre-initiallizez the sideUp variable
        void toss(); //void function that will simulate the toss and sets sideUp according to the toss
        string getSideUp(){//string function that will return the state of sideUp
            return sideUp;
        }
};
#endif