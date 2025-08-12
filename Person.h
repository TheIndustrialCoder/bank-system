#pragma once
#include <iostream>
#include <string>
using namespace std;
#include"validation.h"


class Person
{
protected:
	int id;
	string name;
	string password;

public:
	Person() {
		id = 0;
	}

	Person(int id, string name, string password) {
		this->id = id;
		setName(name);
		setPassword(password);
	}
	//====================================================================================
	void setName(const string& name) {
		if (validation::isValidName(name)) {
			this->name = name;
		}
		else {
			cout << "Invalid name. Name must be between 5 and 20 characters and can only contain letters and spaces." << endl;
		}
	}

	void inputName() {
		string name;
		while (true) {
			cout << "Enter your name: ";
			getline(cin, name);

			if (validation::isValidName(name)) {
				this->name = name;
				break;
			}
			else {
				cout << "Invalid name! Name must be between 5 and 20 characters and contain only letters and spaces.\n";
			}
		}
	}

	string getName() const {
		return name;
	}
	//====================================================================================
	void setPassword(const string& password) {
		if (validation::isValidPassword(password)) {
			this->password = password;
		}
		else {
			cout << "Invalid password. Password must be between 8 and 20 characters." << endl;
		}
	}

	void inputPassword() {
		string password;
		while (true) {
			cout << "Enter your password: ";
			getline(cin, password);
			if (validation::isValidPassword(password)) {
				this->password = password;
				break;
			}
			else {
				cout << "Invalid password! Password must be between 8 and 20 characters.\n";
			}
		}
	}

	string getPassword() const {
		return password;
	}


};

