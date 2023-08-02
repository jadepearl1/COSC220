//Jade Pearl
//Created: 10/4/2022
//Modified: 10/10/2022

#include "PreferredCustomer.h"
#include "CustomerData.h"
#include "PersonData.h"
#include <iostream>
#include <iomanip>

using namespace std;


//*******************
//Default Constructor
//*******************
PreferredCustomer::PreferredCustomer()
{
    purchasesAmount = 0.0;
    discountLevel = 0.0;
}


//
//Constructor
//



//***************************************
//Sets the purchasesAmount varaible value
//***************************************
void PreferredCustomer::setPurhcasesAmount(double pa)
{
    purchasesAmount = pa;
}


//***********************
//Sets the discount level
//***********************
void PreferredCustomer::setDiscountLevel(double pa)
{
    if(pa >= 2000)
        discountLevel = 0.10;
    else if(pa >= 1500)
        discountLevel = 0.07;
    else if(pa >= 1000)
        discountLevel = 0.06;
    else if(pa >= 500)
        discountLevel = 0.05;
    else
        discountLevel = 0.0;
}


//**************************************************************************
//PrintRecord function that calls the print record from the parent functions
//**************************************************************************
void PreferredCustomer::PrintRecord()
{
    CustomerData::PrintRecord();
    cout << "Purchases Amount: " << purchasesAmount << endl;
    cout << "Discount level: " << discountLevel*100 << "%" << endl;   
}



void PreferredCustomer::setup()
{
    CustomerData::setup();
    cout << "Input Purchases Amount: ";
    cin >> purchasesAmount;
    setDiscountLevel(purchasesAmount);
}