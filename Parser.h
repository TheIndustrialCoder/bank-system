#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;




class Parser
{
public:


	static vector<string> split(string line) {
		vector<string>data;
		int start = 0;
		int end = line.find(',');
		while (end != string::npos) {
			data.push_back(line.substr(start, end - start));
			start = end + 1;
			end = line.find(',', start);
		}
		data.push_back(line.substr(start));
		return data;
	}


	static Client parseToClient(string line) {
		vector<string>data = split(line);

		if (data.size() < 4) {
			throw invalid_argument("Invalid client data format.");
		}
		Client client;
		client.setId(stoi(data[0]));
		client.setName(data[1]);
		client.setPassword(data[2]);
		client.setBalance(stod(data[3]));
		return client;
	}

	static Employee parseToEmployee(string line) {
		vector<string>data = split(line);

		if (data.size() < 4) {
			throw invalid_argument("Invalid employee data format.");
		}
		Employee employee;
		employee.setId(stoi(data[0]));
		employee.setName(data[1]);
		employee.setPassword(data[2]);
		employee.setSalary(stod(data[3]));
		return employee;
	}

	static Admin parseToAdmin(string line) {
		vector<string>data = split(line);
		if (data.size() < 4) {
			throw invalid_argument("Invalid admin data format.");
		}
		Admin admin;
		admin.setId(stoi(data[0]));
		admin.setName(data[1]);
		admin.setPassword(data[2]);
		admin.setSalary(stod(data[3]));
		return admin;
	}

};

