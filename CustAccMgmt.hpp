#ifndef CustAccMgmt_hpp
#define CustAccMgmt_hpp

#include <stdio.h>
#include <string>
#include "Customer.hpp"
#include "DatabaseAccess.hpp"

using namespace std;

class CustAccMgmt
{
public:
	void createCustomer();
	void removeCustomer(string);
	void get_information(string);
	void deposit(string);
	void withdraw(string);
private:
	DatabaseAccess accessor;
	Customer customer;
};

#endif /* CustAccMgmt_hpp */
