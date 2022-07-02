#include "EmployeeManagement.hpp"
#include <string>
#include <iostream>

Employee::Employee(std::string _name, std::string _surname, FormOfEmployment _form, double _salary) : name(_name), surname(_surname), form(_form), salary(_salary)
{
}

double Employee::calculateEmployerCost()
{
	double employerCost = 0;

	switch (form)
	{
	case FormOfEmployment::Contract:
		employerCost = (salary * hoursPerMonth) + 0, 23 * (salary * hoursPerMonth);
		break;
	case FormOfEmployment::ContractOfEmployment:
		employerCost = salary;
		break;
	case FormOfEmployment::ContractOfMandate:
		employerCost = salary + 0, 15 * salary;
	}
	return employerCost;
}

double Employee::getEmployeeNetSalary(int hoursInMonth)
{
	if (form == FormOfEmployment::Contract)
	{
		salary *= hoursInMonth;
	}

	double pensionInsurance = 0.15;
	double healthInsurance = 0.12;
	double netSalary = salary - salary * (pensionInsurance + healthInsurance);

	return netSalary;
}

Professor::Professor(std::string _name, std::string _surname, FormOfEmployment _form, double _salary) : Employee(_name, _surname, _form, _salary)
{
}

bool Professor::isTeachingStaff()
{
	return true;
}

Lecturer::Lecturer(std::string _name, std::string _surname, FormOfEmployment _form, double _salary) : Employee(_name, _surname, _form, _salary)
{
}


bool Lecturer::isTeachingStaff()
{
	return true;
}

Assistant::Assistant(std::string _name, std::string _surname, FormOfEmployment _form, double _salary) : Employee(_name, _surname, _form, _salary)
{
}

bool Assistant::isTeachingStaff()
{
	return true;
}

Keeper::Keeper(std::string _name, std::string _surname, FormOfEmployment _form, double _salary) : Employee(_name, _surname, _form, _salary)
{
}

bool Keeper::isTeachingStaff()
{
	return false;
}

Guard::Guard(std::string _name, std::string _surname, FormOfEmployment _form, double _salary) : Employee(_name, _surname, _form, _salary)
{
}

bool Guard::isTeachingStaff()
{
	return false;
}

std::string Employee::getName() const
{
	return name;
}

std::string Employee::getSurname() const
{
	return surname;
}

std::ostream& operator<<(std::ostream& s, const Employee& e)
{
	std::string xx = " - ";
	s << e.getName() << xx << e.getSurname();
	return s;
}
