#include <iostream>
#include "Employee.h"
using namespace std;

int main()
{
	string name = "Ali", password = "123";
	double balance = 500;
	/*cout << "Enter your name: ";
	getline(cin, name);
	cout << "Enter your password: ";
	getline(cin, password);
	cout << "Enter your initial balance: ";
	cin >> balance;*/
	Employee client(name, password, balance);
	client.getSalary();

}
