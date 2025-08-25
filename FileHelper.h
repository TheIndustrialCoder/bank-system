#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include "Admin.h"
#include "Client.h"
#include "Parser.h"

using namespace std;

class FileHelper
{
public:
	static void saveLast(string fileName, int id) {
		ofstream file(fileName, ios::trunc);
		if (!file.is_open()) {
			throw runtime_error("Could not open file: " + fileName);
		}
		file << id;
		file.close();	
	}

	static int getLast(string fileName) {
		ifstream file(fileName);
		if (!file.is_open()) {
			throw runtime_error("Could not open file: " + fileName);
		}
		int id;
		file >> id;
		file.close();
		return id;
	}


	static void saveClient(Client c) {
		string fileName = "Clients.txt";
		int id = getLast("ClientsLastIdUsed.txt") + 1;
		fstream file(fileName, ios::out | ios::app);
		if (!file.is_open()) {
			throw runtime_error("Could not open file: " + fileName);
		}

		file << id << "," << c.getName() << "," << c.getPassword() << "," << c.getBalance() << endl;
		saveLast("ClientsLastIdUsed.txt", id);
		file.close();
	}



	static void saveEmployee(Employee e) {
		string fileName = "Employees.txt";
		fstream file(fileName, ios::out | ios::app);
		if (!file.is_open()) {
			throw runtime_error("Could not open file: " + fileName);
		}

		file << e.getId() << "," << e.getName() << "," << e.getPassword() << "," << e.getSalary() << endl;
		file.close();
	}


	static void saveAdmin(Admin a) {
		string fileName = "Employees.txt";
		fstream file(fileName, ios::out | ios::app);
		if (!file.is_open()) {
			throw runtime_error("Could not open file: " + fileName);
		}

		file << a.getId() << "," << a.getName() << "," << a.getPassword() << "," << a.getSalary() << endl;
		file.close();
	}

	static vector<Client> getClients() {
		vector<Client> dataClients;
		ifstream file("Clients.txt");
		string line;
		while (getline(file, line)) {
			dataClients.push_back(Parser::parseToClient(line));
		}
		file.close();
		return dataClients;
	}

	static void clearFile(string fileName, string lastIdFile) {
		ofstream dataFile(fileName, ios::trunc), idFile(lastIdFile, ios::trunc);
		if (dataFile.is_open()) {
			dataFile.close();
		}
		else {
			cerr << "Error opening file: " << fileName << endl;
		}

		if (idFile.is_open()) {
			idFile << 0;
			idFile.close();
		}
		else {
			cerr << "Error opening file: " << fileName << endl;
		}
	}
};

