#include <iostream>
#include "FeetInches.h"
#include "miniDList.h"
#include "miniDListQueue.h"
#include "miniDListStack.h"
#include "miniArrayQueue.h"
#include "miniArrayStack.h"
#include "RuntimeException.h"

int main()
{
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "FeetInches Using Doubly linked Lists and Arrays" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;

    cout << "Test with DList" << endl;
	miniDList<FeetInches> l1;
    FeetInches a(5,7);
    FeetInches b(3,9);
    FeetInches c(4,11);
    FeetInches d(5,10);
	cout << l1.size() << endl;
	l1.addFront(a);
	l1.addFront(b);
	l1.display();
	cout << l1.size() << endl << endl;
	l1.addBack(c);
	l1.addBack(d);
	l1.display();
	cout << l1.size() << endl;
	l1.removeFront();
	l1.removeFront();
	l1.removeBack();
	l1.display();
	cout << l1.size() << endl << endl;


	cout << "Test with ArrayStack" << endl;
    miniArrayStack<FeetInches> iArrS; // TODO
    FeetInches e(6,2);
    FeetInches f(4,6);
    FeetInches g(7,0);
    FeetInches h(6,5);
	iArrS.push(e);
	iArrS.push(f);
	iArrS.push(g);
	iArrS.push(h);
	cout << iArrS.getTop() << endl;
	iArrS.printStack();
	iArrS.pop();
	iArrS.printStack();
	cout << endl << endl;


    cout << "Test with DListStack" << endl;
	miniDListStack<FeetInches> dDLStack; // TODO
    FeetInches i(9,1);
    FeetInches j(5,8);
    FeetInches k(3,9);
    FeetInches el(4,1);
	dDLStack.push(i);
	dDLStack.push(j);
	dDLStack.push(k);
	dDLStack.push(el);
	cout << dDLStack.top() << endl;
	dDLStack.printStack();
	dDLStack.pop();
	dDLStack.printStack();
	cout << endl << endl;


    cout << "Test with DListQueue" << endl;
	miniDListQueue<FeetInches> iDLQ; // TODO
    FeetInches m(7,3);
    FeetInches n(4,10);
    FeetInches o(5,2);
	iDLQ.enqueue(m);
	iDLQ.enqueue(n);
	iDLQ.enqueue(o);
	cout << iDLQ.front() << endl;
	miniDListQueue<FeetInches> iDLQ2 = iDLQ;
	iDLQ.printQueue();
	iDLQ2.printQueue();
	iDLQ.dequeue();
	iDLQ.dequeue();
	iDLQ.printQueue();
    cout << endl << endl;


    cout << "Test with ArrayQueue" << endl;
	miniArrayQueue<FeetInches> dArrQ;
    FeetInches p(6,9);
    FeetInches q(7,1);
    FeetInches r(4,9);
	dArrQ.enqueue(p);
	dArrQ.enqueue(q);
	dArrQ.enqueue(r);
	cout << dArrQ.getFront() << endl;
	miniArrayQueue<FeetInches> dArrQ2;
	dArrQ2 = dArrQ;
	dArrQ.printQueue();
	dArrQ2.printQueue();
	dArrQ.dequeue();
	dArrQ.dequeue();
	dArrQ.printQueue();
	dArrQ.dequeue();
    dArrQ.dequeue();
	return 0;
}