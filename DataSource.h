#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
#include "Employee.h"
#include "Admin.h"
#include "Client.h"
using namespace std;

class DataSource
{
public:

	virtual void addClient(Client client) = 0;
	virtual void addEmployee(Employee employee) = 0;
	virtual void addAdmin(Admin admin) = 0;

	virtual vector<Client> getAllClients() = 0;
	virtual vector<Employee> getAllEmployees() = 0;
	virtual vector<Admin> getAllAdmins() = 0;
	
	virtual void removeAllClients() = 0;
	virtual void removeAllEmployees() = 0;
	virtual void removeAllAdmins() = 0;

};

