#include<iostream>
#include "Course.h"
class SummerCourse : public Course
{
public:
    SummerCourse() {};
    SummerCourse(string n, int level, int hour) : Course(n, level, hour)
    {
        code = name + "_S" + to_string(level);
    }
};
