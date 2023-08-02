//Jade Pearl
//Created: 10/5/2022
//Modified: 10/10/2022

#ifndef PREFERREDCUSTOMER_H
#define PREFERREDCUSTOMER_H
#include "CustomerData.h"
#include <string>
#include <iomanip>

using namespace std;

class PreferredCustomer : public CustomerData
{
    protected:
        double purchasesAmount;
        double discountLevel;
    public:
       PreferredCustomer(); //default constructor
       //PreferredCustomer(string, string, string, string, string, string, string, int, bool, double, double);
       void setPurhcasesAmount(double);
       double getPurchasesAmount(){
            return purchasesAmount;
       }
       void setDiscountLevel(double);
       double getDiscountLevel(){
            return discountLevel;
       }
     virtual void setup();
     virtual void PrintRecord();
     virtual string getRecord() {
          return (CustomerData::getRecord() + " / Account: $" + to_string(getPurchasesAmount())
               + " / Discount: " + to_string(getDiscountLevel()*100) + "%");
     }
};

#endif