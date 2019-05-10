#ifndef DatabaseAccess_hpp
#define DatabaseAccess_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "Customer.hpp"
using namespace std;

class DatabaseAccess
{
public:
	DatabaseAccess();
	~DatabaseAccess();
	void writeCustomer(string, string, string, int, string, int);
	void removeCustomer(string);
	void writeEmployee(int, string, int, string, int, int, string);
	bool isEmployeeInfoDuplicated(string);
	bool checkID(string);
	void updateQuota(string, int);
	int getQuota(string);
	//return customer that we will use to remove from file
	Customer returnCustomer(string);
private:
	string line;
	int lineCounter = 0;
};

#endif /* DatabaseAccess_hpp */