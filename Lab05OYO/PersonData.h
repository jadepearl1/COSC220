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
        void setLastName(string last){
            lastName = last;
        }
        string getLastName(){
            return lastName;
        }
        void setFirstName(string first){
            firstName = first;
        }
        string getFirstName(){
            return firstName;
        }
        void setName(string, string);
        string getName(){
            return lastName + firstName;
        }
        void setStreetAddress(string add){
            address = add;
        }
        string getStreetAddress(){
            return address;
        }
        void setCity(string c){
            city = c;
        }
        string getCity(){
            return city;
        }
        void setState(string st){
            state = st;
        }
        string getState(){
            return state;
        }
        void setZip(string z){
            zip = z;
        }
        string getZip(){
            return zip;
        }
        void setPhone(string ph){
            phone = ph;
        }
        string getPhone(){
            return phone;
        }
        void setAddress(string, string, string, string);
        string getAddress(){
            return address + city + state + zip;
        }
        virtual void setup();
        virtual void PrintRecord();
        virtual string getRecord(){
            return (firstName + " " + lastName + " / " + address + " / " + city + ", " + state + " " + zip + " / " + phone);
        }
};

#endif