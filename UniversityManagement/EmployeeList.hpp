#pragma once
#include "EmployeeManagement.hpp"

class EmployeeList
{
	Employee** staff;
	Employee** resizeArray();
	void copyElements(Employee** target);
	int count = 0;
	int maxStaffSize = 1;
public:
	EmployeeList();
	virtual ~EmployeeList();
	//EmployeeList(const EmployeeList& obj); //copy constructor
	//EmployeeList& operator=(const EmployeeList& obj); //copy assignment operator
	void add(Employee* object);
	Employee* get(int index);
	int getCount();
};


