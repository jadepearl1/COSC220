// Specification file for the FeetInches class
#ifndef FEETINCHES_H
#define FEETINCHES_H

#include <iostream>
using namespace std;

class FeetInches;	// Forward Declaration

// Function Prototypes for Overloaded Stream Operators
ostream &operator << (ostream &, const FeetInches &);
istream &operator >> (istream &, FeetInches &);

// The FeetInches class holds distances or measurements
// expressed in feet and inches.

class FeetInches
{
  private:
    int feet;        // To hold a number of feet
    int inches;      // To hold a number of inches
    void simplify(); // Defined in FeetInches.cpp
  public:
    // Constructor
    FeetInches(int f = 0, int i = 0)
    {
        feet = f;
        inches = i;
        simplify();
    }

    // Mutator functions
    void setFeet(int f)
    {
        feet = f;
    }

    void setInches(int i)
    {
        inches = i;
        simplify();
    }

    // Accessor functions
    int getFeet() const
    {
        return feet;
    }

    int getInches() const
    {
        return inches;
    }

    // Overloaded operator functions
    FeetInches operator + (const FeetInches &); // Overloaded +
    FeetInches operator - (const FeetInches &); // Overloaded -
    FeetInches operator ++ ();					// Prefix ++
    FeetInches operator ++ (int);				// Postfix ++
    bool operator > (const FeetInches &);		// Overloaded >
    bool operator < (const FeetInches &);		// Overloaded <
    bool operator == (const FeetInches &);		// Overloaded ==
    bool operator != (const FeetInches &);		// Overloaded ==

    // Conversion functions
    operator double();
    operator int();

    // Friends
    friend ostream &operator << (ostream &, const FeetInches &);
    friend istream &operator >> (istream &, FeetInches &);
};


void FeetInches::simplify()
{
    if (inches >= 12)
    {
        feet += (inches / 12);
        inches = inches % 12;
    }
    else if (inches < 0)
    {
        feet -= ((abs(inches) / 12) + 1);
        inches = 12 - (abs(inches) % 12);
    }
}

//**********************************************
// Overloaded binary + operator.               *
//**********************************************

FeetInches FeetInches::operator + (const FeetInches &right)
{
    FeetInches temp;

    temp.inches = inches + right.inches;
    temp.feet = feet + right.feet;
    temp.simplify();
    return temp;
}

//**********************************************
// Overloaded binary - operator.               *
//**********************************************

FeetInches FeetInches::operator - (const FeetInches &right)
{
    FeetInches temp;

    temp.inches = inches - right.inches;
    temp.feet = feet - right.feet;
    temp.simplify();
    return temp;
}

//*************************************************************
// Overloaded prefix ++ operator. Causes the inches member to *
// be incremented. Returns the incremented object.            *
//*************************************************************

FeetInches FeetInches::operator ++ ()
{
    ++inches;
    simplify();
    return *this;
}

//***************************************************************
// Overloaded postfix ++ operator. Causes the inches member to  *
// be incremented. Returns the value of the object before the   *
// increment.                                                   *
//***************************************************************

FeetInches FeetInches::operator ++ (int)
{
    FeetInches temp(feet, inches);

    inches++;
    simplify();
    return temp;
}

//************************************************************
// Overloaded > operator. Returns true if the current object *
// is set to a value greater than that of right.             *
//************************************************************

bool FeetInches::operator > (const FeetInches &right)
{
    bool status;

    if (feet > right.feet)
        status = true;
    else if (feet == right.feet && inches > right.inches)
        status = true;
    else
        status = false;

    return status;
}

//************************************************************
// Overloaded < operator. Returns true if the current object *
// is set to a value less than that of right.                *
//************************************************************

bool FeetInches::operator < (const FeetInches &right)
{
    bool status;

    if (feet < right.feet)
        status = true;
    else if (feet == right.feet && inches < right.inches)
        status = true;
    else
        status = false;

    return status;
}

//*************************************************************
// Overloaded == operator. Returns true if the current object *
// is set to a value equal to that of right.                  *
//*************************************************************

bool FeetInches::operator == (const FeetInches &right)
{
    bool status;

    if (feet == right.feet && inches == right.inches)
        status = true;
    else
        status = false;

    return status;
}

//*************************************************************
// Overloaded != operator. Returns true if the current object *
// is set to a value equal to that of right.                  *
//*************************************************************

bool FeetInches::operator != (const FeetInches &right)
{
    bool status;

    if (feet != right.feet || inches != right.inches)
        status = true;
    else
        status = false;

    return status;
}

//********************************************************
// Overloaded << operator. Gives cout the ability to     *
// directly display FeetInches objects.                  *
//********************************************************

ostream &operator<<(ostream &strm, const FeetInches &obj)
{
    strm << obj.feet << " feet, " << obj.inches << " inches";
    return strm;
}

//********************************************************
// Overloaded >> operator. Gives cin the ability to      *
// store user input directly into FeetInches objects.    *
//********************************************************

istream &operator >> (istream &strm, FeetInches &obj)
{
    // Prompt the user for the feet.
    cout << "Feet: ";
    strm >> obj.feet;

    // Prompt the user for the inches.
    cout << "Inches: ";
    strm >> obj.inches;

    // Normalize the values.
    obj.simplify();

    return strm;
}

//*************************************************************
// Conversion function to convert a FeetInches object         *
// to a double.                                               *
//*************************************************************

FeetInches::operator double()
{
    double temp = feet;

    temp += (inches / 12.0);
    return temp;
}

//*************************************************************
// Conversion function to convert a FeetInches object         *
// to an int.                                                 *
//*************************************************************

FeetInches:: operator int()
{
    return feet;
}

#endif