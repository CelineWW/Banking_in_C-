//
//  main.cpp
//  PA13_banking
//
//  Created by Celine Wang on 11/28/23.
//

#include <iostream>
#include <iomanip>
#include "Account.h"
#include "Saving.h"
#include "Checking.h"

using namespace std;

void display_intro();
void display_title();
void savings_to_checking(Checking&, Savings&, double);
void checking_to_savings(Checking&, Savings&, double);
void process_checking(Checking&, Savings&,int);
void process_savings(Checking&, Savings&);

int main() {
    cout << fixed << setprecision(2);
    
    char program_choice = 'y';
    while (tolower(program_choice == 'y')){
        display_intro();
        display_title();
        
        // create account
        string name_param;
        cout << "Enter your full name: ";
        getline(cin, name_param);
        
        string title_param;
        cout << "Enter your title(Mr., Mrs., Ms., Dr.) : ";
        cin >> title_param;
        
        string ssn_param;
        cout << "Enter your SSN : ";
        cin >> ssn_param;
        
        Account account(123, name_param, title_param, ssn_param);
        Checking checking(account.get_id(), account.get_name(), account.get_title(), account.get_ssn(), account.balance, 0.025, 0, 0, 0);
        Savings savings(account.get_id(), account.get_name(), account.get_title(), account.get_ssn(), account.balance, 0.0375, 0, 0);

        cout << account.get_description() << endl << endl;
        cout << checking.get_description() << endl << endl;
        cout << savings.get_description() << endl << endl;
        
        // select account according to customer id
        int selected_id;
        cout << "Enter your account ID:";
        cin >> selected_id;
        if (selected_id == account.get_id()) {
            cout << "\n                How are you today? " << account.get_title() << " " << account.get_name();
            cout << "\n                Press <Enter> for our banking services ...\n";
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        
        // choose from service menu
        char menu_choice = 'n';
        int menu_item = 0;
        int deduct_count = 0;
        while (tolower(menu_choice) == 'n'){
            Account::display_menu();
            cout << "Enter your choice: ";
            cin >> menu_item;
            cin.ignore();
            switch (menu_item){
                // Checking activites
                case 1:{
                    cout << "Open/manage the Checking account (y/n)?";
                    cin >> menu_choice;
                    if (menu_choice == 'n') {
                        continue;
                    }
                    else if (menu_choice == 'y'){
                        cout << "\n---------------------------------------------------------------------------\n";
                        cout << "Press <Enter> key to continue ...\n";
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        process_checking(checking, savings, deduct_count);
                        ++deduct_count;
                    }
                    break;}
                // Savings activities
                case 2:{
                    cout << "Open/manage the Savings account (y/n)?";
                    cin >> menu_choice;
                    if (menu_choice == 'n') {
                        continue;
                    }
                    else if (menu_choice == 'y'){
                        cout << "\n---------------------------------------------------------------------------\n";
                        cout << "Press <Enter> key to continue ...\n";
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        process_savings(checking, savings);
                    }
                    break;}
                // End of service
                case 3:{
                    cout << "End of service?";
                    cin >> menu_choice;
                    if (menu_choice == 'n') {
                        continue;
                    }
                    else if (menu_choice == 'y'){
                        cout << "\n---------------------------------------------------------------------------\n";
                    }
                    break;}
                default:{
                    cout << "Invalid menu item! Try again.\n";
                    menu_choice = 'n';
                    break;}
            }
            cout << "\n---------------------------------------------------------------------------\n";
            cout << "Leave the program (y/n)? ";
            cin >> menu_choice;
        }
        // Thanks to customer
        cout << "Thanks for visiting our bank, " << account.get_title() << " " << account.get_name() << endl;
        cout << "We hope you are happy with us.\n";
        cout << "Missing anything? back with our back services (y/n)? ";
        cin >> program_choice;
        
    }
    // End of program
    cout << "So long! It's nice to serve you.\n";
    cout << "Developer: Celine Wang\n";
    cout << "Press <Enter> key to end the program.\n";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    return 0;
}
    
// display_intro() function definition
void display_intro() {
    cout << "/* \n"
    << "Class: CISC 192 -- C++ Programming -- Fall 2023\n"
    << "Class Assignent: Programming Project #13 - Banking Project\n"
    << "Author: Celine Wang \n"
    << "CSID: 12345678\n"
    << "Date: Nov 29, 2023\n*/\n\n";
}

// display_title() function definition
void display_title() {
    cout << endl
    << "                * === * === * === * === * === * === * === * === * === * === * === * === *    \n"
    << "                * === * === *    Welcome to CELINE WANG's Enterprise Bank   * === * === *    \n"
    << "                * === * === * === * === * === * === * === * === * === * === * === * === *    \n\n"
    << "Please register with your personal information:\n";
}

// savings_to_checking() function definition
void savings_to_checking(Checking& checking_account, Savings& savings_account, double transfer_amount){
    if (savings_account.get_transfer_count() == 0 && savings_account.balance >= transfer_amount){
        savings_account.balance -= transfer_amount;
        checking_account.balance += transfer_amount;
        cout << "\nDeducted successfully from Savings!";
        cout << "\nAdded successfully to Checking!";
        cout << "\nChecking Balance: $" << checking_account.balance;
        cout << "\nSavings Balance: $" << savings_account.balance << endl;
    }
    else if (savings_account.get_transfer_count() > 0 && savings_account.balance >= (transfer_amount + 1.00)){
        savings_account.balance -= (transfer_amount + 1.00);
        checking_account.balance += transfer_amount;
        cout << "\nDeducted successfully from Savings!";
        cout << "\nCharging a $1 fee for funds transfer.";
        cout << "\nAdded successfully to Checking!";
        cout << "\nChecking Balance: $" << checking_account.balance;
        cout << "\nSavings Balance: $" << savings_account.balance << endl;
    }
    else if ((savings_account.get_transfer_count() == 0 && savings_account.balance < transfer_amount) ||
             (savings_account.get_transfer_count() > 0 && savings_account.balance < (transfer_amount + 1.00))){
        cout << "\nAn error occured: low balance\n";
    }
    savings_account.set_transfer_count(1);
}

// checking_to_savings function definition
void checking_to_savings(Checking& checking_account, Savings& savings_account, double transfer_amount){
    if (checking_account.balance >= transfer_amount){
        savings_account.balance += transfer_amount;
        checking_account.balance -= transfer_amount;
        cout << "\nDeducted successfully from Checking!";
        cout << "\nAdded successfully to Savings!";
        cout << "\nChecking Balance: $" << checking_account.balance;
        cout << "\nSavings Balance: $" << savings_account.balance << endl;
    }
    else {
        cout << "\nAn error occured: low balance\n";
    }
}

// process_checking function definition
void process_checking(Checking& checking, Savings& savings, int deduct_count_param){
    if (deduct_count_param == 0){
        checking.deduct_service_fee();
        ++deduct_count_param;
    }
    Checking::display_activity_menu();
    char checking_choice = 'z';
    int interest_count = 0;
    while (checking_choice != 'g'){
        cout << "\nEnter your checking activity choice: ";
        cin >> checking_choice;
        cin.ignore();
        switch (checking_choice){
            // deposit
            case 'a':{
                double deposit_param;
                cout << "*** Deposit ***\n";
                cout << "Enter amount to deposit? ";
                cin >> deposit_param;
                checking.deposit(deposit_param);
                break;}
            // withdraw
            case 'b':{
                double withdraw_param;
                cout << "*** Withdraw ***\n";
                cout << "Enter amount to withdraw? ";
                cin >> withdraw_param;
                checking.withdraw(withdraw_param);
                break;}
            // transfer
            case 'c':{
                int transfer_choice;
                cout << "*** Transfer ***\n";
                cout << "1) from Checking to Savings\n";
                cout << "2) from Savings to Checking\n";
                cout << "Enter your choice: ";
                cin >> transfer_choice;
                if (transfer_choice == 1) {
                    double transfer_param;
                    cout << "Enter amount to transfer? ";
                    cin >> transfer_param;
                    checking_to_savings(checking,savings,transfer_param);
                }
                else if (transfer_choice == 2) {
                    cout<< "Cannot process! Invalid order.\n"
                    <<"Please go to your Savings account to transfer to Checking account.\n";
                }
                break;}
            // balance
            case 'd':{
                cout << "*** Balance ***\n";
                cout << "Checking Balance: " << checking.balance << endl;
                break;}
            // personal check
            case 'e':{
                int check_param;
                cout << "*** Personal Check ***\n";
                cout << "Enter amount to check out? ";
                cin >> check_param;
                checking.write_check(check_param);
                break;}
            // interest
            case 'f': {
                cout << "*** Interest ***\n";
                if (interest_count == 0){
                    checking.divident += checking.calculate_interest();
                    checking.balance += checking.divident;
                    cout << "Checking divident: $" << checking.divident << endl;
                    cout << "Checking balance: $" << checking.balance << endl;
                    ++interest_count;
                }
                else if (interest_count > 0){
                    cout << "An error accurred: zero interest\n";
                    cout << "Checking balance: $" << checking.balance << endl;
                }
                break;}
            // done
            case 'g':{
                cout << "End of Checking account Option.\n";
                cout << "Number of checks signed: " << checking.get_check_count() << endl;
                cout << "Number of checks bounced: " << checking.get_check_bounced() << endl;
                cout << "Checking divident: " << checking.divident << endl;
                cout << "Checking balanced: " << checking.balance << endl;
                break;}
            default:{
                cout << "Invalid Checking activity! Try again.\n";
                break;}
        }
        cout << "Press <Enter> key to continue ...\n";
        cin.ignore();
    }
    return;
}

// process_savings function definition
void process_savings(Checking& checking, Savings& savings){
    Savings::display_activity_menu();
    char savings_choice = 'z';
    int interest_count = 0;
    while (savings_choice !='g'){
        cout << "\nEnter your savings activity choice: ";
        cin >> savings_choice;
        cin.ignore();
        switch (savings_choice){
            // deposit
            case 'a':{
                double deposit_param;
                cout << "*** Deposit ***\n";
                cout << "Enter amount to deposit? ";
                cin >> deposit_param;
                savings.deposit(deposit_param);
                break;}
            // withdraw
            case 'b':{
                double withdraw_param;
                cout << "*** Withdraw ***\n";
                cout << "Enter amount to withdraw? ";
                cin >> withdraw_param;
                savings.withdraw(withdraw_param);
                break;}
            // transfer
            case 'c':{
                int transfer_choice;
                cout << "*** Transfer ***\n";
                cout << "1) from Checking to Savings\n";
                cout << "2) from Savings to Checking\n";
                cout << "Enter your choice: ";
                cin >> transfer_choice;
                if (transfer_choice == 2) {
                    double transfer_param;
                    cout << "Enter amount to transfer? ";
                    cin >> transfer_param;
                    savings_to_checking(checking,savings,transfer_param);
                }
                else if (transfer_choice == 1) {
                    cout << "Cannot process! Invalid order.\n"
                        <<"Please go to your Checking account to transfer to Savings account.\n";
                }
                break;}
            // balance
            case 'd':{
                cout << "*** Balance ***\n";
                cout << "Savings Balance: " << savings.balance << endl;
                break;}
            // personal check
            case 'e':{
                cout << "*** Personal Check ***\n";
                cout << "You are not allowed to write check from the Savings account.";
                break;}
            // interest
            case 'f': {
                cout << "*** Interest ***\n";
                if (interest_count == 0){
                    savings.divident += savings.calculate_interest();
                    savings.balance += savings.divident;
                    cout << "Savings interest amount: $" << savings.divident << endl;
                    cout << "Savings current balance: $" << savings.balance << endl;
                    ++interest_count;
                }
                else if (interest_count > 0){
                    cout << "An error accurred: zero interest\n";
                    cout << "Savings current balance: $" << savings.balance << endl;
                }
                break;}
            // done
            case 'g':{
                cout << "End of Savings account Option.\n";
                cout << "Number of transfer to checking: " << savings.get_transfer_count() << endl;
                cout << "Savings divident: " << savings.divident << endl;
                cout << "Savings balance: " << savings.balance << endl;
                break;}
            default:{
                cout << "Invalid Savings activity! Try again.\n";
                break;}
        }
        cout << "Press <Enter> key to continue ...\n";
        cin.ignore();
    }
    return;
}
