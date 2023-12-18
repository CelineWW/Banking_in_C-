//
//  Checking.h
//  PA13_banking
//
//  Created by Celine Wang on 11/28/23.
//

#ifndef Checking_h
#define Checking_h

#include <iostream>
#include "Account.h"
using namespace std;

// add member:
// service charge: $5
// checking charge: $0.1
// bounced check charge: $15

// member constructor:
// interest rate: 2.5%

// virtual member function:
// withdraw condition: check < balance, bounced check charge
// checking charge: $0.1 per check, but 1st time free

class Checking : public Account {
private:
    int check_count;
    int check_bounced;
public:
    // Checking constructor
    Checking(int customer_id = 0, string name = "", string title = "", string ssn = "", double balance = 0, double interest_rate = 0.025, double divident = 0, int check_count_param = 0, int check_bounced_param = 0) :
        Account(customer_id, name, title, ssn, balance, interest_rate, divident){
            check_count = check_count_param; check_bounced = check_bounced_param;
    }

    int get_check_count() const { return check_count; }
    int get_check_bounced() const { return check_bounced; }
    int set_check_count(int written_check_param){
        check_count += written_check_param;
        return check_count;
    }
    
    int set_check_bounced(int bounced_check_param){
        check_bounced += bounced_check_param;
        return check_bounced;
    }
    
    // override Account get_description() function
    string get_description() const override{
        return  "\n>Checking Status" + Account::get_description() + "\nChecks written: " + to_string(check_count) + "\nCheck Bounced: " + to_string(check_bounced) ;
    };
    
    // deduct_service_fee function definition
    void deduct_service_fee(){
        balance -= 5.00;
        cout << "---------------------------------------------------------------------------\n\n";
        cout << "\nChecking ccount opened.\n";
        cout << "Service fee charged: $5.00\n"  << "Current balance: " << balance << endl;
    }
    
    // Modified display_activity_menu() function
    static void display_activity_menu() {
        cout << endl << endl;
        cout << "---------------------------------------------------------------------------\n\n";
        cout << "                           *** Checking ***                                \n";
        Account::display_activity_menu();
    }
    
    // override Account withdraw() function
    void withdraw(double withdraw_amount) override{
        if (balance >= withdraw_amount){
            cout << "\nDeducted successfully from Checking!";
            balance -= withdraw_amount;
            cout << "\nChecking balance: $" << balance << endl;
        }
        else
            cout << "\nAn error occured: low balance.\n";
    }

    // override Account deposit() function
    void deposit(double deposit_amount) override {
        balance += deposit_amount;
        cout << "Added successfully to Checking!\n";
        cout << "Checking balance: $" << balance << endl;
    }
    
    // write_check inline function definition
    void write_check(double check_amount) {
        if (balance < check_amount){
            balance -= 15.00;   // bounced check fee $15
            set_check_bounced(1);
            cout << "\nAn error occured: check bounced (not enough funds).\n";
            cout << "\nA fee of $15 has been charged for bounced check.\n";
        }
        else if (get_check_count() == 0 && balance >= check_amount){
            balance -= check_amount;
        }

        else if (get_check_count() > 0 && balance >= check_amount + 0.10){
            balance -= (check_amount + 0.10);    // check fee $0.1
            cout << "\nA fee of $0.10 has been charged for writing a check.\n";
        }
        set_check_count(1);
        cout << "Deducted successfully from Checking!\n";
        cout << "You have written " << get_check_count() << "check(s).\n";
        cout << "Checking balance: $" << balance << endl;
    }
};
#endif /* Checking_h */
