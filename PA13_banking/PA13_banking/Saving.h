//
//  Saving.h
//  PA13_banking
//
//  Created by Celine Wang on 11/28/23.
//

#ifndef Saving_h
#define Saving_h

#include <iostream>
#include "Account.h"

using namespace std;

// add member:
// transfer charge: $1

// member constructor:
// interest rate: 3.75%

// virtual member function:
// withdraw condition: blance >= $25 and enough funds
// transfer charge: $1 per transfer, but 1st time free

class Savings : public Account {
private:
    int transfer_count;
    
public:
    // Savings constructor
    Savings(int customer_id = 0, string name = "", string title = "", string ssn = "", double balance = 0, double interest_rate = 0.0375, double divident = 0, int transfer_count_param = 0) :
        Account(customer_id, name, title, ssn, balance, interest_rate, divident){
        transfer_count = transfer_count_param;
    }
    int get_transfer_count() const { return transfer_count; }
    int set_transfer_count(int added_transfer_param){
        transfer_count += added_transfer_param;
        return transfer_count;
    }
    
    // override Account get_description() function
    string get_description() const override {
        return  "\n>Savings Status" + Account::get_description() + "\nTransfer count: " + to_string(transfer_count);
    };
    
    // Modified display_activity_menu() function
    static void display_activity_menu() {
        cout << endl << endl;
        cout << "---------------------------------------------------------------------------\n\n";
        cout << "                            *** Savings ***                                \n";
        Account::display_activity_menu();
    }
    
    // override Account deposit() function
    void deposit(double deposit_amount) override {
        balance += deposit_amount;
        cout << "Added successfully to Savings!\n";\
        cout << "Savings Balance: $" << balance << endl;
    }

    // override Account withdraw() function
    void withdraw(double withdraw_amount) override {
        if (balance > 25.00 && balance >= withdraw_amount){
            balance -= withdraw_amount;
            cout << "Deducted successfully from Savings!\n";
            cout << "Savings balance: $" << balance << endl;
        }
        else if (balance > 25.00 && balance < withdraw_amount){
            cout << "An error occured: low balance.\n";
        }
        else
            cout<< "An error occured: the account is inactive.\n";
    }

};

#endif /* Saving_h */
