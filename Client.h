#pragma once
#include <iostream>
#include <string>
#include "validation.h"
#include "Person.h"
using namespace std;



class Client :public Person
{
private:
	double balance;
public:
	Client() {
		balance = 0.0;
	}
	Client(int id, string name, string password, double balance) : Person(id, name, password)
	{
		setBalance(balance);
	}
	//===================================================================================
	void setBalance(double balance)
	{
		if (validation::isValidBalance(balance))
		{
			this->balance = balance;
		}
		else
		{
			cout << "Invalid balance. Balance must be at least 1500." << endl;
		}
	}
	void inputBalance()
	{
		double balanceInput;
		while (true) {
			cout << "Enter your balance: ";
			cin >> balanceInput;
			if (validation::isValidBalance(balanceInput)) {
				this->balance = balanceInput;
				break;
			}
			else {
				cout << "Invalid balance! Balance must be at least 1500.\n";
			}
		}
	}

	double getBalance() const
	{
		return balance;
	}

	//===================================================================================
	void deposit(double amount)
	{
		if (validation::isValidDeposit(amount))
		{
			balance += amount;
			cout << "Deposit successful. New balance: " << balance << endl;
		}
		else
		{
			cout << "Invalid deposit amount." << endl;
		}
	}
	//===================================================================================
	void withdraw(double amount)
	{
		if (validation::isValidWithdraw(amount, balance))
		{
			balance -= amount;
			cout << "Withdrawal successful. New balance: " << balance << endl;
		}
		else
		{
			cout << "Invalid withdrawal amount." << endl;
		}
	}
	//===================================================================================
	void transfer(Client& recipient, double amount)
	{
		if (validation::isValidWithdraw(amount, balance))
		{
			balance -= amount;
			recipient.deposit(amount);
			cout << "Transfer successful. New balance: " << balance << endl;
		}
		else
		{
			cout << "Invalid transfer amount." << endl;
		}
	}
	//===================================================================================
	void checkBalance() const
	{
		cout << "Current balance: " << balance << endl;
	}
	//===================================================================================
	void displayInfo() const
	{
		cout << "Client ID: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Balance: " << balance << endl;
	}
	//===================================================================================

};

