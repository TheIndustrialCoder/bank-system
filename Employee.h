#pragma once
#include "Person.h"

class DataSourceInterface;
class Client;

class Employee : public Person
{
private:
	// Attributes
	DataSourceInterface* dataSource;
	double salary;

public:
	// Constructor
	Employee() : Person()
	{
		salary = 0.0;
	}

	Employee(int id, string name, string password, double salary);

	Employee(string name, string password, double salary);

	// Setters
	void setSalary(const double salary)
	{
		if(Validation::validateSalary(salary))
			this->salary = salary;
		else
			this->salary = 0;
	}

	void setDataSource(DataSourceInterface* ds);

	// Getters
	double getSalary () const
	{
		return salary;
	}

	// Methods

	void display()
	{
		Person::display();
		cout << "Salary: " << salary << endl;
	}

	// Services
	void addClient(Client& client);

	Client* searchClient(int clientId);

	void listClients();

	void editClient(int clientId, const string& newName, const string& newPassword, double newBalance);
};