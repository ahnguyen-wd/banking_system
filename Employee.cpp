#include "Employee.hpp"

Employee::Employee() : employeeID(0), name("null"), SSN(0), address("null"), salary(0), birthday(000), managersName("null") {};

Employee::Employee(int ID, string name, int SSN, string address, int salary, int birthday, string managersName) { cout << "Employee " << name << " created.\n"; }

Employee::~Employee() {}