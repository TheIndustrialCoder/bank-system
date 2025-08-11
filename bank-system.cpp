#include <iostream>
#include <string>
#include "Validation.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Person.h"
using namespace std;

//Intializing static members
int Client::idCounter = 1;
int Employee::idCounter = 1;
int Admin::idCounter = 1;

int main()
{
    
	while (true) {
		try {
			string name{ "Mahmoud Amr" }, password{"123456789"};
			double balance{5000};
			/*getline(cin, name);
			getline(cin, password);
			cin >> salary;
			cin.ignore();*/
			Client client(name, password, balance);
			cout << client.display() << endl;
			client.checkBalance();
		
			client.deposit(500);
			cout << "After deposit: " << client.display() << endl;
		
			client.withdraw(100);
			cout << "After withdrawal: " << client.display() << endl;
		
			Client recipient("John Doe", "password123", 1500);
			client.transferTo(recipient, 200);
			cout << "After transfer: " << client.display() << endl;
			cout << "Recipient's balance: " << recipient.display() << endl;
			break;
		
		} catch (const exception& e) {
			cout << e.what() << endl;
		}
	}
	
	cout << "===========================================================" << endl;

	while (true) {
		try {
			string name{ "Mahmoud Amr" }, password{ "123456789" };
			double salary{ 6000 };
			/*getline(cin, name);
			getline(cin, password);
			cin >> salary;
			cin.ignore();*/
			Admin admin(name, password, salary);
			cout << admin.display() << endl;
			Employee employee(name, password, salary);
			cout << employee.display() << endl;
			employee.setSalary(7000);
			cout << "After salary update: " << employee.display() << endl;
			admin.setSalary(8000);
			cout << "After admin salary update: " << admin.display() << endl;
			employee.setName("Ahmed Ali");
			cout << "After name update: " << employee.display() << endl;
			admin.setName("Sara Smith");
			cout << "After admin name update: " << admin.display() << endl;
			Admin admin2("Alice Johnson", "adminpass", 9000);
			Employee employee2("Bob Brown", "employeepass", 5000);
			cout << admin.display() << endl;
			cout << employee.display() << endl;
			cout << admin2.display() << endl;
			cout << employee2.display() << endl;
			break;

		}
		catch (const exception& e) {
			cout << e.what() << endl;
		}
	}
   
}


