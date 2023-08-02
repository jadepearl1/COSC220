//Jade Pearl
//Lab03IL COSC 220-002
//Date Created: 9/13/2022
//Date MOdified: 9/18/2022

#include "Circle.h"
#include <iostream>
#include <cmath>
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


//*************************************************************
//set function that sets the coordinates of the circle's center
//*************************************************************
void Circle::setCenter(double X, double Y)
{
    if(x>=0 && y>=0)
    {
        x = X;
        y = Y;
    }
    else
    {
        x = 0;
        y = 0;
    }
}


//*********************************************************************************
//Member function that compares two circles and reports whether or not they collide
//*********************************************************************************
bool Circle::collide(Circle j)
{
    
    double radSum = radius + j.radius; //takes the sum of the two radii of the circle
    double distance = sqrt(pow(x - j.x, 2) + pow(y - j.y, 2));
    if ((distance <= radSum) && (x != j.x) && (y != j.y)) //make sure a circle isn't "colliding with itself"
    {
        return true;
    }
    else
        return false;
}