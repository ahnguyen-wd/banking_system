#pragma once
#ifndef EmployeeAccMgmt_h
#define EmployeeAccMgmt_h

#include "Employee.hpp"
#include "DatabaseAccess.hpp"
#include "Teller.hpp"
using namespace std;

class EmployeeAccMgmt
{
public:
	void addEmployee();
	void EmployeeAccMgmt::setQuota();
private:
	DatabaseAccess access;
	Employee empl;
};

#endif // !EmployeeAccMgmt_h