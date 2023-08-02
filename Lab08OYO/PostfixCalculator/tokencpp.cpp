//Jade Pearl
//COSC 220 Lab 08 OYO
//Date modified: 10/30/2022
//Help received: Textbook and additional examples of stacks and queues and
//postfix implementations on geeksforgeeks.org

#include <iostream> 
#include <sstream>

#include "ListCollection.h"
#include "Stack.h"

using namespace std; 

int main() 
{ 
    // string input = "234 32 + 7 *";
	// Must have spaces between tokens.
 
	string input;
    cout << "Enter a postfix expression: ";
    getline(cin, input);
    
    ListCollection<string> tokens; 
    stringstream inputstream(input); 
    string token; 
    
    // Tokenizing w.r.t. space ' ' 
    while(getline(inputstream, token, ' ')) 
        tokens.pushBack(token);


    // Printing the token vector 
    cout << "Here is the stack: " << endl;
    for(int i = 0; i < tokens.size(); i++) 
        cout << tokens.getElement(i) << endl; 



    //postfix calculator that helps us do operations in a stack:
    Stack<double> stk; //create a templated class object that represents the stack. This will help with the calculations
                       //by allowing the program to use the functions in Stack.h

    for(int i=0; i<tokens.size(); i++) //make a for loop to read through the string
    {
        string token = tokens.getElement(i); //create a string variable called token that will hold the value to the current element that token is reading in the tokens stack
        if (token != " ") //the calculation of postfix is done whilst ignoring white space.
                          //if token holds a space, then the loop continues until token shows something that is not a space
        {
            if(token>="0" && token<="9") //if token is a digit, convert that token into a double and push it onto the new stack
            {
                double num = atof(token.c_str());
                stk.push(num); //Stack is first in last out so the element is pushed to the end of the new stack
            }
            //tokenize the "+,-,*,/" operators
            else if(token == "+")
            {
                //pop two doubles from the stack and push the sum of those two numbers to the top of the stack
                double num1 = stk.pop();
                double num2 = stk.pop();
                stk.push(num2 + num1);
                //in these operations it is important to make the left side double the second one that was added
                //because a stack uses first in, last out logic
            }
            else if(token == "-")
            {
                //pop 2 doubles and push their difference to the top of the stack
                double num1 = stk.pop();
                double num2 = stk.pop();
                stk.push(num2 - num1);
            }
            else if(token == "*")
            {
                //pop 2 doubles from the stack and push their product to the top of the stack
                double num1 = stk.pop();
                double num2 = stk.pop();
                stk.push(num2 * num1);
            }
            else if(token == "/")
            {
                //pop 2 doubles from the stack and push their quotients to the top of the stack
                double num1 = stk.pop();
                double num2 = stk.pop();
                stk.push(num2 / num1);
            }
        }
    }
    cout << "Value of the stack is: ";
    stk.displayStack(); //use the display function from Stack.h to print out the result of the calculation
    cout << endl;

    return 0;
}