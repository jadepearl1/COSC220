#include <iostream>

using namespace std;

long fibLinRec(long, long, long);

int main()
{
    long num;
    cout << "Enter the number of fibonacci numbers you would like to see: ";
    cin >> num;

    cout << "The first " << num << " Fibonacci numbers are: " << endl;
    for (int i=0; i<num; i++)
		cout << fibLinRec(1, 1, i) << " ";
    cout << endl;
    return 0;
}

long fibLinRec(long i, long j, long n)
{
    if(n==0)
        return 0;
    if(n<=2)
        return j;
    return fibLinRec(j, i+j, n-1); 
}