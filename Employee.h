#pragma once
#include "Person.h"
using namespace std;

class Employee : public Person
{
private:
	// Attributes
	double salary;

public:
	// Constructor
	Employee() : Person()
	{
		salary = 0.0;
	}

	Employee(int id, string name, string password, double salary) : Person(id, name, password)
	{
		setSalary(salary);
	}

	Employee(string name, string password, double salary) : Person(name, password)
	{
		setSalary(salary);
	}

	// Setters
	void setSalary(double salary)
	{
		if(Validation::validateSalary(salary))
			this->salary = salary;
		else
			this->salary = 0;
	}

	// Getters
	double getSalary()
	{
		return salary;
	}

	// Methods

	void display()
	{
		Person::display();
		cout << "Salary: " << salary << endl;
	}
};