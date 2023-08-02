#include <iostream>
#include <cstdlib>

using namespace std;

int binSearch(const int [], int, int, int);

int main()
{
    const int SIZE = 10000;
    int arr[SIZE];
    int first = 0;
    int last = SIZE;
    srand(time(0));

    int num;
    for(int i=0; i<SIZE; i++)
    {
        num = rand()%50; //fills the array with numbers between 1 and 10000
        arr[i] = num;
    }

    int search;
    cout << "Enter a number between 1 and 50 that you want searched: ";
    cin >> search;

    int found;
    found = binSearch(arr, first, last, search);
    if (found >= 0 && found <= 10000)
    {
        cout << search << " was found in the " << found << " index of the array";
    }
    
    return 0;
}


int binSearch(const int arr[], int first, int last, int target)
{
    int mid;
    int midVal;
    int origLast = last;
    while (first < last)
    {
        mid = (first+last)/2;
        midVal = arr[mid];
        if(target == midVal)
            return mid;
        else if(target < midVal)
            last = mid;
        else
            first = mid+1;
    }
}
