//Jade Pearl
//Created:
//Modified:

#include <iostream>
#include <string>
#include "PersonData.h"

using namespace std;

void PersonData::setName(string first, string last){
    lastName = last;
    firstName = first;
}

void PersonData::setAddress(string add, string c, string st, string z){
    address = add;
    city = c;
    state = st;
    zip = z;
}

void PersonData::setPhone(string ph){
    phone = ph;
}

void PersonData::PrintRecord(){
    cout << lastName << ", " << firstName << endl;
    cout << address << endl;
    cout << city << ", " << state << " " << zip << endl;
    cout << phone;
    cout << endl;
}