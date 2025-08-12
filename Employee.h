#pragma once
#include <iostream>
#include <string>
#include "validation.h"
#include "Person.h"
using namespace std;


class Employee :public Person
{
protected:
	double salary;

public:
	Employee() : Person()
	{
		salary = 0.0;
	}

	Employee(int id, string name, string password, double salary) : Person(id, name, password)
	{
		setSalary(salary);
	}

	void setSalary(double salary)
	{
		if (validation::isValidSalary(salary))
		{
			this->salary = salary;
		}
		else
		{
			cout << "Invalid salary. Salary must be at least 5000." << endl;
		}
	}

	void inputSalary()
	{
		double salaryInput;
		while (true) {
			cout << "Enter your salary: ";
			cin >> salaryInput;
			if (validation::isValidSalary(salaryInput)) {
				this->salary = salaryInput;
				break;
			}
			else {
				cout << "Invalid salary! Salary must be at least 5000.\n";
			}
		}
	}

	double getSalary() const
	{
		return salary;
	}
};

