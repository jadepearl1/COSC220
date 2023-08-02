//Jade Pearl
//Created: 10/3/2022
//Modified: 10/5/2022

#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

using namespace std;


class Course
{
    protected:
        int code;
        string name;
        float testsScore[3];
    public:
        Course(); //Default Constructor
        Course(int, string, float[3]); //Constructor

        void setCode(int);
        int getCode(){
            return code;
        }
        void setName(string);
        string getName(){
            return name;
        }
        void setScores(float [3]);
        void getScores(){
            for(int i=0; i<3; i++)
                cout << testsScore[i];
        }

        friend ostream &operator<<(ostream &, const Course &);
};

#endif