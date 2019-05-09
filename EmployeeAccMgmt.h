#pragma once
#ifndef EmployeeAccMgmt_h
#define EmployeeAccMgmt_h

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

#endif // !EmployeeAccMgmt_h