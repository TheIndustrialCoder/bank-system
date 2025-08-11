#pragma once
#include <string>
#include "Validation.h"

using namespace std;

class Person
{
protected:
	// Attributes
	string name, password;
	int id;

public:
	// Constructor

	Person(string name, string password) {
		Validation::validateName(name);
		Validation::validatePassword(password);
		this->name = name;
		this->password = password;
	}

	// Setters
	void setName(string name) {
		Validation::validateName(name);
		this->name = name;
	}

	void setPassword(string password) {
		Validation::validatePassword(password);
		this->password = password;
	}

	// Getters
	int getId() {
		return id;
	}

	string getName() {
		return name;
	}

	string getPassword() {
		return password;
	}

	// Methods
	virtual string display() = 0;

};

