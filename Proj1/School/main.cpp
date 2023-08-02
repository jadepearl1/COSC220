//Jade Pearl
//Created: 10/3/2022
//Modified: 10/7/2022


#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include "Course.h"
#include "Student.h"


using namespace std;

int main()
{
    int numID;
    string sName;
    int numClasses; //number of courses a student has

    Student s1;
    cout << "Input Student First Name: ";
    cin >> sName;
    cout << "What is the student ID #?: ";
    cin >> numID;
    cout << "Input number of courses: ";
    cin >> numClasses;

    s1.setStuName(sName);
    s1.setID(numID);
    s1.setNumCourses(numClasses);

    Course *classes = nullptr;
    classes = new Course[numClasses];
    string className;
    int classID;
    float classScores[3];

    for(int i=0; i<numClasses; i++)
    {
        cout << "Enter course code: ";
        cin >> classID;
        classes[i].setCode(classID);
        cout << "Enter course name: ";
        cin >> className;
        classes[i].setName(className);
        cout << "Enter 3 test scores: ";
        for (int j=0; j<3; j++)
            cin >> classScores[j];
        classes[i].setScores(classScores);
    }
    s1.setCourses(classes);

    Student s2 = new Student;

    s2.setStuName("Shawn");
    s2.setID(2713001);
    Course two;
    two.setCode(120);
    two.setName("COSC");
    float courseTwo[3] = {90.0, 89.7, 78.8};
    two.setScores(courseTwo);
    s2.addCourse(two);


    Student s3 = new Student;
    s3.deleteCourse(classes[numClasses]); //removes the last class in the student's course list

    return 0;
}
