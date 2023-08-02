//Jade Pearl
//Date Created: 9/30/2022
//Date Modified: 10/3/2022

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include "NumDays.h"
#include "TimeOff.h"

using namespace std;

int main()
{
    double months;
    NumDays maxSick;
    NumDays maxVac;
    NumDays maxUn;
    NumDays sickT;
    NumDays vacT;
    NumDays unT;
    //Enter a TimeOff object representing an employee sending arguments in the order: name(string), id(int), sick hours taken (double), vacation hours taken (double), and unpaid hours taken (double)
    TimeOff e1("Jade", 13579, 6.00, 100.00, 5.00);
    cout << "How many months has the employee worked with the company? ";
    cin >> months;
    
    e1.setMaxSick(months);
    e1.setMaxVac(months);
    e1.setMaxUnpaid(months);

    maxSick = e1.getMaxSick();
    maxVac = e1.getMaxVac();
    maxUn = e1.getMaxUnpaid();
    sickT = e1.getSickTaken();
    vacT = e1.getVacTaken();
    unT = e1.getUnpaidTaken();

    
    cout << "Associate name: "<< e1.getName() << endl;
    cout << "Associate Number: " << e1.getID() << endl;
    cout << "Months worked: " << months << endl;
    
    //show days and hours (days times 8 for 8 hours/day for x amount of days)
    cout << "Total sick days accumulated: " << maxSick.getNumDays() << " (" << maxSick.getNumHours() << " hours)" << endl;
    cout << "Total paid vacation days accumulated: " << maxVac.getNumDays() << " (" << maxVac.getNumHours() << " hours)" << endl;
    cout << "Total unpaid days accumulated: " << maxUn.getNumDays() << " (" << maxUn.getNumHours() << " hours)" << endl;
    
    cout << "Sick days used: " << sickT.getNumDays() << " (" << sickT.getNumHours() << " hours)" << endl;
    cout << "Vacation days used: " << vacT.getNumDays() << " (" << vacT.getNumHours() << " hours)" << endl;
    cout << "Unpaid days used: " << unT.getNumDays() << " (" << unT.getNumHours() << " hours)" << endl;

    cout << "They have " << (maxSick.getNumDays()-sickT.getNumDays()) << " sick days left ("
        << (maxSick.getNumHours()-sickT.getNumHours()) << " hours)" << endl;
    cout << "They have " << (maxVac.getNumDays()-vacT.getNumDays()) << " vacation days left ("
        << (maxVac.getNumHours()-vacT.getNumHours()) << " hours)" << endl;
    cout << "They have " << (maxUn.getNumDays()-unT.getNumDays()) << " unpaid days left ("
        << (maxUn.getNumHours()-unT.getNumHours()) << " hours)" << endl;



    return 0;
}