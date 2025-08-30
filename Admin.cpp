#include "Admin.h"
#include "Client.h"
#include "DataSourceInterface.h"

Admin::Admin(int id, string name, string password, double salary)
	: Employee(id, name, password, salary), dataSource(nullptr) {
}

Admin::Admin(string name, string password, double salary)
	: Employee(name, password, salary), dataSource(nullptr) {}

void Admin::setDataSource(DataSourceInterface* ds) {
	dataSource = ds;
}

void Admin::addClient(Client& c) {
	if (!dataSource)
		throw std::runtime_error("No datasource assigned!");

	dataSource->addClient(c);
}

Client* Admin::searchClient(int clientId) {
	if (!dataSource)
		throw std::runtime_error("No datasource assigned!");

	auto clients = dataSource->getAllClients();
	for (Client c : clients) {
		if (c.getId() == clientId)
			return new Client(c);
	}
	cout << "Client with ID " << clientId << " not found." << endl;
	return nullptr;
}

void Admin::listClients() {
	if (!dataSource)
		throw std::runtime_error("No datasource assigned!");

	auto clients = dataSource->getAllClients();
	for (Client& c : clients) {
		c.display();
		cout << "------------------------" << endl;
	}
}

void Admin::editClient(int clientId, const string& newName, const string& newPassword, double newBalance) {
	if (!dataSource)
		throw std::runtime_error("No datasource assigned!");

	auto clients = dataSource->getAllClients();
	bool found = false;
	for (auto& c : clients) {
		if (c.getId() == clientId) {
			found = true;
			c.setName(newName);
			c.setPassword(newPassword);
			c.setBalance(newBalance);
			break;
		}
	}
	if (!found) {
		cout << "Client with ID " << clientId << " not found." << endl;
		return;
	}
	dataSource->removeClientsFile();
	for (Client& c : clients) {
		dataSource->addClient(c);
	}
	cout << "Client with ID " << clientId << " updated successfully." << endl;
}

void Admin::addEmployee(Employee& emp) {
	if (!dataSource)
		throw std::runtime_error("No datasource assigned!");

	dataSource->addEmployee(emp);
}

Employee* Admin::searchEmployee(int empId) {
	if (!dataSource)
		throw std::runtime_error("No datasource assigned!");

	auto employees = dataSource->getAllEmployees();
	for (Employee e : employees) {
		if (e.getId() == empId)
			return new Employee(e);
	}
	cout << "Employee with ID " << empId << " not found." << endl;
	return nullptr;
}

void Admin::listEmployees() {
	if (!dataSource)
		throw std::runtime_error("No datasource assigned!");

	auto employees = dataSource->getAllEmployees();
	for (Employee& e : employees) {
		e.display();
		cout << "------------------------" << endl;
	}
}

void Admin::editEmployee(int empId, const string& newName, const string& newPassword, double newSalary) {
	if (!dataSource)
		throw std::runtime_error("No datasource assigned!");
	auto employees = dataSource->getAllEmployees();
	bool found = false;
	for (auto& e : employees) {
		if (e.getId() == empId) {
			found = true;
			e.setName(newName);
			e.setPassword(newPassword);
			e.setSalary(newSalary);
			break;
		}
	}
	if (!found) {
		cout << "Employee with ID " << empId << " not found." << endl;
		return;
	}
	dataSource->removeEmployeesFile();
	for (Employee& e : employees) {
		dataSource->addEmployee(e);
	}
	cout << "Employee with ID " << empId << " updated successfully." << endl;
}
