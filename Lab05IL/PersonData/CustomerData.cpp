//Jade Pearl
//Created:
//Modified:

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

void CustomerData::PrintRecord(){
    cout << lastName << ", " << firstName << endl;
    cout << address << endl;
    cout << city << ", " << state << " " << zip << endl;
    cout << phone;
    cout << "Customer Number: " << customerNumber << endl;
    cout << "On The Mailing List: " << mailingList << endl << endl;
}