#pragma once
#include<iostream>
class Student
{
public:
	string studentName;
	string studentID;
	int Level;
	double Grades[6];
	Course* CourseList[6];
	static int noOfCourses;
	Student()
	{
		for (int i = 0; i < 6; i++)
		{
			CourseList[i] = nullptr;
		}

	}
	void printRegisteredCourses()
	{
		cout << "Registered Courses : " << endl;
		for (int i = 0; i < 6; i++)
		{
			cout << "Course : " << &CourseList[i] << "\n" << "Grade : " << Grades[i] << endl ;
		}
	}
	//pure virtual function
	virtual float CalculateExpenses() = 0;
	bool RegisterCourse(Course* course)
	{
		if (course != nullptr)  //trying to handle that course not found
		{
			if (noOfCourses < 6 && Level >= course->minStudentLevel)
			{
				CourseList[noOfCourses] = course;
				++noOfCourses;
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	double getTotalGPA() 
	{
		double totalGPA=0.0;
		double totalCreditHours = 0;
		for (int i = 0; i < noOfCourses; ++i) 
		{
			totalGPA += getCourseGPA(Grades[i]) * CourseList[i]->creditHours;
			totalCreditHours += CourseList[i]->creditHours;
		}
		return (totalGPA / totalCreditHours);

	}
	double getCourseGPA(double precentage)
	{
		if (precentage >= 93)
		{
			return 4.00;
		}
		else if(precentage>=90 && precentage <= 92)
		{
			return 3.70;
		}
		else if(precentage >= 87 && precentage <= 89)
		{
			return 3.30;
		}
		else if (precentage >= 83 && precentage <= 86)
		{
			return 3.00;
		}
		else if (precentage >= 80 && precentage <= 82)
		{
			return 2.70;
		}
		else if (precentage >= 77 && precentage <= 79)
		{
			return 2.30;
		}
		else if (precentage >= 73 && precentage <= 76)
		{
			return 2.00;
		}
		else if (precentage >= 70 && precentage <= 72)
		{
			return 1.70;
		}
		else if (precentage >= 67 && precentage <= 69)
		{
			return 1.30;
		}
		else if (precentage >= 63 && precentage <= 66)
		{
			return 1.00;
		}
		else if (precentage >= 60 && precentage <= 62)
		{
			return 0.70;
		}
		else if (precentage < 60)
		{
			return 0.00;
		}
	}
	void printStudentInfo() 
	{
		cout << "Student Name: " << studentName << endl;
		cout << "Student ID: " << studentID << endl;
		cout << "Student Level: " << Level << endl;
		cout << "Registered Courses: " << endl;
		for (int i = 0; i < noOfCourses; ++i) 
		{
			cout << "Course " << i + 1 << ": \n\tname: " << CourseList[i]->name
				<< "\n\tCode: " << CourseList[i]->code << "\n\tGrade: " << Grades[i]
				<< "\n\tLevel:" << CourseList[i]->minStudentLevel << "\n\tCreditHours:"
				<< CourseList[i]->creditHours << endl;
		}
	}
};
int Student::noOfCourses = 0;