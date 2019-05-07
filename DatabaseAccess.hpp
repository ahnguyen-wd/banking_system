//
//  DatabaseAccess.hpp
//  banking_system
//
//  Created by Andrew Nguyen on 5/6/19.
//  Copyright © 2019 CSUF-CPSC462. All rights reserved.
//

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
    bool checkID(string);
    //return customer that we will use to remove from file
    Customer returnCustomer(string);
private:
    string line;
    int lineCounter = 0;
};

#endif /* DatabaseAccess_hpp */
