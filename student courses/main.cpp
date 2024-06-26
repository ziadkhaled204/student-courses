#include<iostream>
#include<string>
#include "Course.h"
#include "NormalCourse.h"
#include "SummerCourse.h"
#include "Student.h"
#include "GeneralStudent.h"
#include"SpecialStudent.h"
using namespace std;
Course* COURSES[] = { new NormalCourse("Math", 1, 2), new NormalCourse("Programming_1", 1, 3),
new NormalCourse("Technical_Writing", 1, 3), new NormalCourse("Electronics", 2, 4),
new NormalCourse("Data_Structures", 2, 3), new NormalCourse("OOP", 2, 3),
new NormalCourse("Algorithms", 3, 2), new NormalCourse("Operating_Systems", 3, 3),
new NormalCourse("Databases", 3, 3), new NormalCourse("Machine_Learning", 4, 3),
new NormalCourse("Compilers", 4, 4), new NormalCourse("Programming_Concepts", 4, 4),
new SummerCourse("Math", 1, 2), new SummerCourse("Compilers", 4, 4),
new SummerCourse("Algorithms", 3, 2), new SummerCourse("OOP", 2, 3) };
Course* searchCourse(string c)
{
	for (int i = 0; i < 18; i++)
	{
		if (COURSES[i]->code == c)
		{
			return COURSES[i];
		}
	}
	return nullptr;
}
int main()
{
	int NumOfStudents;
	cout << "Enter the number of Students : ";
	cin >> NumOfStudents;
	cout << "\n\n";
	Student* student;
	for (int i = 0; i < NumOfStudents; i++) //loop through number of students
	{
		//variables to be used;
		bool typeOfStudent;
		string name, id;
		int level;
		int numberOfcourses;
		//core of main
		cout << "Enter student type : ";
		cin >> typeOfStudent;
		if (typeOfStudent == 0)
		{
			student = new GeneralStudent();
		}
		else if(typeOfStudent==1)
		{
			student = new SpecialStudent();
		}
		else
		{
			cout << "you didn't choose the right type of student!";
			return 0;
		}
		cin.ignore();
		cout << "Enter student name: ";
		getline(cin, name);
		cout << "Enter student ID: ";
		cin >> id;
		cout << "Enter student level (1-4): ";
		cin >> level;
		student->studentName = name;
		student->Level = level;
		student->studentID=id;

		cout << "Number of courses to be registered : ";
		cin >> numberOfcourses;
		for (int j = 0; j < numberOfcourses; j++)  //loop to register courses
		{
			string courseCode;
			int	CourseGrade;
			cout << "Course" << j + 1 << " : " << endl;
			cout << "code : ";
			cin >> courseCode;
			if (student->RegisterCourse(searchCourse(courseCode)))
			{
				cout << "grade : ";
				cin >> CourseGrade;
				student->Grades[j] = CourseGrade;
			}
			else
			{
				cout << "You cannot register in this course :/" << endl;
			}
		}
		cout << "\n";
		student->printStudentInfo();  // this is a method in student class that i coded
		cout << "over all GPA: " << student->getTotalGPA() << endl;
		cout << student->CalculateExpenses() << " EGP " << endl;
		cout << "\n";
	}
	return 0;
}