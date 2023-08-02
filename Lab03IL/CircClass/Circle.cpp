//Jade Pearl
//Lab03IL COSC 220-002
//Date Created: 9/13/2022
//Date MOdified: 9/13/2022

#include "Circle.h"
#include <iostream>
using namespace std;


//*************************************************
// Default constructor that sets the radius to 0.0
//*************************************************
Circle::Circle()
{
    radius = 0.0;
}


//**************************************************
//Constructor that accepts the radius as an argument
//**************************************************
Circle::Circle(double r)
{
    radius = r;
}


//************************************************************************
//set function that sets the value of the radius if greater than or = to 0
//************************************************************************
void Circle::setRadius(double r)
{
    if(r>=0)
    {
        radius = r;
    }
    else
    {
        cout << "Invalid radius. Radius set to 0." << endl;
        radius = 0.0;
    }
}


