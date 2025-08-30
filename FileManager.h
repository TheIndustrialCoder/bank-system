#pragma once
#include "DataSourceInterface.h"
#include "FileHelper.h"

class FileManager : public DataSourceInterface
{
public:
	void addClient(Client& client) override
	{
		if (client.getId() == 0) {
			int newId = FileHelper::generateId("ClientsIdCount.txt");
			client.setId(newId);
		}
		FileHelper::saveClient(client);
	}

	void addEmployee(Employee& employee) override
	{
		if (employee.getId() == 0) {
			int newId = FileHelper::generateId("EmployeeIdCount.txt");
			employee.setId(newId);
		}
		FileHelper::saveEmployee(employee);
	}

	void addAdmin(Admin& admin) override
	{
		if (admin.getId() == 0) {
			int newId = FileHelper::generateId("AdminIdCount.txt");
			admin.setId(newId);
		}
		FileHelper::saveAdmin(admin);
	}

	vector<Client> getAllClients() override
	{
		return FileHelper::getClients();
	}

	vector<Employee> getAllEmployees() override
	{
		return FileHelper::getEmployees();
	}

	vector<Admin> getAllAdmins() override
	{
		return FileHelper::getAdmins();
	}

	void removeAllClients() override
	{
		FileHelper::clearFile("Clients.txt");
		FileHelper::clearFile("ClientsIdCount.txt");

	}

	void removeAllEmployees() override
	{
		FileHelper::clearFile("Employees.txt");
		FileHelper::clearFile("EmployeeIdCount.txt");
	}

	void removeAllAdmins() override
	{
		FileHelper::clearFile("Admins.txt");
		FileHelper::clearFile("AdminIdCount.txt");
	}

	void removeClientsFile() override
	{
		FileHelper::clearFile("Clients.txt");
	}

	void removeEmployeesFile() override
	{
		FileHelper::clearFile("Employees.txt");
	}

	void removeAdminsFile() override
	{
		FileHelper::clearFile("Admins.txt");
	}
};

