#include<iostream>
#include<string>
#include "EmployeeAccMgmt.h"

void EmployeeAccMgmt::addEmployee()
{
	Employee newEmployee;
	cout << "Enter employee ID: ";
	cin >> newEmployee.employeeID;
	cout << "Enter employee name: ";
	cin.ignore();
	getline(cin, newEmployee.name);
	cout << "Enter employee SSN: ";
	cin >> newEmployee.SSN;
	cout << "Enter employee address: ";
	cin.ignore();
	getline(cin, newEmployee.address);
	cout << "Enter employee salary: ";
	cin >> newEmployee.salary;
	cout << "Enter employee birthday: ";
	cin >> newEmployee.birthday;
	cout << "Enter employee's manager's name: ";
	cin.ignore();
	getline(cin, newEmployee.managersName);
	access.writeEmployee(newEmployee.employeeID, newEmployee.name, newEmployee.SSN, newEmployee.address, newEmployee.salary, newEmployee.birthday, newEmployee.managersName);

}