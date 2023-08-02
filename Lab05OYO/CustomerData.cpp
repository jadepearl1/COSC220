//Jade Pearl
//Created: 10/4/2022
//Modified: 10/7/2022

#include <iostream>
#include <string>
#include "CustomerData.h"

using namespace std;

void CustomerData::setCustomerNumber(int c){
    customerNumber = c;
}

void CustomerData::setMailingList(bool m){
    mailingList = m;
}

void CustomerData::PrintRecord()
{
    PersonData::PrintRecord();
    cout << "Customer Number: " << customerNumber << endl;
    cout << "On The Mailing List: ";
    if(mailingList == false)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}



void CustomerData::setup() {
    PersonData::setup();
    char mailing;
    cout << "Input Customer Number: ";
    cin >> customerNumber;
    cout << "Do they wish to be on the mailing list? (Y/N): ";
    cin >> mailing;
    if(mailing == 'Y' || mailing == 'y')
        setMailingList(true);
    else if (mailing == 'N' || mailing == 'n')
        setMailingList(false);
}