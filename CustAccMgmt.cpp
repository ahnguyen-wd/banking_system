//
//  CustAccMgmt.cpp
//  banking_system
//
//  Created by Andrew Nguyen on 5/6/19.
//  Copyright © 2019 CSUF-CPSC462. All rights reserved.
//

#include "CustAccMgmt.hpp"
#include <string>

using namespace std;

void CustAccMgmt::createCustomer() {
    Customer newCustomer;
    bool created = false;
    bool correctID = false;
    cin.ignore();
    
    while(created == false) {
        
        cout << "Enter New Customer ID (4 Digits and a letter i.e. 1738H): ";
        
        getline(cin, newCustomer.customerID);
        cout << "\nYou entered the following for customer ID: " << newCustomer.customerID << endl;
        
        correctID = accessor.checkID(newCustomer.customerID);
        
        if(correctID == true) {
            cout << "Enter Customer Name: ";
            cin.ignore();
            getline(cin, newCustomer.name);
            cout << "Enter Customer Address: ";
            getline(cin, newCustomer.address);
            cout << "Enter Customer birthday: ";
            cin >> newCustomer.birthday;
            cout << "Enter Customer SSN: ";
            cin.ignore();
            getline(cin, newCustomer.SSN);
            cout << "Enter initial deposit: ";
            cin >> newCustomer.funds;
            
            accessor.writeCustomer(newCustomer.customerID, newCustomer.name, newCustomer.address, newCustomer.birthday, newCustomer.SSN, newCustomer.funds);
            
            cout << "New Customer " << newCustomer.name << " with ID " << newCustomer.customerID << " has been created and added to database.";
            
            created = true;
        }
    }
};

void CustAccMgmt::removeCustomer(string ID) {
    customer = accessor.returnCustomer(ID);
    accessor.removeCustomer(ID);
    
    cout << customer.name << " with ID " << customer.customerID << " has been removed from the database.\n";
}

void CustAccMgmt::get_information(string ID) {
    customer = accessor.returnCustomer(ID);
    
    cout << "~~ Customer Information ~~";
    cout << "Customer ID: " << customer.customerID << endl;
    cout << "Customer Name: " << customer.name << endl;
    cout << "Customer Address: " << customer.address << endl;
    cout << "Customer Birthday: " << customer.birthday << endl;
    cout << "Customer SSN: " << customer.SSN << endl;
    cout << "Customer Funds: " << customer.funds << endl;
}


void CustAccMgmt::deposit(string ID) {
	customer = accessor.returnCustomer(ID);
	double depositfund = 0;

	cout << "Enter amount";
	cin >> depositfund;

	customer.funds += depositfund;

	accessor.writeCustomer(ID, customer.name, customer.address, customer.birthday, customer.SSN, customer.funds);
}
void CustAccMgmt::withdraw(string ID) {
	custoner = accessor.returnCustomer(ID);
	double wfund = 0;

	cout << "Enter amount";
	cin >> wfund;

	customer.funds -= wfund;

	accessor.writeCustomer(ID, customer.name, customer.address, customer.birthday, customer.SSN, customer.funds);
}

