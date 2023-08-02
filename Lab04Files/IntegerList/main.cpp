#include <iostream>
#include "IntegerList.h"

using namespace std;

void PopulateList(IntegerList &L, int size)
{
    for (int i = 0; i < size; i++)
        L[i] = i;    
}

void PopulateList2(IntegerList L, int size)
{
    for (int i = 0; i < size; i++)
        L[i] = i;    
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
    l3 = l1 + l2;
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
