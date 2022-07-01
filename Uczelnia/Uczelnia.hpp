#pragma once
#include<string>
#include<iostream>
enum class FormOfEmployment {
	Contract,
	ContractOfMandate,
	ContractOfEmployment
};

class Employee
{
protected:
	FormOfEmployment form;
	std::string firstName;
	std::string secondName;
	double salary;
public:
	Employee(){};
	Employee(FormOfEmployment);
	double getEmployeeNetSalary();
	virtual bool isTeachingStaf()=0;
	virtual void printEployee()=0;
	virtual void printEmployeeNetSalary()=0;
	virtual ~Employee(){};

};

class Professor:public Employee
{
	
public:
	Professor(){};
	Professor(std::string firstName, std::string secondName, FormOfEmployment form, double salary);
	bool isTeachingStaf();
	void printEployee();
	std::string position="Profesor";
	void printEmployeeNetSalary();
	
	~Professor(){};
};
class Lecturer:public Employee
{
public:
	Lecturer(){};
	Lecturer(std::string firstName, std::string secondName, FormOfEmployment form, double salary);
	bool isTeachingStaf();
	void printEployee();
	std::string position = "Adiunkt";
	void printEmployeeNetSalary();
	
	~Lecturer(){};
};
class Assistant:public Employee
{
public:
	Assistant(){};
	Assistant(std::string firstName, std::string secondName, FormOfEmployment form, double salary);
	virtual bool isTeachingStaf();
	virtual void printEployee();
	std::string position = "Asystent";
	void printEmployeeNetSalary();
	
	~Assistant(){};

};
class Keeper:public Employee
{
public:
	Keeper() {};
	Keeper(std::string firstName, std::string secondName, FormOfEmployment form, double salary);
	bool isTeachingStaf();
	void printEployee();
	std::string position = "Konserwator";
	void printEmployeeNetSalary();
	
	~Keeper(){};
};
class Guard :public Employee
{
public:
	Guard(){};
	Guard(std::string firstName, std::string secondName, FormOfEmployment form, double salary);
	bool isTeachingStaf();
	void printEployee();
	std::string position = "Ochroniarz";
	void printEmployeeNetSalary();
	
	~Guard(){};
};

class University
{
	Employee* employees[100]; 
	
public:
	void printAllStaffNetIncomes();
	void add(Employee* e);
	void printAllStaff();
	void printTeachingStaff();
	double salaryOfContract();
	double calculateEmployerCost();
};