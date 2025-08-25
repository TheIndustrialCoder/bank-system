#pragma once
#include <string>
#include <iostream>

using namespace std;

class Validation
{
public:
	// Static Methods
	static bool validateName(string name) {
		if (name.length() < 5 || name.length() > 20) {
			cout << "Name must be between 5 and 20 characters and contain only letters and spaces." << endl;
			return false;
		}
		for (char c : name) {
			if (!isalpha(c) && c != ' ') {
				cout << "Name must be between 5 and 20 characters and contain only letters and spaces." << endl;
				return false;
			}
		}
		return true;
	}

	static bool validatePassword(string password) {
		if (password.length() < 8 || password.length() > 20) {
			cout << "Password must be between 8 and 20 characters" << endl;
			return false;
		}
		return true;
	}

	static bool validateBalance(double balance) {
		if (balance < 1500) {
			cout << "Balance must be at least 1500" << endl;
			return false;
		}
		return true;
	}

	static bool validateAmount(double amount) {
		if (amount <= 0) {
			cout << "Amount must be greater than 0" << endl;
			return false;
		}
		return true;
	}

	static bool validateWithdraw(double balance, double amount) {
		validateAmount(amount);

		if (amount >= balance) {
			cout << "Insufficient balance" << endl;
			return false;
		}
		return true;
	}

	static bool validateSalary(double salary) {
		if (salary < 5000) {
			cout << "Salary must be at least 5000" << endl;
			return false;
		}
		return true;
	}
};