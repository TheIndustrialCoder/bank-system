#pragma once
#include <vector>
using namespace std;

class Client;
class Employee;
class Admin;


class DataSourceInterface
{
public:
	virtual void addClient(Client& client) = 0;
	virtual void addEmployee(Employee& employee) = 0;
	virtual void addAdmin(Admin& admin) = 0;
	virtual vector<Client> getAllClients() = 0;
	virtual vector<Employee> getAllEmployees() = 0;
	virtual vector<Admin> getAllAdmins() = 0;
	virtual void removeAllClients() = 0;
	virtual void removeAllEmployees() = 0;
	virtual void removeAllAdmins() = 0;
	virtual void removeClientsFile() = 0;
	virtual void removeEmployeesFile() = 0;
	virtual void removeAdminsFile() = 0;
};