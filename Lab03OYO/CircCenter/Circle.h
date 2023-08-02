//Jade Pearl
//Lab03IL COSC 220-002
//Date Created: 9/13/2022
//Date MOdified: 9/13/2022
//specification file for Circle class

#ifndef CIRCLE_H
#define CIRCLE_H

//Class declaration for Circle
class Circle
{
    private:
        double radius;
        double pi = 3.141592653589793;
        double x; //one of the center points of the circle
        double y; //the other center point of the circle
    public:
        Circle(); //default constructor that sets the radius to 0.0
        Circle(double); //constructor which accepts the radius of the circle as an argument.
        Circle(double, double, double); //constructor that accepts the x, y, and radius as arguments
        void setRadius(double); //sets the value of the radius 
        void setCenter(double, double); //sets the center values (x and y)
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
        double getCenterX(){
            return x;
        }
        double getCenterY(){
            return y;
        }
        bool collide(Circle);
};
#endif