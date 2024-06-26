#include <iostream>
#include "Student.h"
#include "Course.h"
class SpecialStudent : public Student
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
		float sumOfCreditHours=0;
		for (int i = 0; i < 6; i++)
		{
			sumOfCreditHours += CourseList[i]->creditHours;
		}
		return sumOfCreditHours * 500;

	}
};