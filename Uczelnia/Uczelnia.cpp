#include"Uczelnia.hpp"


Professor::Professor(std::string firstName, std::string secondName, FormOfEmployment form,double salary)
{
	this->firstName = firstName;
	this->secondName = secondName;
	this->form = form;
	this->salary = salary;
}


bool Professor::isTeachingStaf()
{
	return true;
}


void Professor::printEployee()

{
	std::cout << firstName << '\t' << secondName << '\t' <<position <<'\t' << isTeachingStaf() << '\t' << static_cast<int>(form) << '\t' << salary << std::endl;
}

void Professor::printEmployeeNetSalary()
{
	std::cout << getEmployeeNetSalary() << " zl." <<std::endl;
}

Lecturer::Lecturer(std::string firstName, std::string secondName, FormOfEmployment form, double salary)
{
	this->firstName = firstName;
	this->secondName = secondName;
	this->form = form;
	this->salary = salary;
}

bool Lecturer::isTeachingStaf()
{
	return true;
}
void Lecturer::printEployee()
{
	std:std::cout << firstName << '\t' << secondName << '\t' << position << '\t' << isTeachingStaf() << '\t' << static_cast<int>(form) << '\t' << salary << std::endl;
}

void Lecturer::printEmployeeNetSalary()
{
	std::cout << getEmployeeNetSalary() << " zl." << std::endl;
}
Assistant::Assistant(std::string firstName, std::string secondName, FormOfEmployment form, double salary)
{
	this->firstName = firstName;
	this->secondName = secondName;
	this->form = form;
	this->salary = salary;
}

bool Assistant::isTeachingStaf()
{
	return true;
}

void Assistant::printEployee()
{
	std::cout << firstName << '\t' << secondName << '\t' << position << '\t' << isTeachingStaf() << '\t' << static_cast<int>(form) << '\t' << salary << std::endl;
}

void Assistant::printEmployeeNetSalary()
{
	std::cout << getEmployeeNetSalary() << " zl." << std::endl;
}
Guard::Guard(std::string firstName, std::string secondName, FormOfEmployment form, double salary)
{
	this->firstName = firstName;
	this->secondName = secondName;
	this->form = form;
	this->salary = salary;
}

bool Guard::isTeachingStaf()
{
	return false;
}
void Guard::printEployee()
{
	std::cout << firstName << '\t' << secondName << '\t' << position << '\t' << isTeachingStaf() << '\t' << static_cast<int>(form) << '\t' << salary << std::endl;
}

void Guard::printEmployeeNetSalary()
{
	std::cout << getEmployeeNetSalary() << " zl." << std::endl;
}
Keeper::Keeper(std::string firstName, std::string secondName, FormOfEmployment form, double salary)
{
	this->firstName = firstName;
	this->secondName = secondName;
	this->form = form;
	this->salary = salary;
}

bool Keeper::isTeachingStaf()
{
	return false;
}

void Keeper::printEployee()
{
	std::cout << firstName << '\t' << secondName << '\t' << position << '\t' << isTeachingStaf() << '\t' << static_cast<int>(form) << '\t' << salary << std::endl;
}

void Keeper::printEmployeeNetSalary()
{
	std::cout << getEmployeeNetSalary() <<" zl." << std::endl;
}

void University::printAllStaffNetIncomes()
{
	for (int i = 0; i < count; ++i)
	{
		std::cout << i + 1 << "  ";
		employees[i]->printEmployeeNetSalary();
	}
}

void University::add(Employee* e)
{
	employees[count] = e;
	++count;
}

void University::printAllStaff()
{
	for (int i = 0; i < count; ++i)
	{
		std::cout <<i+1<<" ";
		employees[i]->printEployee();
	}
	
}

void University::printTeachingStaff()
{
	for (int i = 0; i < count; ++i)
	{
		std::cout << i + 1 <<" ";
		if (employees[i]->isTeachingStaf())
		{
			employees[i]->printEployee();
		}
		
	}
}

//double University::calculateEmployerCost()
{
	 
	return 0.0;
}

//double University::salaryOfContract()
{
	
	return 0.0;
}



double Employee::getEmployeeNetSalary()
{
	int h = 168;
	double s = 0.00;
	this->salary = salary;
	if (form == FormOfEmployment::Contract)
	{
		 s = salary * h*0.88;
	}
	else
	{
		 s = salary * 0.88;
	}
	
	return s;
}
