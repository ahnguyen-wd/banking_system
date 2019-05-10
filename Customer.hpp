#ifndef Customer_hpp
#define Customer_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Customer {
public:
	Customer();
	~Customer();
	string name;
	string address;
	string SSN;
	string customerID;
	int birthday;
	int funds;
};

#endif /* Customer_hpp */