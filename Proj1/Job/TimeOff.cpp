//Jade Pearl
//Created: 9/30/2022
//Modified: 10/3/2022

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include "TimeOff.h"

using namespace std;


//*****************************************************
//Constructor that sets all varibles and member objects
//*****************************************************
TimeOff::TimeOff(string n, int i, double sickT, double vacayT, double nonPayT)
{
    name = n;
    id = i;
    setSickTaken(sickT);
    setVacTaken(vacayT);
    setUnpaidTaken(nonPayT);
}

    

void TimeOff::setName(string n){
    name = n;
}


void TimeOff::setID(int i){
    id = i;
}


void TimeOff::setMaxSick(double maxSick){
    maxSick = 8 * maxSick; //8 hours sick time a month
    maxSickDays.setNumHours(maxSick);
    maxSickDays.setNumDays(maxSick);
}


void TimeOff::setSickTaken(double sick){
    sickTaken.setNumHours(sick);
    sickTaken.setNumDays(sick);
}


void TimeOff::setMaxVac(double months){
    double maxVac = months * 12;
    if (maxVac>240) //cannot exceed 240 hours
    {
        maxVacation.setNumHours(240);
        maxVacation.setNumDays(240);
    }
    else
    {
        maxVacation.setNumHours(maxVac);
        maxVacation.setNumDays(maxVac);
    }
}


void TimeOff::setVacTaken(double vac){
    vacTaken.setNumHours(vac);
    vacTaken.setNumDays(vac);
}


void TimeOff::setMaxUnpaid(double months){
    double maxUn = months * 8; //The programmer decided to go off of there being 8 max unpaid hours allocated per month of work
    maxUnpaid.setNumHours(maxUn);
    maxUnpaid.setNumDays(maxUn);
}


void TimeOff::setUnpaidTaken(double nopay){
    unpaidTaken.setNumHours(nopay);
    unpaidTaken.setNumDays(nopay);
}