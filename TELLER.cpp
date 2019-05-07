//
//  Teller.cpp
//  Banking System
//
//  Created by Andrew Nguyen on 4/8/19.
//  Copyright © 2019 CSUF-CPSC462. All rights reserved.
//

#include "Teller.hpp"
#include <iostream>

Teller::Teller() {
    //New hire quota requirement
    accessCode = 5539232;
    quota = 15;
}
Teller::~Teller() {}


