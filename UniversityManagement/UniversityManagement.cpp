#pragma once
#include <iostream>
#include "UniversityManagement.hpp"

double University::calculateEmployerCost()
{
	double sum = 0;
	for (int i = 0; i < list.getCount(); ++i)
	{
		sum += list.get(i)->calculateEmployerCost();
	}
	return sum;
}

void University::printTeachingStaff()
{
	for (int i = 0; i < list.getCount(); ++i)
	{
		//if(staff[i]->isTeachingStaff())
		if (list.get(i)->isTeachingStaff())
			std::cout << *list.get(i) << std::endl;
	}
}

void University::printAllStaffNetIncomes(int hoursInMonth)
{
	for (int i = 0; i < list.getCount(); ++i)
	{
		std::cout << *list.get(i) << " - " << list.get(i)->getEmployeeNetSalary(hoursInMonth) << std::endl;
	}

}

void University::add(Employee* object)
{
	list.add(object);
}


void Course::setTutor(Employee* tutor)
{
	if (Employee::isTeachingStaff)
	{
		std::cout << " mo¿esz poprowadziæ kursu";
	}
	else {
		std::cout << "nie mo¿esz prowadziæ kursu";
	}
}

void Course::addStudent(Student* student)
{
	list.add(student);
	student->signIn(this);
}
void Course::printAllCourses()
{
	std::cout;
	std::cout;
}
void Student::signIn(Course* course)
{
	list.add(course);
	course->addStudent(this);
}

Course* CourseList::get(int index)
{
	return courses[index];
}

int CourseList::getCount()
{
	return count;
}

Student* StudentList::get(int index)
{
	return students[index];
}

int StudentList::getCount()
{
	return count;
}
