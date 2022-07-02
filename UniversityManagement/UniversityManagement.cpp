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

//
//void course::settutor(employee* tutor)
//{
//	if (tutor->isteachingstaff())
//	{
//		this->tutor = tutor;
//		std::cout << " mo¿esz poprowadziæ kursu";
//	}
//	else {
//		std::cout << "nie mo¿esz prowadziæ kursu";
//	}
//}

void Course::addStudent(Student* student)
{
	list.add(student);
	student->signIn(this);
}

void Student::signIn(Course* course)
{
	list.add(course);
	course->addStudent(this);
}
void CourseList::add(Course* object)
{
	if (count == maxStaffSize)
	{
		Course** newStaff = resizeArray(); // tworzymy nowa 2-krotnie szersza tablice
		copyElements(newStaff); // kopiujemy elementy pomiedzy tablicami
		delete[] courses; // usuwamy stara tablice		
		courses = newStaff; // zapamietujemy nowa tablice - podobnie do //staff = nullptr;
	}
	courses[count] = object;
	++count;
}

Course* CourseList::get(int index)
{
	return courses[index];
}

int CourseList::getCount()
{
	return count;
}


Course** CourseList::resizeArray()
{
	maxStaffSize *= 2;
	Course** newArray = new Course * [maxStaffSize];
	return newArray;
}


void CourseList::copyElements(Course** target)
{
	for (int i = 0; i < count; i++)
	{
		target[i] = courses[i];
	}
}

CourseList::CourseList()
{
	courses = new Course * [maxStaffSize];
}

CourseList::~CourseList()
{
	delete[] courses;
}

////////////StudentList
void StudentList::add(Student* object)
{
	if (count == maxStaffSize)
	{
		Student** newStaff = resizeArray(); // tworzymy nowa 2-krotnie szersza tablice
		copyElements(newStaff); // kopiujemy elementy pomiedzy tablicami
		delete[] students; // usuwamy stara tablice		
		students = newStaff; // zapamietujemy nowa tablice - podobnie do //staff = nullptr;
	}
	students[count] = object;
	++count;
}

Student* StudentList::get(int index)
{
	return students[index];
}

int StudentList::getCount()
{
	return count;
}


Student** StudentList::resizeArray()
{
	maxStaffSize *= 2;
	Student** newArray = new Student * [maxStaffSize];
	return newArray;
}

//przepisujemy wszystkie elementy (count)
//miedzy staff->target
void StudentList::copyElements(Student** target)
{
	for (int i = 0; i < count; i++)
	{
		target[i] = students[i];
	}
}

StudentList::StudentList()
{
	students = new Student * [maxStaffSize];
}

StudentList::~StudentList()
{
	delete[] students;
}
