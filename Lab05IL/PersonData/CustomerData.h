//Jade Pearl
//Created: 10/4/2022
//Modified: 10/4/2022


#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H
#include <iostream>
#include <string>
#include "PersonData.h"

using namespace std;

class CustomerData:public PersonData
{
    protected:
        int customerNumber;
        bool mailingList;
    public:
        void setCustomerNumber(int);
        string getCustomerNumber(){
            string cust = to_string(customerNumber);
            return cust;
        }
        void setMailingList(bool);
        string getMailingList(){
            if(mailingList == true)
               return "Yes";
            else
                return "No";
        }
        void PrintRecord();
        string getRecord(){
            return (PersonData::getRecord() + " / C#: " + getCustomerNumber() + " / ML: " + getMailingList());
        }
};

#endif