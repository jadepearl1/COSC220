#include <iostream>

using namespace std;

long fibBinRec(long);

int main()
{
    long num;
    cout << "Enter the number of fibonacci numbers you would like to see: ";
    cin >> num;

    cout << "The first " << num << " Fibonacci numbers are: " << endl;
    for (int i=0; i<num; i++)
		cout << fibBinRec(i) << " ";

    cout << endl;
    return 0;
}


long fibBinRec(long n)
{
    if(n<=1)
        return n;
    else
        return (fibBinRec(n-1) + fibBinRec(n-2));
}