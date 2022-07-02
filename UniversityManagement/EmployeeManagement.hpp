#pragma once
#include <string>

enum class FormOfEmployment
{
	Contract,
	ContractOfMandate,
	ContractOfEmployment
};

//abstrakcyjna klasa - nie mozna tworzyc obiektow tej klasy
class Employee
{
protected:
	std::string name;
	std::string surname;
	FormOfEmployment form;
	double salary = 0;
	int hoursPerMonth = 0;
public:
	Employee(std::string _name, std::string _surname, FormOfEmployment _form, double _salary);
	double calculateEmployerCost();
	double getEmployeeNetSalary(int hoursInMonth);
	virtual bool isTeachingStaff() = 0; //pure virtual method
	std::string getName() const;
	std::string getSurname() const;
};

std::ostream& operator<<(std::ostream& s, const Employee& e);

class Professor : public Employee
{
public:
	Professor(std::string _name, std::string _surname, FormOfEmployment _form, double _salary);
	virtual bool isTeachingStaff();
};

class Lecturer : public Employee
{
public:
	Lecturer(std::string _name, std::string _surname, FormOfEmployment _form, double _salary);
	virtual bool isTeachingStaff();
};

class Assistant : public Employee
{
public:
	Assistant(std::string _name, std::string _surname, FormOfEmployment _form, double _salary);
	virtual bool isTeachingStaff();
};

class Keeper : public Employee
{
public:
	Keeper(std::string _name, std::string _surname, FormOfEmployment _form, double _salary);
	virtual bool isTeachingStaff();
};

class Guard : public Employee
{
public:
	Guard(std::string _name, std::string _surname, FormOfEmployment _form, double _salary);
	virtual bool isTeachingStaff();
};
