//Jade Pearl
//Date Created: 9/30/2022
//Date Modified: 10/3/2022

#include <iostream>
#include <cmath>
#include <iomanip>
#include "NumDays.h"

using namespace std;

NumDays::NumDays()
{
    hours = 0;
    days = 0;
}

//****************************************
//Constrcutor that accepts number of hours
//****************************************
NumDays::NumDays(double h)
{
    hours = h;
}


//*********************************************
//member function that sets the amount of hours
//*********************************************
void NumDays::setNumHours(double h)
{
    hours = h;
}


//********************************************
//member function that sets the number of days
//********************************************
void NumDays::setNumDays(double h)
{
    days = hours / 8.0; //there are 8 hours in a typical work day, so #days are dependent on how many 8 hour shifts are worked
}


//*****************************************************
//Addition operator that adds two NumDays class objects
//*****************************************************
double NumDays::operator+(const NumDays &right)
{
    double sum;
    sum = hours+right.hours;
    return sum;
}


//*************************************************************
//Subtraction operator that subtracts two NumDays class objects
//*************************************************************
double NumDays::operator-(const NumDays &right)
{
    double diff;
    diff = hours-right.hours;
    return diff;
}


//***************************************************************************
//Postfix increment operator that increments number of hours and recalcs days
//***************************************************************************
NumDays NumDays::operator++(int h)
{
    hours = double(h);
    hours++;
    days = hours/8.0;
    return h;
}


//**************************************************************************
//Prefix increment operator that increments number of hours and recalcs days
//**************************************************************************
NumDays NumDays::operator++()
{
    hours++;
    days = hours/8.0;
    return hours;
}


//*******************************************************************************
//Postfix decrement operator that decrements the number of hours and recalcs days
//*******************************************************************************
NumDays NumDays::operator--(int h)
{
    hours = double(h);
    hours--;
    days = hours/8.0;
    return h;
}


//******************************************************************************
//Prefix decrement operator that decrements the number of hours and recalcs days
//******************************************************************************
NumDays NumDays::operator--()
{
    hours--;
    days = hours/8.0;
    return hours;
}