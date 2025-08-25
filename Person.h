#pragma once
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
	Person() {
		id = 0;
		name = "";
		password = "";
	}

	Person(int id, string name, string password) {
		setId(id);
		setName(name);
		setPassword(password);
	}

	Person(string name, string password) {
		setName(name);
		setPassword(password);
	}

	// Setters
	void setId(int id) {
		this->id = id;
	}

	void setName(string name) {
		if(Validation::validateName(name))
			this->name = name;
	}

	void setPassword(string password) {
		if(Validation::validatePassword(password))
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
	void display() {
		cout << "ID : " << id << endl;
		cout << "Name : " << name << endl;
		cout << "Password : " << password << endl;
	}

};