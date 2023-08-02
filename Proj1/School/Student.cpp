//Jade Pearl
//Created: 10/3/2022
//Modified: 10/5/2022

#include <iostream>
#include <stdio.h>
#include "Course.h"
#include "Student.h"

using namespace std;


//*******************
//Default constructor
//*******************
Student::Student()
{

}


//***********
//Constructor
//***********
Student::Student(int i, string sn)
{
    id = i;
    stuName = sn;
}


//****************
//Copy Constructor
//****************
Student::Student(const Student &obj)
{
    id = obj.id;
    stuName = obj.stuName;
    for(int i=0; i<numCourses; i++)
    {
        *(courses + i) = *(obj.courses + i);
    }
}


//
//
//
const Student Student::operator=(const Student &obj)
{
    id = obj.id;
    stuName = obj.stuName;
    delete[] courses;
	courses = new Course[numCourses];
	for (int i=0; i<numCourses; i++)
		courses[i] = obj.courses[i];

	return *this;
}


//
//
//
ostream &operator<<(ostream &output, const Student &obj)
{
    output << "Name of Student: " << obj.stuName;
    output << "Student ID #: " << obj.id;
    output << "Course information: ";
    for(int i=0; i<obj.numCourses; i++)
        output << obj.courses[i];
    return output;
}


//*********
//Sets ID #
//*********
void Student::setID(int i)
{
    id = i;
}


//***********************
//Sets the student's name
//***********************
void Student::setStuName(string sn)
{
    stuName = sn;
}


void Student::setNumCourses(int n)
{
    numCourses = n;
}


//************************************
//Sets the courses in array of Courses
//************************************
void Student::setCourses(Course* c)
{
    courses = new Course[numCourses];
    courses = c;
    *courses = *c;
}


//*********************************
//adds a course to the course array
//*********************************
void Student::addCourse(Course a)
{
    Course *newArr = nullptr;
    newArr = new Course[10];
    for (int i=0; i<10; i++)
    {
        newArr[i].setCode(courses[i].getCode());
        newArr[i].setName(courses[i].getName());
        for(int j=0; j<3; j++)
            newArr[i].setScores(courses[i].getScores());
    }
    delete[] courses;
    courses = newArr;
    numCourses+=1;

    // int aCode;
    // string aName;
    // float aScores[3];
    for (int i=0; i<numCourses; i++)
    {
        if (i==(numCourses-1))
        {
            // cout << "Enter Course Code: ";
            // cin >> aCode;
            // a.setCode(aCode);
            courses[i].setCode(a.getCode());
            // cout << "Enter Course Name: ";
            // cin >> aName;
            // a.setName(aName);
            courses[i].setName(a.getName());
            // cout << "Enter Course Scores: ";
            // for (int j=0; j<3; j++)
            //     cin >> aScores[j];
            // a.setScores(aScores);
            courses[i].setScores(a.getScores());
        }
    }
    this->setCourses(courses);
}


//*******************************
//Deletes a course from the array
//*******************************
void Student::deleteCourse(Course a)
{
    Course *newArr = nullptr;
    newArr = new Course[numCourses];
    for (int i=0; i<numCourses; i++)
    {
        *(newArr+i) = *(courses+i);
    }
    int k;
    for (k=0; k<numCourses; k++)
    {
        if (newArr[k].getCode()==a.getCode() && newArr[k].getName()==a.getName() && newArr->getScores()==a.getScores())
            break;
    }
    if (k<numCourses)
    {
        numCourses-=1;
        for(int j=k; j<numCourses; j++)
            *(newArr+j) = *(newArr+(j+1));
    }
    
    delete[] courses;
    courses = newArr;
    this->setCourses(courses);
}