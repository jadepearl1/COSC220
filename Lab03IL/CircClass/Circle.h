//Jade Pearl
//Lab03IL COSC 220-002
//Date Created: 9/13/2022
//Date MOdified: 9/13/2022
//specification file for Circle class

#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>

//Class declaration for Circle
class Circle
{
    private:
        double radius;
        double pi = 3.141592653589793;
    public:
        Circle(); //default constructor that sets the radius to 0.0
        Circle(double); //constructor which accepts the radius of the circle as an argument.
        void setRadius(double); //sets the value of the radius 
        double getRadius(){ //Returns the value of the radius
            return radius;
        }
        double getArea(){ //Returns the area which is pi * radius^2
            return pi * (radius * radius);
        }
        double getDiameter(){ //returns the diameter which is radius * 2
            return radius * 2;
        }
        double getCircumference(){ //Returns the circumference of the circle which is 2 * pi * r.
            return 2*pi*radius;
        } 
};
#endif