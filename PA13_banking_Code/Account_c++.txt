//
//  Account.cpp
//  PA13_banking
//
//  Created by Celine Wang on 11/28/23.
//
#include "Account.h"
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

Account::Account(int customer_id_param, string name_param, string title_param, string ssn_param, double balance, double interest_rate_param, double divident){
    customer_id = customer_id_param;
    set_name(name_param);
    set_title(title_param);
    set_ssn(ssn_param);
    set_interest_rate(interest_rate_param);
};


void Account::set_name(string name_param){
    name = name_param;
}
void Account::set_interest_rate(double interest_rate_param){
    interest_rate = interest_rate_param;
}

void Account::set_title(string title_param){
    title = title_param;
}

void Account::set_ssn(string ssn_param){
    ssn = ssn_param;
}

string Account::get_description() const {
    return "\n>ID: " + to_string(customer_id) + "\n>Name: " + name +
    + "\n>Title: " + title + "\n>SSN: " + ssn + "\nBalance: " + to_string(balance) + "\nDivident: " + to_string(divident);
}

void Account::display_menu() {
    cout << endl << endl;
    cout << "---------------------------------------------------------------------------\n\n";
    cout << "                          Bank Services Menu                               \n";
    cout << "                          ------------------                               \n";
    cout << "                          1) Checking Account                              \n";
    cout << "                          2) Savings Account                               \n";
    cout << "                          3) End of Services                               \n\n";
}

void Account::display_activity_menu() {
    cout << "                          Account Activities                               \n";
    cout << "                          ==================                               \n";
    cout << "                          a) --- Deposit ---                               \n";
    cout << "                          b) --- Withdraw---                               \n";
    cout << "                          c) --- Transfer---                               \n";
    cout << "                          d) --- Balance ---                               \n";
    cout << "                          e)  Personal Check                               \n";
    cout << "                          f) --- Interest---                               \n";
    cout << "                          g) ----  Done ----                               \n\n";
}

void Account::deposit(double deposit_amount){
    balance += deposit_amount;
    
}

double Account::calculate_interest() {
    double interest = balance * interest_rate;
    return interest;
}

void Account::withdraw(double withdraw_amount) {
    if (balance >= withdraw_amount){
        balance -= withdraw_amount;
    }
    else
        throw invalid_argument("An error occured: low balance.\n");
}
