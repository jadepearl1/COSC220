//Jade Pearl
//Created: 9/20/2022
//Modified: 9/21/2022

//Update of main.cpp from Lab04Files

#include <iostream>
#include "IntegerList.h"

using namespace std;

void PopulateList(IntegerList &L, int size)
{
    cout << "In PopulateList" << endl;
    for (int i = 0; i < size; i++)
        L[i] = i;  
    cout << "Out PopulateList" << endl;
}

void PopulateList2(IntegerList L, int size)
{
    cout << "In PopulateList2" << endl;
    for (int i = 0; i < size; i++)
        L[i] = i;
    cout << "Out PopulateList2" << endl;
}

int main()
{
    IntegerList l1(7);
    IntegerList l2(17);

    for (int i = 0; i < 7; i++)
        l1[i] = i * i;

    PopulateList2(l1, 7); 
    PopulateList(l2, 17);

    l1.displayList();
    l2.displayList();

    IntegerList l3;
    l3 = l1+l2;
    l3.displayList();

    l3[4] = 100;
    l3.displayList();

    IntegerList l4 = l3.sublist(3, 8);
    l4.displayList();

    IntegerList l5 = l3.sublist(8);
    l5.displayList();

    IntegerList l6 = l3.sublist(3, 800);
    l6.displayList();

    l6.resize(5);
    l4.resize(30);
    l6.displayList();
    l4.displayList();

    IntegerList l7 = l3.sort();
    l3.displayList();
    l7.displayList();

    IntegerList l8 = l7;
    l8.displayList();

    return 0;
}

//ANSWERS TO PART 2 Questions:

// a) PopulateList passes in a memory location of the IntegerList class object being passed in whereas
// PopulateList2 takes in the IntegerList object itself as a parameter. PopulateList2 also ends in accessing
// the Destructor and PopulateList does not enter the Destructor. These calls are different because once the
// IntegerList is constructed in PopulateList2, the memory of the original list was cleared so that l1 (which
// was passed to PopulateList2 initially) could be updated with new element values without it's size being altered.
// The cause of this is because of the Destructor being used after PopulateList2 was exited. The difference in the
// results is that l1 became a list that was not just counting 0-6 but counting in index^2 and l2 remained a list
// that counted from 0-16

// b) Output created from the two lines IntegerList l3; & l3 = l1 + l2;
//    In Default Constructor
//    In the + operator
//    In Constructor
//    Out the + operator
//    In Assignment Statement
//    In Copy Constructor
//    In Destructor
//    In Destructor
// This is the output because since l3 did not have any parameters, it was sent to a default constructor to create a new
// IntegerList 