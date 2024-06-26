#pragma once
#include<iostream>
#include "Student.h"
#include "Course.h"
class GeneralStudent : public Student
{
	bool RegisterCourse(Course* course)
	{
		if (course->minStudentLevel > Level)
		{
			cout << "can't register more courses :/" << endl;
			return false;
		}
		else
		{
			return Student::RegisterCourse(course);
		}
	}
	float CalculateExpenses() override
	{
		return Level * 1000;
	}
};