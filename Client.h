#pragma once
#include "Person.h"
using namespace std;

class Client : public Person
{
private:
	// Attributes
	double balance;

public:
	// Constructor
	Client() : Person()
	{
		balance = 0.0;
	}

	Client(int id, string name, string password, double balance) : Person(id, name, password)
	{
		setBalance(balance);
	}

	Client(string name, string password, double balance) : Person(name, password)
	{
		setBalance(balance);
	}

	// Setters
	void setBalance(double balance)
	{
		if (Validation::validateBalance(balance))
			this->balance = balance;
		else
			this->balance = 0;
	}

	// Getters
	double getBalance()
	{
		return balance;
	}

	// Methods
	void deposit(double amount)
	{
		if(Validation::validateAmount(amount))
			balance += amount;
	}

	void withdraw(double amount)
	{
		if(Validation::validateWithdraw(balance, amount))
			balance -= amount;
	}

	void transferTo(Client& recipient, double amount)
	{
		withdraw(amount);
		recipient.deposit(amount);
	}

	void checkBalance() {
		cout << "Current balance: " << balance << endl;
	}

	void display() {
		Person::display();
		cout << "Balance: " << balance << endl;
	}
};