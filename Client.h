#pragma once
#include <string>
#include <iostream>
#include "Person.h"
#include "Validation.h"
using namespace std;

class Client : public Person
{
private:
	// Attributes
	static int idCounter;
	double balance;

public:
	// Constructor
	Client(string name, string password, double balance) : Person(name, password)
	{
		Validation::validateBalance(balance);
		this->balance = balance;
		this->id = 0 + idCounter++;
	}

	// Setters
	void setBalance(double balance)
	{
		Validation::validateBalance(balance);
		this->balance = balance;
	}

	// Getters
	double getBalance()
	{
		return balance;
	}

	// Methods
	void deposit(double amount)
	{
		balance += amount;
	}

	void withdraw(double amount)
	{
		Validation::validateWithdraw(balance, amount);
		balance -= amount;
	}

	void transferTo(Client& recipient, double amount)
	{
		Validation::validateWithdraw(balance, amount);
		balance -= amount;
		recipient.deposit(amount);
	}

	void checkBalance() {
		cout << "Current balance: " << balance << endl;
	}

	string display()
	{
		return "Client Info: ID: " + to_string(id) + ", Name: " + getName() + ", Balance: " + to_string(balance);
	}
};

