#include<iostream>
#include "Course.h"
class NormalCourse : public Course 
{
public:
    NormalCourse() {};
    NormalCourse(string n, int level, int hour) : Course(n, level, hour)
    {
        code = name + "_N" + to_string(level);
    }
};