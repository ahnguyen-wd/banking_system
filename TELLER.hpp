//
//  Teller.hpp
//  Banking System
//
//  Created by Andrew Nguyen on 4/8/19.
//  Copyright © 2019 CSUF-CPSC462. All rights reserved.
//

#ifndef Teller_hpp
#define Teller_hpp

#include <stdio.h>
#include <iostream>
#include "Employee.hpp"

#include "CustAccMgmt.hpp"

using namespace std;

class Teller : public Employee, public CustAccMgmt
{
public:
    Teller();
    ~Teller();
    int quota;
    int accessCode;
};

#endif /* Teller_hpp */
