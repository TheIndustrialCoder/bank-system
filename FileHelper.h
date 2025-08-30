#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Parser.h"

using namespace std;

class FileHelper
{
public:

	static int generateId(const string& fileName)
	{
		int id = getLast(fileName) + 1;
		saveLast(fileName, id);
		return id;
	}

	static void saveLast(const string& fileName, int id)
	{
		ofstream file(fileName, ios::trunc);
		if (!file.is_open())
			throw runtime_error("Could not open file: " + fileName);
		file << id;
		file.close();
	}

	static int getLast(const string& fileName)
	{
		ifstream file(fileName);
		if (!file.is_open()) {
			file.close();
			ofstream createFile(fileName);
			createFile << 0;
			createFile.close();
			return 0;
		}
		int id = 0;	
		if (!(file >> id))
			return 0; // starts from 0 if file is empty or invalid
		file.close();
		return id;
	}

	static void saveClient(const Client& c)
	{
		string fileName = "Clients.txt";
		ofstream file(fileName, ios::app);
		if (!file.is_open())
			throw runtime_error("Could not open file: " + fileName);

		file << c.getId() << ","
			 << c.getName() << "," 
			 << c.getPassword() << "," 
			 << c.getBalance() << "\n";

		file.close();
	}

	static void saveEmployee(const Employee& e)
	{
		string fileName = "Employees.txt";
		ofstream file(fileName, ios::app);
		if (!file.is_open())
			throw runtime_error("Could not open file: " + fileName);

		file << e.getId() << ","
			 << e.getName() << ","
			 << e.getPassword() << ","
			 << e.getSalary() << "\n";

		file.close();
	}

	static void saveAdmin(const Admin& a)
	{
		string fileName = "Admins.txt";
		ofstream file(fileName, ios::app);
		if (!file.is_open())
		{
			throw runtime_error("Could not open file: " + fileName);
		}

		file << a.getId() << ","
			 << a.getName() << ","
			 << a.getPassword() << ","
			 << a.getSalary() << "\n";

		file.close();
	}

	static vector<Client> getClients()
	{
		vector<Client> dataClients;
		ifstream file("Clients.txt");
		string line;
		while (getline(file, line))
		{
			dataClients.push_back(Parser::parseToClient(line));
		}
		file.close();
		return dataClients;
	}

	static vector<Employee> getEmployees()
	{
		vector<Employee> dataEmployees;
		ifstream file("Employees.txt");
		string line;
		while (getline(file, line))
		{
			dataEmployees.push_back(Parser::parseToEmployee(line));
		}
		file.close();
		return dataEmployees;
	}

	static vector<Admin> getAdmins()
	{
		vector<Admin> dataAdmins;
		ifstream file("Admins.txt");
		string line;
		while (getline(file, line))
		{
			dataAdmins.push_back(Parser::parseToAdmin(line));
		}
		file.close();
		return dataAdmins;
	}

	static void clearFile(const string& fileName)
	{
		ofstream dataFile(fileName, ios::trunc);
		if (dataFile.is_open())
		{
			dataFile.close();
		}
		else
		{
			cerr << "Error opening file: " << fileName << endl;
		}
	}

	//static void clearFile(const string& fileName, const string& lastIdFile)
	//{
	//	ofstream dataFile(fileName, ios::trunc);
	//	if (dataFile.is_open())
	//	{
	//		dataFile.close();
	//	}
	//	else
	//	{
	//		cerr << "Error opening file: " << fileName << endl;
	//	}

	//	ofstream idFile(lastIdFile, ios::trunc);
	//	if (idFile.is_open())
	//	{
	//		idFile << 0;
	//		idFile.close();
	//	}
	//	else
	//	{
	//		cerr << "Error opening file: " << lastIdFile << endl;
	//	}
	//}
};
