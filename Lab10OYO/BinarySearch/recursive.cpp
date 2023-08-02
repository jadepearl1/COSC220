#include <iostream>
#include <cstdlib>

using namespace std;

int binSearch(const int [], int, int, int);

int main()
{
    int arr[10000];
    int first = 0;
    int last = 10000;
    srand(time(0));

    int num;
    for(int i=0; i<10000; i++)
    {
        num = rand()%50; //fills the array with numbers between 1 and 10000
        arr[i] = num;
    }

    int search;
    cout << "Enter a number between 1 and 50 that you want searched: ";
    cin >> search;

    int found;
    found = binSearch(arr, first, last, search);
    if (found != -1)
    {
        cout << search << " was found in the " << found << " index of the array" << endl;
    }
    else
        cout << search << " was not found in the array." << endl;
    
    return 0;
}


int binSearch(const int arr[], int first, int last, int target)
{
    int mid = (first+last)/2;
    if(first>last)
        return -1;
    if(target == arr[mid])
        return mid;
    if(target<arr[mid])
        return binSearch(arr, first, mid, target);
    else
        return binSearch(arr, mid+1, last, target);
}