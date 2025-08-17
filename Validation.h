#pragma once
#include <string>
#include <iostream>
#include <exception>

using namespace std;

class NameException : public exception {
public:
	const char* what() const throw()
	{
		return "Invalid name, please enter a name between 5 and 20 characters, containing only letters and spaces";
	}
};

class PasswordException : public exception {
public:
	const char* what() const throw()
	{
		return "Invalid password, please enter a password between 8 and 20 characters";
	}
};

class BalanceException : public exception {
public:
	const char* what() const throw()
	{
		return "Client balance must be at least 1500";
	}
};

class AmountException : public exception {
	public:
	const char* what() const throw()
	{
		return "Amount must be greater than 0";
	}
};

class WithdrawException : public exception {
public:
	const char* what() const throw()
	{
		return "Withdrawal amount exceeds available balance or amount is invalid";
	}
};

class SalaryException : public exception {
public:
	const char* what() const throw()
	{
		return "Salary must be at least 5000";
	}
};


class Validation
{
public:
	// Static Methods
	static void validateName(string name) {
		if (name.length() < 5 || name.length() > 20) {
			throw NameException();
		}
		for (char c : name) {
			if (!isalpha(c) && c != ' ') {
				throw NameException();
			}
		}
	}
	
	static void validatePassword(string password) {
		if (password.length() < 8 || password.length() > 20) {
			throw PasswordException();
		}
	}

	static void validateBalance(double balance) {
		if (balance < 1500) {
			throw BalanceException();
		}
	}

	static void validateAmount(double amount) {
		if (amount <= 0) {
			throw AmountException();
		}
	}

	static void validateWithdraw(double balance, double amount) {
		validateAmount(amount);

		if (amount >= balance) {
			throw WithdrawException();
		}
	}

	static void validateSalary(double salary) {
		if (salary < 5000) {
			throw SalaryException();
		}
	}
};

