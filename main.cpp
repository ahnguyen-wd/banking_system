//
//  main.cpp
//  Banking System
//
//  Created by Andrew Nguyen on 4/8/19.
//

#include "SystemAdmin.cpp"
#include "Manager.cpp"
#include "Teller.cpp"
#include "Auditor.cpp"
#include "Accountant.cpp"
#include <iostream>

using namespace std;

void tellerMenu();
void managerMenu();
void systemAdminMenu();
void auditorMenu();
void accountantMenu();

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int ch = 0;
    
    while(ch != 6) {
        cout << "MAIN MENU" << endl;
        cout << "1. TELLER MENU" << endl;
        cout << "2. MANAGER MENU" << endl;
        cout << "3. SYSTEM ADMIN MENU" << endl;
        cout << "4. AUDITOR MENU" << endl;
        cout << "5. ACCOUNTANT MENU" << endl;
        cout << "6. QUIT" << endl;
        cin >> ch;
        
        if(ch > 0 && ch < 6) {
            switch(ch) {
                case 1:
                    tellerMenu();
                    break;
                case 2:
                    managerMenu();
                    break;
                case 3:
                    systemAdminMenu();
                    break;
                case 4:
                    auditorMenu();
                    break;
                case 5:
                    accountantMenu();
                    break;
            }
        }
        else if(ch == 6) {
            cout << "\nExiting Banking System...." << endl;
        }
        else {
            cout << "\nYou have entered an invalid option, please try again." << endl;
            cout << "--------------------------------\n" << endl;
        }
    }
    
    return 0;
}

void tellerMenu() {
    Teller teller;
    cout << "This is the teller menu";
}

void managerMenu() {
    Manager manager;
    cout << "This is the manager menu";
}

void systemAdminMenu() {
    SystemAdmin sysad;
    cout << "This is the sysad menu";
}

void auditorMenu() {
    Auditor auditor;
    cout << "This is the auditor menu";
}

void accountantMenu() {
    Accountant accountant;
    cout << "This is the accountant menu";
}
