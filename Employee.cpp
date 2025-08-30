#include "Employee.h"
#include "Client.h"
#include "DataSourceInterface.h"

Employee::Employee(int id, string name, string password, double salary)
	: Person(id, name, password), dataSource(nullptr)
{
	setSalary(salary);
}

Employee::Employee(string name, string password, double salary)
	: Person(name, password), dataSource(nullptr)
{
	setSalary(salary);
}

void Employee::setDataSource(DataSourceInterface* ds)
{
	dataSource = ds;
}

// Services
void Employee::addClient(Client& c) {
	if (!dataSource)
		throw std::runtime_error("No datasource assigned!");

	dataSource->addClient(c);
}

Client* Employee::searchClient(int clientId)
{
	if (!dataSource)
		throw std::runtime_error("No datasource assigned!");

	auto clients = dataSource->getAllClients();
	for (Client c : clients)
	{
		if (c.getId() == clientId)
			return new Client(c);
	}
	cout << "Client with ID " << clientId << " not found." << endl;
	return nullptr;
}

void Employee::listClients()
{
	if (!dataSource)
		throw std::runtime_error("No datasource assigned!");

	auto clients = dataSource->getAllClients();
	for (Client& c : clients)
	{
		c.display();
		cout << "------------------------" << endl;
	}
}

void Employee::editClient(int clientId, const string& newName, const string& newPassword, double newBalance) {
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
	for (Client& c : clients)
		dataSource->addClient(c);
	cout << "Client with ID " << clientId << " updated successfully." << endl;
}
