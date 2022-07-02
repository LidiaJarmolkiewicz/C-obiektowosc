#pragma once
#include<string>
#include "EmployeeList.hpp"

class University
{
	//Employee* employees = new Employee[100]; // nie mozemy jesli Employee jest abstrakcyjna klasa i/lub nie ma bezparametrowego konstruktora
	/*Employee** staff; */
	EmployeeList list;
public:
	double calculateEmployerCost();
	void printTeachingStaff();
	void printAllStaffNetIncomes(int hoursInMonth);
	void add(Employee* object);
};
class Student;
class Course
{
	std::string name;
	Employee* tutor;//EducationalEmployee jako klasa/warstwa posrednia
	StudentList list;
public:
	Course(std::string name);
	void setTutor(Employee* tutor);
	void addStudent(Student* student);
	void printAllCourses();
};
class Student
{
	std::string firstname;
	std::string secondname;
	//Course** courses = new Course * [101];
	CourseList list;
public:
	void signIn(Course* course);
	//void resign(Course* course);

};

class CourseList
{
	Course** courses;
	Course** resizeArray();
	void copyElements(Course** target);
	int count = 0;
	int maxStaffSize = 1;
public:
	CourseList();
	virtual ~CourseList();
	//EmployeeList(const EmployeeList& obj); //copy constructor
	//EmployeeList& operator=(const EmployeeList& obj); //copy assignment operator
	void add(Course* object);
	Course* get(int index);
	int getCount();
};

class StudentList
{
	Student** students;
	Student** resizeArray();
	void copyElements(Student** target);
	int count = 0;
	int maxStaffSize = 1;
public:
	StudentList();
	virtual ~StudentList();
	//EmployeeList(const EmployeeList& obj); //copy constructor
	//EmployeeList& operator=(const EmployeeList& obj); //copy assignment operator
	void add(Student* object);
	Student* get(int index);
	int getCount();
};
