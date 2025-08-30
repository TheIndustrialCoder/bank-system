#include <iostream>
#include "FileManager.h"
#include "Employee.h"

using namespace std;

int main()
{
	FileManager fm;
	Admin emp("Aliceeeee", "empPasssssss", 60000);
	emp.setDataSource(&fm);
	Employee emp2("Bobaaaa", "empPass22222", 55000);
	Employee emp3("Charlie", "empPass33333", 52000);
	emp.addEmployee(emp2);
	emp.addEmployee(emp3);
	emp.listEmployees();
	emp.editEmployee(emp2.getId(), "Bob Updated", "newPass22222", 58000);
}
