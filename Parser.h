#pragma once
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include <vector>
using namespace std;

class Parser
{
private:
	static char delimiter;
public:
	static vector<string> split(string line) {
		vector<string> data;
		int start = 0;
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == delimiter) {
				data.push_back(line.substr(start, i - start));
				start = i + 1;
			}
		}
		data.push_back(line.substr(start));
		return data;
	}

	static Client parseToClient(string line) {
		vector<string> data = split(line);
		int id = stoi(data[0]);
		string name = data[1];
		string password = data[2];
		double balance = stod(data[3]);
		Client client(id, name, password, balance);
		return client;
	}

	static Employee parseToEmployee(string line) {
		auto data = split(line);
		int id = stoi(data[0]);
		string name = data[1];
		string password = data[2];
		double salary = stod(data[3]);
		Employee employee(id, name, password, salary);
		return employee;
	}

	static Admin parseToAdmin(string line) {
		auto data = split(line);
		int id = stoi(data[0]);
		string name = data[1];
		string password = data[2];
		double salary = stod(data[3]);
		Admin admin(id, name, password, salary);
		return admin;
	}
};