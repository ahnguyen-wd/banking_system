//
//  DatabaseAccess.cpp
//  banking_system
//
//  Created by Andrew Nguyen on 5/6/19.
//  Copyright © 2019 CSUF-CPSC462. All rights reserved.
//

#include "DatabaseAccess.hpp"

using namespace std;

DatabaseAccess::DatabaseAccess() {
}

void DatabaseAccess::writeCustomer(string ID, string name, string address, int birthday, string SSN, int funds) {

	ofstream customerFile;
	customerFile.open("customers.txt", ofstream::out | ofstream::app);
	customerFile << ID << "\n";
	customerFile << name << "\n";
	customerFile << address << "\n";
	customerFile << birthday << "\n";
	customerFile << SSN << "\n";
	customerFile << funds << "\n";

	customerFile.close();
}

void DatabaseAccess::removeCustomer(string ID) {
	ifstream in("customers.txt");
	string str;
	vector<string> vect;
	bool found = false;
	int removeRangeStart = 0;
	lineCounter = 0;

	//Will push content of text file into vector and find line where ID is
	while (getline(in, str)) {
		lineCounter++;
		if (str.find(ID) != string::npos) {
			removeRangeStart = lineCounter;
			found = true;
		}
		vect.push_back(str);
	}

	in.close();

	//Create a temp file which will replace the original after writing to it
	ofstream customerTemp("temp.txt");

	removeRangeStart--;
	int removeRangeEnd = removeRangeStart + 6;

	//Erase the customer with the ID given
	vect.erase(vect.begin() + removeRangeStart, vect.begin() + removeRangeEnd);

	//Write customer into temp text file
	for (int i = 0; i < vect.size(); i++) {
		customerTemp << vect[i] << "\n";
	}

	customerTemp.close();

	remove("customers.txt");
	rename("temp.txt", "customers.txt");
}

Customer DatabaseAccess::returnCustomer(string ID) {
	Customer customer;

	ifstream in("customers.txt");
	int customerDataCnt = 6;
	bool found = false;
	lineCounter = 0;

	while (getline(in, line)) {
		lineCounter++;
		if (line.find(ID) != string::npos) {
			found = true;
		}
		if (found == true && customerDataCnt != 0) {
			customerDataCnt--;
			if (customerDataCnt == 5) {
				cout << line << endl;
				customer.customerID = line;
			}
			else if (customerDataCnt == 4) {
				customer.name = line;
			}
			else if (customerDataCnt == 3) {
				customer.address = line;
			}
			else if (customerDataCnt == 2) {
				customer.birthday = stoi(line);
			}
			else if (customerDataCnt == 1) {
				customer.SSN = line;
			}
			else if (customerDataCnt == 0) {
				customer.funds = stoi(line);
			}
		}
	}

	return customer;
}

Teller DatabaseAccess::returnTeller(string ID) {
	Teller employee;

	ifstream in("employees.txt");
	int employeeDataCnt = 6;
	bool found = false;
	lineCounter = 0;

	while (getline(in, line)) {
		lineCounter++;
		if (line.find(ID) != string::npos) {
			found = true;
		}
		if (found == true && employeeDataCnt != 0) {
			employeeDataCnt--;
			if (employeeDataCnt == 7) {
				cout << line << endl;
				employee.employeeID = stoi(line);
			}
			else if (employeeDataCnt == 6) {
				employee.name = line;
			}
			else if (employeeDataCnt == 5) {
				employee.SSN = stoi(line);
			}
			else if (employeeDataCnt == 4) {
				employee.address = line;
			}
			else if (employeeDataCnt == 3) {
				employee.salary = stoi(line);
			}
			else if (employeeDataCnt == 2) {
				employee.birthday = stoi(line);
			}
			else if (employeeDataCnt == 1) {
				employee.managersName = line;
			}
			else if (employeeDataCnt == 0) {
				employee.quota = stoi(line);
			}
		}
	}

	return employee;
}

void DatabaseAccess::updateQuota(string ID, int quota)
{
	ifstream employeeFile;
	ofstream newFile;
	string line;
	bool found;
	employeeFile.open("employees.txt", ios::app);
	newFile.open("newEmployees.txt", ios::app);
	while (employeeFile >> line)
	{
		if (line == ID)
		{
			for (int i = 0; i < 7; i++)
			{
				line += "\n";
				newFile << line;
			}
			newFile << "\n" << quota;
		}
	}
	remove("employees.txt");
	rename("newEmployees.txt", "employees.txt");

}


void DatabaseAccess::writeEmployee(int ID, string name, int SSN, string address, int salary, int birthday, string managerName)
{
	ofstream employeeFile;
	employeeFile.open("employees.txt", ios::app);
	employeeFile << ID << endl;
	employeeFile << name << endl;
	employeeFile << SSN << endl;
	employeeFile << address << endl;
	employeeFile << salary << endl;
	employeeFile << birthday << endl;
	employeeFile << managerName << endl;
	employeeFile.close();
}

bool DatabaseAccess::isEmployeeInfoDuplicated(string info)
{
	ifstream in("employees.txt");
	string str;
	while (getline(in, str))
	{
		if (str.find(info) != string::npos)
			return true;
	}
	return false;
}

bool DatabaseAccess::checkID(string ID) {
	//Simple check to see if ID is correct length
	if (ID.length() > 5) {
		cerr << "The length of the ID is incorrect. Please try again.\n";
		cout << "Length is " << ID.length() << endl << endl;
		return false;
	}
	//Check if the ID is in correct format
	else {
		bool singleLetter = false;
		bool fourDigit = false;
		int digitCount = 0;

		//Check first four for digits
		for (int i = 0; i < ID.length() - 1; i++) {
			if (!isdigit(ID.at(i))) {
				cerr << "There cannot be a letter in the first four characters. Please try again.\n";
				return false;
			}
			if (isdigit(ID[i])) { digitCount++; }
		}

		if (digitCount == 4) { fourDigit = true; }
		else {
			cerr << "There must be at least 4 digits before a letter. Please try again.\n";
			cout << "Digit count it " << digitCount << endl << endl;;
			return false;
		}

		//Check last character for letter
		if (!isalpha(ID[4])) {
			cerr << "The last character must be a letter. Please try again.\n";
			return false;
		}
		else {
			singleLetter = true;
		}
	}

	//Check customers file to see if the ID is already taken
	ifstream in("customers.txt");
	string str;
	bool notFound = true;

	while (getline(in, str)) {
		if (str.find(ID) != string::npos) {
			notFound = false;
		}
	}

	in.close();

	if (notFound == false) {
		cerr << "The ID is already being used. Please try again.\n";
	}

	return notFound;
}

DatabaseAccess::~DatabaseAccess() {}
