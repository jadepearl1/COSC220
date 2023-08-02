//Jade Pearl
//Created: 10/4/2022
//Modified: 10/4/2022

#ifndef PERSONDATA_H
#define PERSONDATA_H

#include <iostream>
#include <string>

using namespace std;

class PersonData
{
    protected:
        string lastName;
        string firstName;
        string address;
        string city;
        string state;
        string zip;
        string phone;
    public:
        void setName(string, string);
        string getName(){
            return lastName + firstName;
        }
        void setAddress(string, string, string, string);
        string getAddress(){
            return address + city + state + zip;
        }
        void setPhone(string);
        string getPhone(){
            return phone;
        }
        void PrintRecord();
        string getRecord(){
            return (firstName + ", " + lastName + " / " + address + " / " + city + ", " + state + " " + zip + " / " + phone);
        }
};

#endif
