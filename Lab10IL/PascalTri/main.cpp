#include <iostream>

using namespace std;

int choose(int, int); //takes two integers input by the user as arguments

int main()
{
    int n;
    int k;
    cout << "Enter n and k (integer) with a space between them: ";
    cin >> n;
    cin >> k;
    
    cout << n << " choose " << k << " = " << choose(n, k) << endl;
    return 0;
}


int choose(int n, int k)
{
    if (n == 0 || k == 0)
        return 1;
    else if(n<0 || k<0 || k>n)
        return 0;
    else if (n == k)
        return 1;
    else
        return(choose(n-1, k) + choose(n-1, k-1));
}