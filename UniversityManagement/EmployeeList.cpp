#include "EmployeeList.hpp"

void EmployeeList::add(Employee* object)
{
	if (count == maxStaffSize)
	{
		Employee** newStaff = resizeArray(); // tworzymy nowa 2-krotnie szersza tablice
		copyElements(newStaff); // kopiujemy elementy pomiedzy tablicami
		delete[] staff; // usuwamy stara tablice		
		staff = newStaff; // zapamietujemy nowa tablice - podobnie do //staff = nullptr;
	}
	staff[count] = object;
	++count;
}

Employee* EmployeeList::get(int index)
{
	return staff[index];
}

int EmployeeList::getCount()
{
	return count;
}

//tworzymy nowa tablice
//aktualizujemy maxsize
//zwracamy ja
Employee** EmployeeList::resizeArray()
{
	maxStaffSize *= 2;
	Employee** newArray = new Employee * [maxStaffSize];
	return newArray;
}

//przepisujemy wszystkie elementy (count)
//miedzy staff->target
void EmployeeList::copyElements(Employee** target)
{
	for (int i = 0; i < count; i++)
	{
		target[i] = staff[i];
	}
}

EmployeeList::EmployeeList()
{
	staff = new Employee * [maxStaffSize];
}

EmployeeList::~EmployeeList()
{
	delete[] staff;
}