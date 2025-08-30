#pragma once
#include "Employee.h"

class Admin : public Employee
{
private:
	// Attributes
	DataSourceInterface* dataSource;

public:
	// Constructor
	Admin() : Employee() {}

	Admin(int id, string name, string password, double salary);

	Admin(string name, string password, double salary);

	// Setters

	void setDataSource(DataSourceInterface* ds);

	// Services
	void addClient(Client& client);

	Client* searchClient(int clientId);

	void listClients();

	void editClient(int clientId, const string& newName, const string& newPassword, double newBalance);

	void addEmployee(Employee& emp);

	Employee* searchEmployee(int empId);

	void listEmployees();

	void editEmployee(int empId, const string& newName, const string& newPassword, double newSalary);
};