#pragma once
#include "Employee.h"
using namespace std;

class Admin : public Employee
{
private:
	// Attributes
	static int idCounter;
	double salary;

public:
	// Constructor
	Admin() : Employee() {}

	Admin(int id, string name, string password, double salary) : Employee(id, name, password, salary) {}
};

