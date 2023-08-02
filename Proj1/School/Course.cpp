//Jade Pearl
//Created: 10/3/2022
//Modified: 10/5/2022


#include <iostream>
#include <iomanip>

#include "Course.h"

using namespace std;


//*******************
//Default Constructor
//*******************
Course::Course()
{
    code = 120;
    name = "CSI";
    for (int i=0; i<3; i++)
        testsScore[i] = 0.0;
}


//***********
//Constructor
//***********
Course::Course(int c, string n, float ts[3]) //Constructor
{
    code = c;
    name = n;
    for(int i=0; i<3; i++)
        testsScore[i] = ts[i];
}



//sets the value of code
void Course::setCode(int c)
{
    code = c;
}



//sets the name string
void Course::setName(string n)
{
    name = n;
}


//***************************************
//sets the values in the testsScore array
//***************************************
void Course::setScores(float ts[])
{
    for(int i=0; i<3; i++)
        testsScore[i] = ts[i];
}


//**********************************************
//Overloads the << operator as a friend function
//**********************************************
ostream &operator<<(ostream &output, const Course &obj)
{
    output << "Course: " << obj.name << endl;
    output << "Course Code: " << obj.code << endl;
    output << "Course test scores: ";
    for(int i=0; i<3; i++)
    {
        output << obj.testsScore[i] << "  ";
    }
    output << endl;
    return output;
}