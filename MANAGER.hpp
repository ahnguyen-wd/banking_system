#pragma once
#ifndef manager_hpp
#define manager_hpp

#include<iostream>
#include "Employee.hpp"
#include "EmployeeAccMgmt.h"
using namespace std;

class Manager : public Employee, public EmployeeAccMgmt
{
public:
	Manager();
	~Manager();
	int managerAccessCode;
};

#endif // !manager
