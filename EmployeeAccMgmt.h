#pragma once
#include "Employee.hpp"
#include "DatabaseAccess.hpp"
using namespace std;

class EmployeeAccMgmt
{
public:
	void addEmployee();
private:
	DatabaseAccess access;
	Employee empl;
};