//Jade Pearl
//Date Created: 9/30/2022
//Date Modified: 10/3/2022

#ifndef NUMDAYS_H
#define NUMDAYS_H
//#include <iostream>
//#include <cmath>
//#include <iomanip>

using namespace std;

class NumDays
{
    protected:
        double hours; //represents # of hours worked
        double days; //stores the number of days
    public:
        NumDays();
        NumDays(double);

        void setNumHours(double);
        void setNumDays(double);
        double getNumHours(){
            return hours;          
        }
        double getNumDays(){
            return days;
        }

        double operator+ (const NumDays &);
        double operator- (const NumDays &);
        NumDays operator++(int); //postfix operator for ++
        NumDays operator++(); //prefix operator for ++
        NumDays operator--(int); //postfix operator for --
        NumDays operator--(); //prefix operator for --

};

#endif