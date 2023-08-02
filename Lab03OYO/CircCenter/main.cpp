//Jade Pearl
//Lab03IL COSC 220-002
//Date Created: 9/13/2022
//Date MOdified: 9/13/2022

#include <iostream>
#include "Circle.h" //needed for access to the Circle class
#include <time.h>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
	srand(time(0));

	ofstream outfile;
	outfile.open("report.txt"); //creates an output file for listing all colliding circles

    double rad, cenX, cenY; //holds radius and center values

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
    cout << "The circumference of the circle is " << circ.getCircumference() << "." << endl << endl;

	cout << "The program will now create 1000 circles to compare." << endl;
	int size = 1000;
	Circle *circArray = new Circle[size];

	for(int i=0; i<size; i++)
	{
		rad = rand()%2 + 1;
		cenX = rand()%40 - 20;
		cenY = rand()%40 - 20;
		circArray[i].setRadius(rad);
		circArray[i].setCenter(cenX,cenY);
	}

	bool collision;
	int numColl = 0; //counts the number of collisions between circles
	for (int i=0; i<size; i++)
	{
		for (int j=i+1; j<size; j++)
		{
			collision = circArray[i].collide(circArray[j]);
			if (collision == true)
			{
				numColl++;
				outfile << "Circles " << i << " and " << j << " collide." << endl;
			}
		}
	}

	cout << "There were " << numColl << " circle collisions." << endl;
	cout << "Check for the list of colliding circles in the output file 'report.txt'." << endl;
	outfile.close();

	return 0;
}