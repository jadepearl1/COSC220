#include <iostream>
#include <stack>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    int lcBrack = 0;
    int rcBrack = 0;
    int lParen = 0;
    int rParen = 0;
    int lSqBr = 0;
    int rSqBr = 0;
    stack<char> exp;
    string stkin;

    cout << "Enter an expression: ";

    getline(cin, stkin);
    for(int i=0; i<stkin.size(); i++)
        exp.push(stkin[i]);
    
    
    char cursor;
    int sz = exp.size();
    for(int i=0; i<sz; i++)
    {
        cursor = exp.top();
        exp.pop();
        if(cursor == '{')
            lcBrack++;
        else if(cursor == '}')
            rcBrack++;
        else if(cursor == '(')
            lParen++;
        else if(cursor == ')')
            rParen++;
        else if(cursor == '[')
            lSqBr++;
        else if(cursor == ']')
            rSqBr++;
    }

    if((lcBrack == rcBrack) && (lParen == rParen) && (lSqBr == rSqBr))
        cout << "Delimiters are balanced." << endl;
    else
        cout << "Delimiters are not balanced." << endl;

    return 0;
}