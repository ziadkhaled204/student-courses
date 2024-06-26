#pragma once
#include<iostream>
#include<string>
using namespace std;
class Course
{
public:
    string name;
    string code;
    int minStudentLevel;
    int creditHours;
    Course()
    {
        name = "";
        minStudentLevel = 1;
        creditHours = 0;
    }
    Course(string n, int level, int hour)
    {
        name = n;
        minStudentLevel = level;
        creditHours = hour;

    }
    friend ostream& operator << (ostream& output, Course c)
    {
    output << " Course code :  " << c.code << endl;
    output << " Course name : " << c.name << endl;
    output << " Credit Hours : " << c.creditHours << endl;
    output << " Level : " << c.minStudentLevel << endl;
    return output;
    }
};  

