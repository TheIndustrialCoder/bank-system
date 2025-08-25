#pragma once
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include <vector>


class DataSourceInterface
{
public:
	virtual void addClient(Client client) = 0;
	virtual void addEmployee(Employee employee) = 0;
	virtual void addAdmin(Admin admin) = 0;
	virtual vector<Client> getAllClients() = 0;
	virtual vector<Employee> getAllEmployees() = 0;
	virtual vector<Admin> getAllAdmins() = 0;
	virtual void RemoveAllClients() = 0;
	virtual void RemoveAllEmployees() = 0;
	virtual void RemoveAllAdmins() = 0;
};

