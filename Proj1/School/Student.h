//Jade Pearl
//Created: 10/3/2022
//Modified: 10/5/2022

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include "Course.h"

using namespace std;

class Student : public Course
{
    private:
        int id; //7 digit student id
        string stuName; // string representing a student's name
        Course *courses; //pointer to an array of courses
        int numCourses; //represents number of courses a student has
    public:
        Student(); //Default constructor is empty DO NOTHING
        Student(int, string); //Constructor accepts id and name as arguments
        Student(const Student &); //Copy Constructor
        const Student operator=(const Student &);
        friend ostream &operator<<(ostream &, const Student &);
        
        void setID(int);
        int getID(){
            return id;
        }
        void setStuName(string);
        string getStuName(){
            return stuName;
        }
        void setNumCourses(int);
        int getNumCourses(int){
            return numCourses;
        }
        void setCourses(Course*);
        const Course* getCourses(){
            return courses;
        }

        void addCourse(Course); //adds course to course array
        void deleteCourse(Course); //deletes course from course array
};

#endif