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
	if (access.isEmployeeInfoDuplicated(to_string(newEmployee.SSN)) 
		|| access.isEmployeeInfoDuplicated(to_string(newEmployee.employeeID)))
	{
		cout << "Info duplicated. Employee already exists." << endl;
	}
	else
	{
		access.writeEmployee(newEmployee.employeeID, newEmployee.name, newEmployee.SSN, newEmployee.address,
			newEmployee.salary, newEmployee.birthday, newEmployee.managersName);
		cout << "Employee successfully added" << endl;
	}
}

void EmployeeAccMgmt::setQuota()
{
	string ID;
	int quota;
	cout << "Enter Employee ID: ";
	cin >> ID;
	cin.ignore();
	cout << "Enter Quota amount: ";
	cin >> quota;
	access.updateQuota(ID, quota);
}

void EmployeeAccMgmt::getQuota()
{
	string ID;
	int quota;
	cout << "Enter Employee ID: ";
	cin >> ID;
	cin.ignore();
	quota = access.getQuota(ID);
	cout << "Quota: " << quota << endl;
}