//Jade Pearl
//Lab09IL

#include <iostream> 
#include <sstream>
#include <stack>
#include <queue>

using namespace std;

stack<string> stokenPostfix(stack<string> &);
void postfixCalc(string, stack<string> &);
queue<string> qtokenPostfix(queue<string> &);
void qpostCalc(string, queue<string> &);

int main() 
{
    string stkin, qin;
    cout << "Input a stack: ";
    getline(cin, stkin);
    stack<string> tok1;
    stringstream stkinputstream(stkin);
    string stkToken;
    while(getline(stkinputstream, stkToken, ' '))
        tok1.push(stkToken);

    stack<string> tokPost1 = stokenPostfix(tok1);
    cout << "Value of the stack is: ";
    while(!tok1.empty())
    {
        cout << tok1.top() << " ";
        tok1.pop();
    }
    cout << endl << endl;

    cout << "Input a queue: ";
    getline(cin, qin);
    queue<string> tok2;
    stringstream qinputstream(qin);
    string qToken;
    while(getline(qinputstream, qToken, ' '))
        tok2.push(qToken);

    queue<string> tokPost2 = qtokenPostfix(tok2);
    cout << "Value of the queue is: ";
    while(!tok2.empty())
    {
        cout << tok2.front() << " ";
        tok2.pop();
    }

    return 0;
}


stack<string> stokenPostfix(stack<string> &obj)
{
    while(obj.size() >= 3)
    {
        string n1 = obj.top();
        obj.pop();
        if(n1 == "+" || n1 == "-" || n1 == "*" || n1 == "/")
        {
            string n2 = obj.top();
            obj.pop();
            if(n2 == "+" || n2 == "-" || n2 == "*" || n2 == "/")
            {
                postfixCalc(n2, obj);
                obj.push(n1);
            }
            else
            {
                string n3 = obj.top();
                obj.pop();
                if(n3 == "+" || n3 == "-" || n3 == "*" || n3 == "/")
                {
                    postfixCalc(n3, obj);
                    obj.push(n2);
                    obj.push(n1);
                }
                else
                {
                    obj.push(n3);
                    obj.push(n2);
                    postfixCalc(n1, obj);
                }
            }
        }
    }
    return obj;
}

void postfixCalc(string tok, stack<string> &obj)
{
    if(tok == "+")
    {
        string t1 = obj.top();
        obj.pop();
        string t2 = obj.top();
        obj.pop();

        double num1 = atof(t1.c_str());
        double num2 = atof(t2.c_str());
        double sum = num2 + num1;
        obj.push(to_string(sum));
    }
    else if(tok == "-")
    {
        string t1 = obj.top();
        obj.pop();
        string t2 = obj.top();
        obj.pop();

        double num1 = atof(t1.c_str());
        double num2 = atof(t2.c_str());
        double diff = num2 - num1;
        obj.push(to_string(diff));
    }
    else if(tok == "*")
    {
        string t1 = obj.top();
        obj.pop();
        string t2 = obj.top();
        obj.pop();

        double num1 = atof(t1.c_str());
        double num2 = atof(t2.c_str());
        double prod = num2 * num1;
        obj.push(to_string(prod));
    }
    else if(tok == "/")
    {
        string t1 = obj.top();
        obj.pop();
        string t2 = obj.top();
        obj.pop();

        double num1 = atof(t1.c_str());
        double num2 = atof(t2.c_str());
        double quotient = num2 / num1;
        obj.push(to_string(quotient));
    }
}




//for queues
queue<string> qtokenPostfix(queue<string> &obj)
{
   while(obj.size() >= 3)
    {
        string n1 = obj.front();
        obj.pop();
        if(n1 == "+" || n1 == "-" || n1 == "*" || n1 == "/")
        {
            string n2 = obj.front();
            obj.pop();
            if(n2 == "+" || n2 == "-" || n2 == "*" || n2 == "/")
            {
                qpostCalc(n2, obj);
                obj.push(n1);
            }
            else
            {
                string n3 = obj.front();
                obj.pop();
                if(n3 == "+" || n3 == "-" || n3 == "*" || n3 == "/")
                {
                    qpostCalc(n3, obj);
                    obj.push(n2);
                    obj.push(n1);
                }
                else
                {
                    obj.push(n3);
                    obj.push(n2);
                    qpostCalc(n1, obj);
                }
            }
        }
        else
        {
            obj.push(n1);
        }
    }
    return obj; 
}

void qpostCalc(string t, queue<string> &obj)
{
    if(t == "+")
    {
        string t1 = obj.front();
        obj.pop();
        string t2 = obj.front();
        obj.pop();
        double num1 = atof(t1.c_str());
        double num2 = atof(t2.c_str());
        double sum = num1 + num2;
        obj.push(to_string(sum));
    }
    if(t == "-")
    {
        string t1 = obj.front();
        obj.pop();
        string t2 = obj.front();
        obj.pop();
        double num1 = atof(t1.c_str());
        double num2 = atof(t2.c_str());
        double diff = num1 - num2;
        obj.push(to_string(diff));
    }
    if(t == "*")
    {
        string t1 = obj.front();
        obj.pop();
        string t2 = obj.front();
        obj.pop();
        double num1 = atof(t1.c_str());
        double num2 = atof(t2.c_str());
        double prod = num1 * num2;
        obj.push(to_string(prod));
    }
    if(t == "/")
    {
        string t1 = obj.front();
        obj.pop();
        string t2 = obj.front();
        obj.pop();
        double num1 = atof(t1.c_str());
        double num2 = atof(t2.c_str());
        double quot = num1 / num2;
        obj.push(to_string(quot));
    }
}