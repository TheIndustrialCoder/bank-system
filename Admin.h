#pragma once
#include <string>
#include <iostream>
#include "Person.h"
#include "Employee.h"
#include "Validation.h"
using namespace std;

class Admin : public Person
{
private:
	// Attributes
	static int idCounter;
	double salary;

public:
	// Constructor
	Admin(string name, string password, double salary) : Person(name, password)
	{
		Validation::validateSalary(salary);
		this->salary = salary;
		this->id = 0 + idCounter++;
	}

	// Setters
	void setSalary(double salary)
	{
		Validation::validateSalary(salary);
		this->salary = salary;
	}

	// Getters
	double getSalary()
	{
		return salary;
	}

	// Methods

	string display()
	{
		return "Admin Info : ID " + to_string(id) + ", Name: " + getName() + ", Salary: " + to_string(salary);
	}
};

