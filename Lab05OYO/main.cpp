//Jade Pearl
//Created: 10/4/2022
//Modified: 10/10/2022


#include <iostream>
#include <string>
#include <iomanip>
#include "PersonData.h"
#include "CustomerData.h"
#include "PreferredCustomer.h"

using namespace std;

void printMenu();

int main() {

    PersonData *arr[10];
    int databaseSize = 0;


    int option;
    while (true) {
        printMenu();
        cin >> option;
        cout << endl;
        switch (option) {
            case 1: //adds Personal
                arr[databaseSize] = new PersonData();
                arr[databaseSize]->setup();
                databaseSize++;
                break;
            case 2: // add Customer
                arr[databaseSize] = new CustomerData();
                arr[databaseSize]->setup();
                databaseSize++;
                break;
            case 3: // add preferred
                arr[databaseSize] = new PreferredCustomer();
                arr[databaseSize]->setup();
                databaseSize++;
                break;
            case 4: // view long
                for(int i=0; i<databaseSize; i++)
                {
                    arr[i]->PrintRecord();
                    cout << endl << endl;
                }
                break;
            case 5: //view short
                for(int i=0; i<databaseSize; i++)
                {
                    cout << arr[i]->getRecord() << endl;
                }
                break;
            case 6: //quit
                return 0;
        }
        cout << endl;
    }
}

void printMenu()
{
    cout << "1. Add Personal Data Object" << endl;
    cout << "2. Add Customer Data Object" << endl;
    cout << "3. Add Preferred Customer Data Object" << endl;
    cout << "4. View Database Long Form" << endl;
    cout << "5. View Database Short Form" << endl;
    cout << "6. Quit" << endl;
    cout << "Choice: ";
}
