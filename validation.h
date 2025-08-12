#pragma once
#include <iostream>
#include <string>
using namespace std;

class validation
{
public:
	static bool isValidName(const string& nameinput)
	{
		if (nameinput.length() < 5 || nameinput.length() > 20)
			return false;


		for (char c : nameinput) {
			if (!((c >= 'a' && c <= 'z') ||
				(c >= 'A' && c <= 'Z') ||
				c == ' '))
				return false;
		}
		return true;
	}
	//==================================================================================
	static bool isValidPassword(const string& passwordinput)
	{
		return passwordinput.length() >= 8 && passwordinput.length() <= 20;
	}
	//==================================================================================
	static bool isValidSalary(double salaryInput)
	{
		return salaryInput >= 5000;
	}
	//==================================================================================
	static bool isValidBalance(double balanceInput)
	{
		return balanceInput >= 1500;
	}
	//==================================================================================
	static bool isValidDeposit(double depositInput)
	{
		return depositInput >= 0;
	}
	//==================================================================================
	static bool isValidWithdraw(double withdrawInput, double balance)
	{
		return withdrawInput >= 0 &&
			withdrawInput <= balance &&
			(balance - withdrawInput) >= 1500;
	}
	//==================================================================================
	static bool isValidTransfer(double transferInput, double balance)
	{
		return transferInput >= 0 &&
			transferInput <= balance &&
			(balance - transferInput) >= 1500;
	}
	//==================================================================================

};

