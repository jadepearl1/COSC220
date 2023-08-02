//Jade Pearl
//Lab03IL COSC 220-002
//Date Created: 9/13/2022
//Date MOdified: 9/13/2022

#include <iostream>
#include "Circle.h" //needed for access to the Circle class
using namespace std;

int main()
{
    double rad; //holds the radius of the circle

	// Get radius from user
	cout << "Input the radius of your circle ";
	cin >> rad;

	// Create a Circle object.
	Circle circ(rad);

    circ.setRadius(rad);

	// Display the radius, area, diameter, and circumference of the circle
    cout << "The radius of the circle is " << circ.getRadius() << "." << endl;
    cout << "The area of the circle is " << circ.getArea() << "." << endl;
    cout << "The diameter of the circle is " << circ.getDiameter() << "." << endl;
    cout << "The circumference of the circle is " << circ.getCircumference() << "." << endl;
	return 0;
}