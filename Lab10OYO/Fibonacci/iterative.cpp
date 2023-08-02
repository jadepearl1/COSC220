#include <iostream>

using namespace std;

void fibIter(int);

int main()
{
    int num;
    cout << "Enter the number of fibinacci numbers you would like to see: ";
    cin >> num;
    cout << "The first " << num << " Fibonacci numbers are: " << endl;
    fibIter(num);
    cout << endl;
    return 0;
}


void fibIter(int n)
{
    long a = 0, b = 1, c = 0;
    for(int i=0; i<n; i++)
    {
        cout << a << " ";
        c = a+b;
        a = b;
        b = c;
    }
}