//
//  Customer.hpp
//  Banking System Test
//
//  Created by Andrew Nguyen on 5/7/19.
//  Copyright © 2019 CSUF-CPSC462. All rights reserved.
//

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
