#include <iostream>
#include <string>

using namespace std;

bool isPal(const string&, int, int);

int main()
{
    int start = 0; //represents the beginning of the string
    int end = 0; //represents the end of the string
    string phrase;
    cout << "Enter a string, no spaces and all lower case: ";
    cin >> phrase;

    for(int i=0; i<phrase.size(); i++)
        end++;

    if(isPal(phrase, start, end-1))
        cout << phrase << " is a palindrome." << endl;
    else
        cout << phrase << " is not a palindrome." << endl;

    return 0;
}


bool isPal(const string& str, int startIndex, int endIndex)
{
    if (startIndex == endIndex) //if only one character in the string, then return true
        return true;
    
    else
    {
        if (str[startIndex] != str[endIndex])
            return false;
        
        else if (startIndex < endIndex+1)
            return isPal(str, startIndex+1, endIndex-1);
    }
    return true;
}