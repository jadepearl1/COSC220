//Jade Pearl
//Created: 10/4/2022
//Modified: 10/7/2022

#include <iostream>
#include <string>
#include "PersonData.h"
#include <iomanip>

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

void PersonData::PrintRecord(){
    cout << lastName << ", " << firstName << endl;
    cout << address << endl;
    cout << city << ", " << state << " " << zip << endl;
    cout << phone;
    cout << endl;
}



void PersonData::setup() {
    cout << "Input Last Name: ";
    cin >> lastName;
    cout << "Input First Name: ";
    cin >> firstName;
    cout << "Input Street Address: ";
    getline(cin, address); //ignores the \n
    getline(cin, address);
    cout << "Input City: ";
    getline(cin, city);
    cout << "Input State: ";
    cin >> state;
    cout << "Input Zip Code: ";
    cin >> zip;
    cout << "Input Phone Number: ";
    getline(cin, phone);
    getline(cin, phone);
}