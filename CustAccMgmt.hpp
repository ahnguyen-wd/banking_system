//
//  CustAccMgmt.hpp
//  banking_system
//
//  Created by Andrew Nguyen on 5/6/19.
//  Copyright © 2019 CSUF-CPSC462. All rights reserved.
//

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
    void deposit();
private:
    DatabaseAccess accessor;
    Customer customer;
};

#endif /* CustAccMgmt_hpp */
