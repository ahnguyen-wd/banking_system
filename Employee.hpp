//
//  Employee.hpp
//  banking_system
//
//  Created by Andrew Nguyen on 5/6/19.
//  Copyright © 2019 CSUF-CPSC462. All rights reserved.
//

#ifndef Employee_hpp
#define Employee_hpp
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Employee
{
public:
    Employee();
    Employee(int ID, string name, int SSN, string address, int salary, int birthday, string managersName);
    ~Employee();
    string managersName;
	int employeeID, SSN, birthday, salary;
	string address, name;
};

#endif /* Employee_hpp */
