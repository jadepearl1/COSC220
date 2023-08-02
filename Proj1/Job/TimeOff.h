//Jade Pearl
//Created: 9/30/2022
//Modified: 10/3/2022

#ifndef TIMEOFF_H
#define TIMEOFF_H
#include <iostream>
//#include <string>
#include "NumDays.h"
using namespace std;

class TimeOff:public NumDays
{
    private:
        NumDays maxSickDays; //records maximum sick leave days an employee can take
        NumDays sickTaken; // records number of sick leave days taken by the employee
        NumDays maxVacation; //records max # paid vacation days that can be taken
        NumDays vacTaken; //records number of vacation days already taken
        NumDays maxUnpaid; //records maximum number of unpaid vacation days an employee can take
        NumDays unpaidTaken; //records number of unpaid vacation days already taken by employee
        string name; //holds the name of the employee
        int id; //holds ID # value for employee
    public:
        TimeOff(string, int, double, double, double); //Constructor takes name, id, sick HOURS taken, vacation HOURS taken, and unpaid HOURS taken
        
        void setName(string);
        string getName(){
            return name;    
        }
        void setID(int);
        int getID(){
            return id;
        }
        void setMaxSick(double);
        NumDays getMaxSick(){
            return maxSickDays;
        }
        void setSickTaken(double);
        NumDays getSickTaken(){
            return sickTaken;
        }
        
        void setMaxVac(double);
        NumDays getMaxVac(){
            return maxVacation; 
        }
        void setVacTaken(double);
        NumDays getVacTaken(){
            return vacTaken;
        }
        void setMaxUnpaid(double);
        NumDays getMaxUnpaid(){
            return maxUnpaid;
        }
        void setUnpaidTaken(double);
        NumDays getUnpaidTaken(){
            return unpaidTaken;
        }
};

#endif